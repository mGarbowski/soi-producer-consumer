#include <iostream>
#include <vector>
#include <algorithm>
#include "monitor.h"
#include "ThreadGroup.h"

#define SLEEP_USECONDS 100000
#define FULL "full"
#define EMPTY "empty"

unsigned int numOfProdEvenWaiting = 0;
unsigned int numOfProdOddWaiting = 0;
unsigned int numOfConsEvenWaiting = 0;
unsigned int numOfConsOddWaiting = 0;

Semaphore mutex(1);
Semaphore prodEvenSem(0);
Semaphore prodOddSem(0);
Semaphore consEvenSem(0);
Semaphore consOddSem(0);

int lastEven = 0;
int lastOdd = 1;

class FifoBuffer {
private:
    std::vector<int> buffer;
public:
    FifoBuffer() = default;

    size_t countEven() {
        return std::count_if(
                this->buffer.begin(), this->buffer.end(),
                [](int number) { return number % 2 == 0; }
        );
    }

    size_t countOdd() {
        return std::count_if(
                this->buffer.begin(), this->buffer.end(),
                [](int number) { return number % 2 != 0; }
        );
    }

    size_t countAll() {
        return this->buffer.size();
    }

    void push(int number) {
        this->buffer.push_back(number);
    }

    int pop() {
        auto value = this->buffer[0];
        this->buffer.erase(this->buffer.begin());
        return value;
    }

    int peek() {
        return this->buffer[0];
    }

    void fill() {
        for (int i = 0; i < 30; ++i) {
            buffer.push_back(i);
        }
    }

    void print(const std::string &prefix) {
        std::cout << prefix << " [";
        for (auto num: this->buffer) {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

FifoBuffer buffer;

bool canProdEven() {
    return buffer.countEven() < 10;
}

bool canProdOdd() {
    return buffer.countEven() > buffer.countOdd();
}

bool canConsEven() {
    return buffer.countAll() >= 3 && buffer.peek() % 2 == 0;
}

bool canConsOdd() {
    return buffer.countAll() >= 7 && buffer.peek() % 2 != 0;
}

int nextEven() {
    lastEven = (lastEven + 2) % 50;
    return lastEven;
}

int nextOdd() {
    lastOdd = (lastOdd + 2) % 50;
    return lastOdd;
}

[[noreturn]] void *prodEven(void *args) {
    while (true) {
        mutex.p();

        if (!canProdEven()) {
            numOfProdEvenWaiting++;
            mutex.v();
            prodEvenSem.p();
            numOfProdEvenWaiting--;
        }

        buffer.push(nextEven());
        buffer.print("PE");

        if (numOfProdOddWaiting > 0 && canProdOdd()) {
            prodOddSem.v();
        } else if (numOfConsEvenWaiting > 0 && canConsEven()) {
            consEvenSem.v();
        } else if (numOfConsOddWaiting > 0 && canConsOdd()) {
            consOddSem.v();
        } else {
            mutex.v();
        }

        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *prodOdd(void *args) {
    while (true) {
        mutex.p();

        if (!canProdOdd()) {
            numOfProdOddWaiting++;
            mutex.v();
            prodOddSem.p();
            numOfProdOddWaiting--;
        }

        buffer.push(nextOdd());
        buffer.print("PO");

        if (numOfProdEvenWaiting > 0 && canProdEven()) {
            prodEvenSem.v();
        } else if (numOfConsEvenWaiting > 0 && canConsEven()) {
            consEvenSem.v();
        } else if (numOfConsOddWaiting > 0 && canConsOdd()) {
            consOddSem.v();
        } else {
            mutex.v();
        }

        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *consEven(void *args) {
    while (true) {
        mutex.p();

        if (!canConsEven()) {
            numOfConsEvenWaiting++;
            mutex.v();
            consEvenSem.p();
            numOfConsEvenWaiting--;
        }

        buffer.pop();
        buffer.print("CE");

        if (numOfProdEvenWaiting > 0 && canProdEven()) {
            prodEvenSem.v();
        } else if (numOfProdOddWaiting > 0 && canProdOdd()) {
            prodOddSem.v();
        } else if (numOfConsOddWaiting > 0 && canConsOdd()) {
            consOddSem.v();
        } else {
            mutex.v();
        }

        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *consOdd(void *args) {
    while (true) {
        mutex.p();

        if (!canConsOdd()) {
            numOfConsOddWaiting++;
            mutex.v();
            consOddSem.p();
            numOfConsOddWaiting--;
        }

        buffer.pop();
        buffer.print("CO");

        if (numOfProdEvenWaiting > 0 && canProdEven()) {
            prodEvenSem.v();
        } else if (numOfProdOddWaiting > 0 && canProdOdd()) {
            prodOddSem.v();
        } else if (numOfConsEvenWaiting > 0 && canConsEven()) {
            consEvenSem.v();
        } else {
            mutex.v();
        }

        usleep(SLEEP_USECONDS);
    }
}


int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    std::string initialBufferState = argv[5];
    if (initialBufferState != EMPTY && initialBufferState != FULL) {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }
    if (initialBufferState == FULL) {
        buffer.fill();
    }

    std::vector<ThreadGroup> threadGroups = {
            ThreadGroup(std::stoi(argv[1]), prodEven),
            ThreadGroup(std::stoi(argv[2]), prodOdd),
            ThreadGroup(std::stoi(argv[3]), consEven),
            ThreadGroup(std::stoi(argv[4]), consOdd),
    };

    std::cout << "Starting with:" << std::endl;
    std::cout << "- " << threadGroups[0].getNThreads() << " even producer threads:" << std::endl;
    std::cout << "- " << threadGroups[1].getNThreads() << " odd producer threads:" << std::endl;
    std::cout << "- " << threadGroups[2].getNThreads() << " even consumer threads:" << std::endl;
    std::cout << "- " << threadGroups[3].getNThreads() << " odd consumer threads:" << std::endl;
    std::cout << "Initial buffer state:" << std::endl;
    buffer.print("");


    for (auto &group: threadGroups) {
        group.runAll();
    }

    for (auto &group: threadGroups) {
        group.joinAll();
    }


    sleep(1);
    return 0;
}
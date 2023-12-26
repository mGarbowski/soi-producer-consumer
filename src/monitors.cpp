//
// Created by mgarbowski on 26.12.23.
//
#include <iostream>
#include <unistd.h>
#include "BlockingBuffer.h"
#include "ThreadGroup.h"

#define SLEEP_USECONDS 100000
BlockingBuffer buffer;


[[noreturn]] void *evenProducer(void*) {
    int number = 0;
    while (true) {
        buffer.putEven(number);
        number = (number + 2) % 50;
        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *oddProducer(void*) {
    int number = 1;
    while(true) {
        buffer.putOdd(number);
        number = (number + 2) % 50;
        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *evenConsumer(void*) {
    while (true) {
        buffer.popEven();
        usleep(SLEEP_USECONDS);
    }
}

[[noreturn]] void *oddConsumer(void*) {
    while (true) {
        buffer.popOdd();
        usleep(SLEEP_USECONDS);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

//    std::string initialBufferState = argv[5];
//    if (initialBufferState != EMPTY && initialBufferState != FULL) {
//        std::cerr << "Invalid arguments" << std::endl;
//        return 1;
//    }
//    if (initialBufferState == FULL) {
//        buffer.fill();
//    }

    std::vector<ThreadGroup> threadGroups = {
            ThreadGroup(std::stoi(argv[1]), evenProducer),
            ThreadGroup(std::stoi(argv[2]), oddProducer),
            ThreadGroup(std::stoi(argv[3]), evenConsumer),
            ThreadGroup(std::stoi(argv[4]), oddConsumer),
    };

    std::cout << "Starting with:" << std::endl;
    std::cout << "- " << threadGroups[0].getNThreads() << " even producer threads:" << std::endl;
    std::cout << "- " << threadGroups[1].getNThreads() << " odd producer threads:" << std::endl;
    std::cout << "- " << threadGroups[2].getNThreads() << " even consumer threads:" << std::endl;
    std::cout << "- " << threadGroups[3].getNThreads() << " odd consumer threads:" << std::endl;


    for (auto &group: threadGroups) {
        group.runAll();
    }

    for (auto &group: threadGroups) {
        group.joinAll();
    }


    sleep(1);
    return 0;
}
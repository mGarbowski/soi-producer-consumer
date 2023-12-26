//
// Created by mgarbowski on 26.12.23.
//

#include <iostream>
#include "BlockingBuffer.h"

bool BlockingBuffer::canProdEven() const {
    return evenCount < 10;
}

bool BlockingBuffer::canProdOdd() const {
    return evenCount > oddCount;
}

bool BlockingBuffer::canConsEven() {
    return buffer.size() >= 3 && buffer.front() % 2 == 0;
}

bool BlockingBuffer::canConsOdd() {
    return buffer.size() >= 7 && buffer.front() % 2 != 0;
}

BlockingBuffer::BlockingBuffer() {
    this->oddCount = 0;
    this->evenCount = 0;
}

void BlockingBuffer::putEven(int element) {
    if (element % 2 != 0) {
        throw std::invalid_argument("Element must be even");
    }

    enter();

    if (!canProdEven()) {
        wait(prodEvenCond);
    }

    buffer.push(element);
    evenCount++;
    std::cout << buffer.size() << std::endl;

    if (prodOddCond.getWaitingCount() && canProdOdd()) {
        signal(prodOddCond);
    } else if (consOddCond.getWaitingCount() && canConsOdd()) {
        signal(consOddCond);
    } else if (consEvenCond.getWaitingCount() && canConsEven()) {
        signal(consEvenCond);
    } else {
        leave();
    }
}

void BlockingBuffer::putOdd(int element) {
    if (element % 2 == 0) {
        throw std::invalid_argument("Element must be odd");
    }

    enter();

    if (!canProdOdd()) {
        wait(prodOddCond);
    }

    buffer.push(element);
    oddCount++;
    std::cout << buffer.size() << std::endl;

    if (prodEvenCond.getWaitingCount() && canProdEven()) {
        signal(prodEvenCond);
    } else if (consOddCond.getWaitingCount() && canConsOdd()) {
        signal(consOddCond);
    } else if (consEvenCond.getWaitingCount() && canConsEven()) {
        signal(consEvenCond);
    } else {
        leave();
    }
}

int BlockingBuffer::popEven() {
    enter();

    if (!canConsEven()) {
        wait(consEvenCond);
    }

    int element = buffer.front();
    buffer.pop();
    evenCount--;
    std::cout << buffer.size() << std::endl;

    if (prodEvenCond.getWaitingCount() && canProdEven()) {
        signal(prodEvenCond);
    } else if (prodOddCond.getWaitingCount() && canProdOdd()) {
        signal(prodOddCond);
    } else if (consOddCond.getWaitingCount() && canConsOdd()) {
        signal(consOddCond);
    } else {
        leave();
    }

    return element;
}

int BlockingBuffer::popOdd() {
    enter();

    if (!canConsOdd()) {
        wait(consOddCond);
    }

    int element = buffer.front();
    buffer.pop();
    oddCount--;
    std::cout << buffer.size() << std::endl;

    if (prodEvenCond.getWaitingCount() && canProdEven()) {
        signal(prodEvenCond);
    } else if (prodOddCond.getWaitingCount() && canProdOdd()) {
        signal(prodOddCond);
    } else if (consEvenCond.getWaitingCount() && canConsEven()) {
        signal(consEvenCond);
    } else {
        leave();
    }

    return element;
}

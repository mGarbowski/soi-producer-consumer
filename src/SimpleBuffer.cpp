//
// Created by mgarbowski on 26.12.23.
//

#include "SimpleBuffer.h"

size_t SimpleBuffer::countEven() {
    return std::count_if(
            this->buffer.begin(), this->buffer.end(),
            [](int number) { return number % 2 == 0; }
    );
}

size_t SimpleBuffer::countOdd() {
    return std::count_if(
            this->buffer.begin(), this->buffer.end(),
            [](int number) { return number % 2 != 0; }
    );
}

size_t SimpleBuffer::countAll() {
    return this->buffer.size();
}

void SimpleBuffer::push(int number) {
    this->buffer.push_back(number);
}

int SimpleBuffer::pop() {
    auto value = this->buffer[0];
    this->buffer.erase(this->buffer.begin());
    return value;
}

int SimpleBuffer::peek() {
    return this->buffer[0];
}

void SimpleBuffer::fill() {
    for (int i = 0; i < 30; ++i) {
        buffer.push_back(i);
    }
}

void SimpleBuffer::print(const std::string &prefix) {
    std::cout << prefix << " [";
    for (auto num: this->buffer) {
        std::cout << num << ", ";
    }
    std::cout << "]" << std::endl;
}

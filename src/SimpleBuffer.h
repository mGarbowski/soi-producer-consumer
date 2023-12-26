//
// Created by mgarbowski on 26.12.23.
//

#ifndef SOI_PRODUCER_CONSUMER_SIMPLEBUFFER_H
#define SOI_PRODUCER_CONSUMER_SIMPLEBUFFER_H


#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

class SimpleBuffer {
private:
    std::vector<int> buffer;
public:
    SimpleBuffer() = default;

    size_t countEven();

    size_t countOdd();

    size_t countAll();

    void push(int number);

    int pop();

    int peek();

    void fill();

    void print(const std::string &prefix);
};


#endif //SOI_PRODUCER_CONSUMER_SIMPLEBUFFER_H

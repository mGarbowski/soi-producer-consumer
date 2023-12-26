//
// Created by mgarbowski on 26.12.23.
//

#ifndef SOI_PRODUCER_CONSUMER_BLOCKINGBUFFER_H
#define SOI_PRODUCER_CONSUMER_BLOCKINGBUFFER_H

#include "monitor.h"
#include <queue>
#include <stdexcept>

class BlockingBuffer : Monitor {
private:
    std::queue<int> buffer;
    Condition prodEvenCond;
    Condition prodOddCond;
    Condition consEvenCond;
    Condition consOddCond;
    size_t oddCount;
    size_t evenCount;


    [[nodiscard]] bool canProdEven() const;

    [[nodiscard]] bool canProdOdd() const;

    bool canConsEven();

    bool canConsOdd();


public:
    BlockingBuffer();

    void putEven(int element);

    void putOdd(int element);

    int popEven();

    int popOdd();

    void fill();
};


#endif //SOI_PRODUCER_CONSUMER_BLOCKINGBUFFER_H

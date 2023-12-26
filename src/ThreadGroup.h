//
// Created by mgarbowski on 26.12.23.
//

#ifndef SOI_PRODUCER_CONSUMER_THREADGROUP_H
#define SOI_PRODUCER_CONSUMER_THREADGROUP_H

#include <vector>
#include "Thread.h"

class ThreadGroup {
private:
    int nThreads;
    std::vector<Thread> threads;
public:
    ThreadGroup(int nThreads, const std::function<void *(void *)> &startFunction);


    [[nodiscard]] int getNThreads() const;

    void runAll();

    void joinAll();
};


#endif //SOI_PRODUCER_CONSUMER_THREADGROUP_H

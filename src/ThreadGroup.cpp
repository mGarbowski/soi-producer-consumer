//
// Created by mgarbowski on 26.12.23.
//

#include "ThreadGroup.h"

ThreadGroup::ThreadGroup(int nThreads, const std::function<void *(void *)> &startFunction)
        : nThreads(nThreads), threads(nThreads, Thread(startFunction)) {}

int ThreadGroup::getNThreads() const {
    return nThreads;
}

void ThreadGroup::runAll() {
    for (auto &thread: threads) {
        thread.run();
    }
}

void ThreadGroup::joinAll() {
    for (const auto &thread: threads) {
        thread.join();
    }
}

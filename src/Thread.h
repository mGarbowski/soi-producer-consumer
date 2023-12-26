//
// Created by mgarbowski on 26.12.23.
//

#ifndef SOI_PRODUCER_CONSUMER_THREAD_H
#define SOI_PRODUCER_CONSUMER_THREAD_H

#include <pthread.h>
#include <utility>
#include <algorithm>

class Thread {
private:
    pthread_t threadId{};
    std::function<void *(void *)> func;

public:
    explicit Thread(std::function<void *(void *)> function);

    void run();

    void join() const;

    static void *threadEntryPoint(void *obj);
};


#endif //SOI_PRODUCER_CONSUMER_THREAD_H

//
// Created by mgarbowski on 26.12.23.
//

#include "Thread.h"

Thread::Thread(std::function<void *(void *)> function) {
    this->func = std::move(function);
}

void Thread::run() {
    pthread_create(&threadId, nullptr, threadEntryPoint, this);
}

void Thread::join() const {
    pthread_join(threadId, nullptr);
}

void *Thread::threadEntryPoint(void *obj) {
    return reinterpret_cast<Thread *>(obj)->func(nullptr);
}

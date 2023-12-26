cmake_minimum_required(VERSION 3.22)
project(soi_producer_consumer)

set(CMAKE_CXX_STANDARD 17)

set(COMMON_SOURCES
        src/utils.h
        src/common.h
        src/Thread.h
        src/Thread.cpp
        src/ThreadGroup.h
        src/ThreadGroup.cpp
)

add_executable(semaphores-app src/semaphores.cpp src/SimpleBuffer.h src/SimpleBuffer.cpp ${COMMON_SOURCES})
add_executable(monitors-app src/monitors.cpp src/BlockingBuffer.h src/BlockingBuffer.cpp ${COMMON_SOURCES})

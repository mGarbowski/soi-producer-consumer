cmake_minimum_required(VERSION 3.27)
project(soi_producer_consumer)

set(CMAKE_CXX_STANDARD 17)

set(COMMON_SOURCES
        src/Thread.h
        src/Thread.cpp
        src/ThreadGroup.h
        src/ThreadGroup.cpp
        src/monitor.h
)

add_executable(semaphores-app src/semaphores.cpp ${COMMON_SOURCES})

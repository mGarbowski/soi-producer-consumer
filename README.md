# Producer-consumer problem
Mikołaj Garbowski

Two solutions to a producer-consumer synchronization problem with shared buffer. Using semaphores and monitors.

Assignment for Operating Systems course @ Warsaw University of Technology.

## Build
```shell
mkdir cmake-build-debug
cmake -S . -B cmake-build-debug/
cmake --build cmake-build-debug/
```

## Run
```shell
./cmake-build-debug/semaphores-app 1 1 1 1 empty
```

```shell
./cmake-build-debug/monitors-app 1 1 1 1 empty
```


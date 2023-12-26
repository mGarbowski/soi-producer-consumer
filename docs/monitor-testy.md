# Testy
Wyniki uruchomienia programu `monitors-app` z podanymi argumentami

## Założenia
* Przyjąłem że konsument liczb parzystych może pracować tylko jeśli na początku bufora jest liczba parzysta (i analogicznie konsument nieparzysty)
* Przyjąłem, że pełny bufor oznacza zapełniony liczbami od 0 do 29

Wyniki są zgodne z oczekiwaniami

## `./cmake-build-debug/monitors-app 1 0 0 0 empty`
```
Starting with:
- 1 even producer threads:
- 0 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
1
2
3
4
5
6
7
8
9
10
^C
```

## `./cmake-build-debug/monitors-app 1 0 0 0 full`
```
Starting with:
- 1 even producer threads:
- 0 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 1 0 0 empty`
```
Starting with:
- 0 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 1 0 0 full`
```
Starting with:
- 0 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 0 1 0 empty`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 0 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 0 1 0 full`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 0 odd consumer threads:
29
^C
```

## `./cmake-build-debug/monitors-app 0 0 0 1 empty`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 0 even consumer threads:
- 1 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 0 0 1 full`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 0 even consumer threads:
- 1 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 1 1 0 0 empty`
```
Starting with:
- 1 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
^C
```

## `./cmake-build-debug/monitors-app 1 1 0 0 full`
```
Starting with:
- 1 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 0 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 0 1 1 empty`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 1 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 0 1 1 full`
```
Starting with:
- 0 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 1 odd consumer threads:
29
28
27
26
25
24
23
22
21
20
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
^C
```

## `./cmake-build-debug/monitors-app 1 0 1 0 empty`
```
Starting with:
- 1 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 0 odd consumer threads:
1
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
3
2
^C
```

## `./cmake-build-debug/monitors-app 1 0 1 0 full`
```
Starting with:
- 1 even producer threads:
- 0 odd producer threads:
- 1 even consumer threads:
- 0 odd consumer threads:
29
^C
```

## `./cmake-build-debug/monitors-app 0 1 0 1 empty`
```
Starting with:
- 0 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 1 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 0 1 0 1 full`
```
Starting with:
- 0 even producer threads:
- 1 odd producer threads:
- 0 even consumer threads:
- 1 odd consumer threads:
^C
```

## `./cmake-build-debug/monitors-app 1 1 1 1 empty`
```
Starting with:
- 1 even producer threads:
- 1 odd producer threads:
- 1 even consumer threads:
- 1 odd consumer threads:
1
2
3
4
3
4
5
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
5
6
7
8
7
6
7
6
5
6
7
8
7
6
7
8
7
6
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
7
8
7
6
^C
```

## `./cmake-build-debug/monitors-app 1 1 1 1 full`
```
Starting with:
- 1 even producer threads:
- 1 odd producer threads:
- 1 even consumer threads:
- 1 odd consumer threads:
29
28
27
26
25
24
23
22
21
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
18
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
^C
```

## `./cmake-build-debug/monitors-app 2 2 2 2 empty`
```
Starting with:
- 2 even producer threads:
- 2 odd producer threads:
- 2 even consumer threads:
- 2 odd consumer threads:
1
2
3
4
3
2
3
4
5
6
7
8
7
8
7
6
7
6
7
8
7
6
7
6
7
8
7
8
7
8
7
6
7
8
7
8
9
8
7
6
7
8
7
8
9
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
7
8
7
6
7
8
7
8
^C
```

## `./cmake-build-debug/monitors-app 2 2 2 2 full`
```
Starting with:
- 2 even producer threads:
- 2 odd producer threads:
- 2 even consumer threads:
- 2 odd consumer threads:
29
28
27
26
25
24
23
22
21
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
20
19
18
19
20
19
20
19
20
19
18
19
20
19
20
19
20
19
18
19
20
19
20
19
20
19
18
19
20
19
20
19
20
19
^C
```
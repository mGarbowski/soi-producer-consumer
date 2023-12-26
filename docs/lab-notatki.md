trzeba linkować pthread
sekcja krytyczna powinna być jak najmniejsza
dowolna technologia, nie trzeba używać semaforu kruka

preferowane rozwiązanie - 5 semaforów binarnych
rozwiązanie na wątkach - pthread

testy - bufor na początku pustu i oddzielnie bufor bufor pełny
* tylko producent parzysty - zapełni bufor i się zatrzyma
* tylko producent nieparzysty - nic nie zrobi
* tylko konsument parzysty - nic nie zrobi
* tlyko konsument nieparzysty - nic nie zrobi
* dwóch producentów - zapełnią bufor i się zatrzymają
* dwóch konsumentów - nic nie zrobią
* producent parzysty i konsument parzysty - działą w nieskończoność
* producent nieparzysty i konsument nieparzysty - nic nie zrobią (bufor jest pusty)
* prodEven prodOdd consEven consOdd - powinno działać w nieskończoność
* po 2 z każdego

oddajemy pdfa z wynikami testów
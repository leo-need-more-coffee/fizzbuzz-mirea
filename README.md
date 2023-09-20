# fizzbuzz-mirea
Запускать:
```
gcc -fopenmp -Ofast -march=native -flto -funroll-loops -finline-functions -ffast-math -g -o fizzbuzz fizzbuzz.c -lpthread && ./fizzbuzz
```
Там в коде есть строка, которая считает гипотетическое время выполнения, настоящее надо замерять как-то по другому.

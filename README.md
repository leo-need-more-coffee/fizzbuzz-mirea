# fizzbuzz-mirea
Запускать:
```
clang -Ofast -march=native -flto -funroll-loops -finline-functions -ffast-math -o fizzbuzz fizzbuzz.c && ./fizzbuzz
```
Там в коде есть строка, которая считает гипотетическое время выполнения, настоящее надо замерять как-то по другому.

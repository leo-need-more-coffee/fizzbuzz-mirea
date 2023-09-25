# fizzbuzz-mirea
Запускать:
```
clang -Ofast -march=native -flto -funroll-loops -finline-functions -ffast-math -ffinite-math-only -fno-signed-zeros -fno-trapping-math -fassociative-math -fno-math-errno -freciprocal-math -funsafe-math-optimizations -o fizzbuzz fizzbuzz.c && ./fizzbuzz
```
Там в коде есть строка, которая считает гипотетическое время выполнения, настоящее надо замерять как-то по другому.

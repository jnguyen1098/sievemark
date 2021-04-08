#!/usr/bin/env sh

clang -Ofast -std=c99 -Wall -Wpedantic -Wextra -ggdb3 sieve.c -lm
# valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./a.out
./a.out
rm a.out

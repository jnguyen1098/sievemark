#!/usr/bin/env sh

clang -O0 -std=c99 -Wall -Wpedantic -Wextra -ggdb3 sieve.c
# valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./a.out
./a.out
rm a.out

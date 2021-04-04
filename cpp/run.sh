#!/usr/bin/env sh

g++ -Ofast sieve.cpp
# valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./a.out
./a.out
rm a.out

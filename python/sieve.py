#!/usr/bin/env python3
import time
import sieve_assert

NUM_LIMIT = 100000
NUM_PRIMES = 9592

def sieve(results):
    n = 0
    numbers = [0] * (NUM_LIMIT + 1)
    for i in range(2, NUM_LIMIT + 1):
        for j in range(2 * i, NUM_LIMIT + 1, i):
            numbers[j] = 1
    for i in range(2, NUM_LIMIT + 1):
        if numbers[i] == 0:
            results[n] = i
            n += 1

results = [0] * NUM_PRIMES

start = time.time()
sieve(results)
end = time.time()

for i in range(len(sieve_assert.expected_results)):
    if results[i] != sieve_assert.expected_results[i]:
        print("Fail")
        exit(0)
        # print(f"Expected {sieve_assert.expected_results[i]} but got {results[i]}")

print('{:.6f}%'.format(end - start))

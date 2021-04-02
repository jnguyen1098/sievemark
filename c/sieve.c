#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "sieve.h"

void sieve_of_eratosthenes(int results[NUM_PRIMES])
{
    int n = 0;
    for (int i = 0; i < NUM_PRIMES; i++) {
        results[i] = 0;
    }
}

int main(void)
{
    int results[NUM_PRIMES] = { 0 };

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sieve_of_eratosthenes(results);
    end = clock();

    for (int i = 0; i < NUM_PRIMES; i++) {
        assert(primes[i] == results[i]);
    }

    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

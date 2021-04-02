#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "sieve.h"

void sieve_of_eratosthenes(int results[NUM_PRIMES])
{
    int n = 0;
    int numbers[NUM_LIMIT + 1] = { 0 };
    for (int i = 2; i <= NUM_LIMIT; i++) {
        for (int j = 2 * i; j <= NUM_LIMIT; j += i) {
            numbers[j] = 1;
        }
    }
    for (int i = 2; i <= NUM_LIMIT; i++) {
        if (numbers[i] == 0) {
            results[n++] = i;
        }
    }
}

int main(void)
{
    int results[NUM_PRIMES] = { 0 };

    clock_t start, end;

    start = clock();
    sieve_of_eratosthenes(results);
    end = clock();

    int fail = 0;

    for (int i = 0; i < NUM_PRIMES; i++) {
        if (primes[i] != results[i]) {
            fail = 1;
            printf("Expected %d but got %d\n", primes[i], results[i]);
        }
    }

    printf(fail ? "Fail\n" : "");

    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

#include <time.h>
#include "sieve.h"

void sieve_of_erathosthenes(int results[NUM_PRIMES])
{
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

    printf("%.3f\n", ((double)t / CLOCKS_PER_SEC));

    return 0;
}

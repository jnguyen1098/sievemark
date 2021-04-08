#include <time.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "sieve.h"
// https://craftofcoding.wordpress.com/2021/04/06/algorithm-35-the-sieve-in-algol-68/
void sieve_of_eratosthenes(int results[NUM_PRIMES])
{
    results[0] = 1;
    results[1] = 2;
    results[2] = 3;
    int n = 2;
    int i = 2;
    int j = 2;
    for (; n <= NUM_LIMIT; n++) {
        if (results[n] < sqrt((float)n)) {
            goto a1;
        } else {
            goto a2;
        }
    }
    a1:
        if (n / results[i] == n % results[i]) {
            goto b1;
        } else {
            goto b2;
        }
    a2:
        results[j] = n;
        j++;
    b1:
        return;
    b2:
        i++;
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

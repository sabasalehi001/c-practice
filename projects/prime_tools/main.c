#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Sieve of Eratosthenes
int *sieve_of_eratosthenes(int limit, int *count) {
    char *isPrime = (char *)malloc((limit + 1) * sizeof(char));
    if (isPrime == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    memset(isPrime, 1, (limit + 1) * sizeof(char)); // Assume all numbers are prime initially
    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = 0;
            }
        }
    }

    // Count the number of primes
    *count = 0;
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            (*count)++;
        }
    }

    // Allocate memory for the primes array
    int *primes = (int *)malloc((*count) * sizeof(int));
    if (primes == NULL) {
        perror("Memory allocation failed");
        free(isPrime);
        exit(EXIT_FAILURE);
    }

    // Populate the primes array
    int index = 0;
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes[index++] = p;
        }
    }

    free(isPrime);
    return primes;
}

// Prime Factorization
void prime_factorization(int n) {
    printf("Prime factors: ");
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    if (n > 1) {
        printf("%d ", n);
    }
    printf("\n");
}

int main() {
    int choice, number, limit, prime_count, *primes;

    printf("Choose an operation:\n");
    printf("1. Generate primes using Sieve of Eratosthenes\n");
    printf("2. Prime Factorization\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the upper limit: ");
        scanf("%d", &limit);

        primes = sieve_of_eratosthenes(limit, &prime_count);

        printf("Primes up to %d: ", limit);
        for (int i = 0; i < prime_count; i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");

        free(primes);
    } else if (choice == 2) {
        printf("Enter the number to factorize: ");
        scanf("%d", &number);
        prime_factorization(number);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}

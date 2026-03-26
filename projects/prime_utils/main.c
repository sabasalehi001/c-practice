#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to implement Sieve of Eratosthenes
void sieve_of_eratosthenes(int n) {
    if (n < 2) {
        printf("No prime numbers in this range.\n");
        return;
    }
    
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    char *prime = (char *)malloc((n + 1) * sizeof(char));
    memset(prime, 1, (n + 1) * sizeof(char));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == 1) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are: ", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");

    free(prime);
}

// Function to find prime factors of a number
void prime_factorization(int n) {
    if (n <= 1) {
        printf("No prime factors for numbers less than or equal to 1.\n");
        return;
    }
    
    printf("Prime factors of %d are: ", n);

    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        printf("2 ");
        n = n / 2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        printf("%d ", n);

    printf("\n");
}

int main() {
    int choice, number;

    printf("Prime Number Toolkit\n");
    printf("1. Sieve of Eratosthenes\n");
    printf("2. Prime Factorization\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the upper limit for Sieve of Eratosthenes: ");
            scanf("%d", &number);
            sieve_of_eratosthenes(number);
            break;
        case 2:
            printf("Enter the number for Prime Factorization: ");
            scanf("%d", &number);
            prime_factorization(number);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert an integer to a Roman numeral
char *intToRoman(int num) {
    if (num < 1 || num > 3999) {
        return NULL; // Invalid input
    }

    char *roman = (char *)malloc(16 * sizeof(char)); // Allocate memory for the Roman numeral (max length)
    roman[0] = '\0'; // Initialize as an empty string

    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(roman, symbols[i]);
            num -= values[i];
        }
    }

    return roman;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    char *endptr;
    long num = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || num < 1 || num > 3999) {
        fprintf(stderr, "Invalid input. Please enter an integer between 1 and 3999.\n");
        return 1;
    }

    char *romanNumeral = intToRoman((int)num);

    if (romanNumeral != NULL) {
        printf("%s\n", romanNumeral);
        free(romanNumeral); // Free the allocated memory
    } else {
        fprintf(stderr, "Error converting to Roman numeral.\n");
        return 1;
    }

    return 0;
}
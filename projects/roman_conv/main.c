#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an integer to a Roman numeral
char *intToRoman(int num) {
    if (num < 1 || num > 3999) {
        return NULL; // Invalid input
    }

    char *roman = (char *)malloc(16 * sizeof(char)); // Allocate enough space
    roman[0] = '\0'; // Initialize as an empty string

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

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

    int num = atoi(argv[1]);

    char *romanNumeral = intToRoman(num);

    if (romanNumeral == NULL) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer between 1 and 3999.\n");
        return 1;
    }

    printf("%s\n", romanNumeral);
    free(romanNumeral);

    return 0;
}
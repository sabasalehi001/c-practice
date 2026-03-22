#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char *password = argv[1];
    int length = strlen(password);

    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_symbol = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    int score = 0;

    // Length bonus
    if (length >= 8) {
        score += 20;
    } else {
        score += length * 2;
    }

    // Character class bonus
    if (has_upper) score += 20;
    if (has_lower) score += 20;
    if (has_digit) score += 20;
    if (has_symbol) score += 20;

    // Normalize score to 0-100
    if (score > 100) {
        score = 100;
    }

    printf("Password strength: %d\n", score);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate_strength(const char *password) {
    int length = strlen(password);
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    int i;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    int score = 0;

    // Length bonus
    score += length * 4;

    // Character class bonuses
    if (has_upper) score += 10;
    if (has_lower) score += 10;
    if (has_digit) score += 10;
    if (has_special) score += 10;

    // Length penalties
    if (length < 8) score -= (8 - length) * 2;

    // Adjust score to be within 0-100
    if (score < 0) score = 0;
    if (score > 100) score = 100;

    return score;
}

const char *get_strength_level(int score) {
    if (score <= 25) {
        return "Very Weak";
    } else if (score <= 50) {
        return "Weak";
    } else if (score <= 75) {
        return "Medium";
    } else if (score <= 99) {
        return "Strong";
    } else {
        return "Very Strong";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char *password = argv[1];
    int strength = calculate_strength(password);
    const char *level = get_strength_level(strength);

    printf("Password Strength: %d/100 (%s)\n", strength, level);

    return 0;
}
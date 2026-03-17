#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char *password = argv[1];
    int length = strlen(password);

    int hasLower = 0;
    int hasUpper = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLower = 1;
        } else if (isupper(password[i])) {
            hasUpper = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    int score = 0;

    // Length bonus
    if (length >= 8) {
        score += 20;
    }
    if (length >= 12) {
        score += 20;
    }

    // Character class bonus
    if (hasLower) {
        score += 15;
    }
    if (hasUpper) {
        score += 15;
    }
    if (hasDigit) {
        score += 15;
    }
    if (hasSpecial) {
        score += 15;
    }

    // Normalize the score to a percentage
    score = (score > 100) ? 100 : score;

    printf("Password Strength: %d%%\n", score);

    if (score < 50) {
        printf("Weak password.\n");
    } else if (score < 80) {
        printf("Moderate password.\n");
    } else {
        printf("Strong password.\n");
    }

    return 0;
}
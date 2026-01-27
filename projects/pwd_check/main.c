#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[256];
    int length = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;

    printf("Enter password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        perror("Error reading input");
        return 1;
    }

    // Remove trailing newline character
    password[strcspn(password, "\n")] = 0;

    length = strlen(password);

    if (length == 0) {
        printf("Password strength: Empty\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
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

    int strength = 0;
    if (length >= 8) strength++;
    if (has_upper) strength++;
    if (has_lower) strength++;
    if (has_digit) strength++;
    if (has_special) strength++;

    printf("Password strength: ");
    switch (strength) {
        case 0:
        case 1:
            printf("Very Weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Very Strong\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}
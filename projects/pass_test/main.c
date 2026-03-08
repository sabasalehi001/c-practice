#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    char *password = argv[1];
    int length = strlen(password);
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    int strength = 0;
    if (length >= 8) strength++;
    if (hasUpper) strength++;
    if (hasLower) strength++;
    if (hasDigit) strength++;
    if (hasSpecial) strength++;

    printf("Password strength: ");
    if (strength <= 1) {
        printf("Very Weak\n");
    } else if (strength == 2) {
        printf("Weak\n");
    } else if (strength == 3) {
        printf("Moderate\n");
    } else if (strength == 4) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}
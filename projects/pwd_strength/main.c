#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
    int has_special = 0;

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

    printf("Password Strength: %d/5\n", strength);

    return 0;
}
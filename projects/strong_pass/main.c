#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    // Remove trailing newline
    password[strcspn(password, "\n")] = 0;

    int length = strlen(password);
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSymbol = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSymbol = 1;
        }
    }

    int classCount = hasUpper + hasLower + hasDigit + hasSymbol;

    if (length < 8 || classCount < 2) {
        printf("Password strength: Weak\n");
    } else if (length >= 8 && length <= 12 && classCount >= 2) {
        printf("Password strength: Moderate\n");
    } else {
        printf("Password strength: Strong\n");
    }

    return 0;
}
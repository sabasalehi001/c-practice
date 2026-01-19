#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"json_string\"\n", argv[0]);
        return 1;
    }

    const char *json_string = argv[1];
    int brace_count = 0;
    int quote_count = 0;
    int i = 0;

    while (json_string[i] != '\0') {
        if (json_string[i] == '{') {
            brace_count++;
        } else if (json_string[i] == '}') {
            brace_count--;
        } else if (json_string[i] == '"' && (i == 0 || json_string[i-1] != '\\')) { // Handle escaped quotes
            quote_count++;
        }

        if (brace_count < 0) {
            printf("Invalid: Unmatched closing brace.\n");
            return 1;
        }
        i++;
    }

    if (brace_count != 0) {
        printf("Invalid: Unmatched brace.\n");
        return 1;
    }

    if (quote_count % 2 != 0) {
        printf("Invalid: Unmatched quote.\n");
        return 1;
    }

    printf("Valid JSON-like string.\n");
    return 0;
}
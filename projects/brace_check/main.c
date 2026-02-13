#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_valid(const char *input) {
    int brace_count = 0;
    bool in_string = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '"') {
            in_string = !in_string;
        } else if (!in_string) {
            if (input[i] == '{') {
                brace_count++;
            } else if (input[i] == '}') {
                brace_count--;
            }
        }
        if (brace_count < 0) {
            return false;
        }
    }

    return brace_count == 0 && !in_string; // Also check if string is unclosed
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s '<json_string>'\n", argv[0]);
        return 1;
    }

    if (is_valid(argv[1])) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
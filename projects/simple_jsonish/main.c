#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s 'json_string'\n", argv[0]);
        return 1;
    }

    const char *json_string = argv[1];
    int brace_count = 0;
    int in_string = 0;

    for (int i = 0; json_string[i] != '\0'; i++) {
        if (json_string[i] == '{') {
            brace_count++;
        } else if (json_string[i] == '}') {
            brace_count--;
        } else if (json_string[i] == '"') {
            in_string = !in_string;
        }

        if (brace_count < 0) {
            printf("Invalid JSONish\n");
            return 0;
        }
    }

    if (brace_count == 0 && !in_string) {
        printf("Valid JSONish\n");
    } else {
        printf("Invalid JSONish\n");
    }

    return 0;
}
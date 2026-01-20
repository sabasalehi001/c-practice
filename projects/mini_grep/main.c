#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <search_string> <file>\n", argv[0]);
        return 1;
    }

    const char *search_string = argv[1];
    const char *filename = argv[2];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    return 0;
}
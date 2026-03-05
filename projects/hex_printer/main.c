#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void print_hex_ascii(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    long offset = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        printf("%08lx: ", offset);

        // Print hex values
        for (size_t i = 0; i < BUFFER_SIZE; i++) {
            if (i < bytes_read) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   "); // Padding for incomplete lines
            }
        }

        // Print ASCII values
        printf(" ");
        for (size_t i = 0; i < bytes_read; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");

        offset += bytes_read;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_hex_ascii(argv[1]);

    return EXIT_SUCCESS;
}
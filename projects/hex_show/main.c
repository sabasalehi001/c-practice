#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void hexdump(FILE *fp) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    unsigned long offset = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        printf("%08lx: ", offset);

        // Hex part
        for (size_t i = 0; i < BUFFER_SIZE; i++) {
            if (i < bytes_read) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   "); // Padding for incomplete lines
            }
        }

        printf("  ");

        // ASCII part
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
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin; // Default to stdin

    if (argc > 1) {
        fp = fopen(argv[1], "rb");
        if (fp == NULL) {
            perror("Error opening file");
            return 1;
        }
    }

    hexdump(fp);

    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}
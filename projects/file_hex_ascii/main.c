#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void hexdump(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    long offset = 0;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        printf("%08lx: ", offset);

        for (size_t i = 0; i < BUFFER_SIZE; i++) {
            if (i < bytesRead) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   ");
            }
        }

        printf("         ");

        for (size_t i = 0; i < bytesRead; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");

        offset += bytesRead;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    hexdump(argv[1]);

    return 0;
}
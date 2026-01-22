#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void print_hex_and_ascii(const char *buffer, int len, long offset) {
    printf("%08lx: ", offset);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (i < len) {
            printf("%02x ", (unsigned char)buffer[i]);
        } else {
            printf("   ");
        }
        if (i == 7) printf(" ");
    }

    printf(" ");

    for (int i = 0; i < len; i++) {
        if (isprint((unsigned char)buffer[i])) {
            printf("%c", buffer[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    long offset = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        print_hex_and_ascii(buffer, bytes_read, offset);
        offset += bytes_read;
    }

    fclose(fp);
    return 0;
}
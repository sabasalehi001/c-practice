#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void print_hex_ascii_line(const unsigned char *buf, int len, int offset) {
    int i;
    printf("%08x: ", offset);

    // Hexadecimal representation
    for (i = 0; i < BUFFER_SIZE; i++) {
        if (i < len) {
            printf("%02x ", buf[i]);
        } else {
            printf("   "); // Pad with spaces for incomplete lines
        }
        if (i == 7) printf(" "); // Add extra space after 8 bytes
    }

    printf("      ");

    // ASCII representation
    for (i = 0; i < len; i++) {
        if (isprint(buf[i])) {
            printf("%c", buf[i]);
        } else {
            printf("."); // Replace non-printable characters with dots
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int offset = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        print_hex_ascii_line(buffer, (int)bytes_read, offset);
        offset += BUFFER_SIZE;
    }

    fclose(fp);
    return 0;
}
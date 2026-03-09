#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 16

void print_hex_ascii(const char *filename);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  print_hex_ascii(argv[1]);

  return 0;
}

void print_hex_ascii(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  unsigned char buffer[BUFFER_SIZE];
  size_t bytes_read;
  long offset = 0;

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
    printf("%08lx: ", offset);

    for (size_t i = 0; i < BUFFER_SIZE; i++) {
      if (i < bytes_read) {
        printf("%02x ", buffer[i]);
      } else {
        printf("   "); // Pad with spaces if less than BUFFER_SIZE bytes were read
      }
    }

    printf("         "); // Spacing between hex and ascii

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
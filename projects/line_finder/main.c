#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <substring> <filename>\n", argv[0]);
    return 1;
  }

  const char *substring = argv[1];
  const char *filename = argv[2];

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strstr(line, substring) != NULL) {
      printf("%s", line);
    }
  }

  fclose(file);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <log_file>
", argv[0]);
    return 1;
  }

  const char *log_file = argv[1];
  FILE *fp = fopen(log_file, "r");
  if (fp == NULL) {
    perror("Error opening log file");
    return 1;
  }

  int info_count = 0;
  int warn_count = 0;
  int error_count = 0;
  char line[MAX_LINE_LENGTH];

  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    if (strstr(line, "INFO:") != NULL) {
      info_count++;
    }
    if (strstr(line, "WARN:") != NULL) {
      warn_count++;
    }
    if (strstr(line, "ERROR:") != NULL) {
      error_count++;
    }
  }

  fclose(fp);

  printf("INFO: %d\n", info_count);
  printf("WARN: %d\n", warn_count);
  printf("ERROR: %d\n", error_count);

  return 0;
}
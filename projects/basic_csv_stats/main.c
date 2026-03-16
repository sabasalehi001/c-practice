#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define DELIMITER ","

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <csv_file> <column_index>\n", argv[0]);
        return 1;
    }

    const char *csv_file = argv[1];
    int column_index = atoi(argv[2]);

    FILE *fp = fopen(csv_file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    double sum = 0.0;
    double min = -1.0; // Initialize to -1 to handle cases where the first value is positive
    double max = -1.0; // Initialize to -1 to handle cases where the first value is positive
    int count = 0;

    // Skip the header line
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        fprintf(stderr, "Error reading header line or empty file.\n");
        fclose(fp);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token;
        char *rest = line;
        int current_column = 0;
        double value;

        while ((token = strsep(&rest, DELIMITER)) != NULL) {
            // Remove leading/trailing whitespace
            while (isspace((unsigned char)*token)) token++;
            char *end = token + strlen(token) - 1;
            while (end > token && isspace((unsigned char)*end)) end--;
            *(end+1) = 0;

            if (current_column == column_index) {
                char *endptr;
                value = strtod(token, &endptr);

                if (*endptr != '\0' && *endptr != '\n') {
                    fprintf(stderr, "Warning: Invalid numeric value '%s' in column %d. Skipping.\n", token, column_index);
                    break; // Skip to the next line
                }

                if (count == 0) {
                    min = value;
                    max = value;
                } else {
                    if (value < min) {
                        min = value;
                    }
                    if (value > max) {
                        max = value;
                    }
                }

                sum += value;
                count++;
                break; // Move to next line after processing desired column
            }
            current_column++;
        }
    }

    fclose(fp);

    if (count == 0) {
        fprintf(stderr, "No valid numeric data found in column %d.\n", column_index);
        return 1;
    }

    double mean = sum / count;

    printf("{\n");
    printf("  \"mean\": %.2f,\n", mean);
    printf("  \"min\": %.2f,\n", min);
    printf("  \"max\": %.2f\n", max);
    printf("}\n");

    return 0;
}

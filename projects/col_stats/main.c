#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

#define MAX_LINE_LENGTH 1024

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
    double min = DBL_MAX;
    double max = DBL_MIN;
    int count = 0;
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_num++;
        // Skip the header line
        if (line_num == 1) continue;

        char *token;
        char *rest = line;
        int current_column = 0;

        while ((token = strtok_r(rest, ",", &rest)) != NULL) {
            if (current_column == column_index) {
                // Trim leading/trailing whitespace
                char *start = token;
                while (isspace((unsigned char)*start)) start++;
                char *end = start + strlen(start) - 1;
                while (end > start && isspace((unsigned char)*end)) end--;
                end[1] = '\0';

                char *endptr;
                double value = strtod(start, &endptr);

                if (*endptr == '\0') {
                    sum += value;
                    if (value < min) min = value;
                    if (value > max) max = value;
                    count++;
                } else {
                    fprintf(stderr, "Warning: Invalid numeric value '%s' in column %d, line %d. Skipping.\n", start, column_index, line_num);
                }
                break; // Stop tokenizing after target column is processed
            }
            current_column++;
        }
    }

    fclose(fp);

    if (count > 0) {
        double mean = sum / count;
        printf("Mean: %lf\n", mean);
        printf("Min: %lf\n", min);
        printf("Max: %lf\n", max);
    } else {
        fprintf(stderr, "No valid numeric data found in column %d\n", column_index);
        return 1;
    }

    return 0;
}
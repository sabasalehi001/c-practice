#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

double calculate_mean(double *data, int count) {
    if (count == 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum / count;
}

double find_min(double *data, int count) {
    if (count == 0) {
        return 0.0; // Or some other reasonable default, like infinity
    }
    double min = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

double find_max(double *data, int count) {
    if (count == 0) {
        return 0.0; // Or some other reasonable default, like negative infinity
    }
    double max = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <csv_file_path> <column_number>\n", argv[0]);
        return 1;
    }

    const char *csv_file_path = argv[1];
    int column_number = atoi(argv[2]);

    if (column_number <= 0) {
        fprintf(stderr, "Error: Column number must be a positive integer.\n");
        return 1;
    }

    FILE *fp = fopen(csv_file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    double values[MAX_LINE_LENGTH]; // Assume no more than MAX_LINE_LENGTH rows
    int value_count = 0;

    // Skip header line
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) { // Consume header
      if (feof(fp)) {
        fprintf(stderr, "Error: File is empty or contains only a header.\n");
        fclose(fp);
        return 1;
      } else {
        perror("Error reading header line");
        fclose(fp);
        return 1;
      }
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token;
        char *rest = line;
        int current_column = 1;

        while ((token = strsep(&rest, ",")) != NULL) {
            // Remove leading/trailing whitespace
            while (isspace((unsigned char)*token)) token++;
            size_t len = strlen(token);
            while (len > 0 && isspace((unsigned char)token[len - 1])) token[--len] = 0;

            if (current_column == column_number) {
                char *endptr;
                double value = strtod(token, &endptr);
                if (*endptr == '\0' || isspace((unsigned char)*endptr)) {
                    values[value_count++] = value;
                } else {
                   // Treat non-numeric as 0
                   values[value_count++] = 0.0;
                }
                break; // Found the column, move to the next line
            }
            current_column++;
        }
    }

    fclose(fp);

    if (value_count == 0) {
        fprintf(stderr, "Error: No data found in the specified column.\n");
        return 1;
    }

    double mean = calculate_mean(values, value_count);
    double min = find_min(values, value_count);
    double max = find_max(values, value_count);

    printf("Mean: %f\n", mean);
    printf("Min: %f\n", min);
    printf("Max: %f\n", max);

    return 0;
}

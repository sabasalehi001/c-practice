#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert kilometers to miles
double km_to_mi(double km) {
    return km * 0.621371;
}

// Function to convert miles to kilometers
double mi_to_km(double mi) {
    return mi * 1.60934;
}

// Function to convert Celsius to Fahrenheit
double c_to_f(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double f_to_c(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <conversion_type> <value>\n", argv[0]);
        fprintf(stderr, "Supported conversion types: km_to_mi, mi_to_km, c_to_f, f_to_c\n");
        return 1;
    }

    char *conversion_type = argv[1];
    char *value_str = argv[2];

    // Validate input
    for (int i = 0; value_str[i] != '\0'; i++) {
        if (!isdigit(value_str[i]) && value_str[i] != '.' && value_str[i] != '-') {
            fprintf(stderr, "Error: Invalid value '%s'. Must be a number.\n", value_str);
            return 1;
        }
    }

    double value = atof(value_str);

    if (strcmp(conversion_type, "km_to_mi") == 0) {
        printf("%.2f km = %.2f mi\n", value, km_to_mi(value));
    } else if (strcmp(conversion_type, "mi_to_km") == 0) {
        printf("%.2f mi = %.2f km\n", value, mi_to_km(value));
    } else if (strcmp(conversion_type, "c_to_f") == 0) {
        printf("%.2f C = %.2f F\n", value, c_to_f(value));
    } else if (strcmp(conversion_type, "f_to_c") == 0) {
        printf("%.2f F = %.2f C\n", value, f_to_c(value));
    } else {
        fprintf(stderr, "Error: Invalid conversion type '%s'\n", conversion_type);
        fprintf(stderr, "Supported conversion types: km_to_mi, mi_to_km, c_to_f, f_to_c\n");
        return 1;
    }

    return 0;
}

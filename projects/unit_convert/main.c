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
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <unit_from> <unit_to>\n", argv[0]);
        return 1;
    }

    double value = atof(argv[1]);
    char *unit_from = argv[2];
    char *unit_to = argv[3];

    double result;

    if (strcmp(unit_from, "km") == 0 && strcmp(unit_to, "mi") == 0) {
        result = km_to_mi(value);
        printf("%.2f km = %.2f mi\n", value, result);
    } else if (strcmp(unit_from, "mi") == 0 && strcmp(unit_to, "km") == 0) {
        result = mi_to_km(value);
        printf("%.2f mi = %.2f km\n", value, result);
    } else if (strcmp(unit_from, "C") == 0 && strcmp(unit_to, "F") == 0) {
        result = celsius_to_fahrenheit(value);
        printf("%.2f C = %.2f F\n", value, result);
    } else if (strcmp(unit_from, "F") == 0 && strcmp(unit_to, "C") == 0) {
        result = fahrenheit_to_celsius(value);
        printf("%.2f F = %.2f C\n", value, result);
    } else {
        fprintf(stderr, "Unsupported conversion: %s to %s\n", unit_from, unit_to);
        return 1;
    }

    return 0;
}

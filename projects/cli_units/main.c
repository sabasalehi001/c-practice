#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <conversion_type> <value>\n", argv[0]);
        return 1;
    }

    char *conversion_type = argv[1];
    double value = atof(argv[2]);

    if (strcmp(conversion_type, "km_to_mi") == 0) {
        double miles = value * 0.621371;
        printf("%.2f km is equal to %.2f mi\n", value, miles);
    } else if (strcmp(conversion_type, "mi_to_km") == 0) {
        double kilometers = value * 1.60934;
        printf("%.2f mi is equal to %.2f km\n", value, kilometers);
    } else if (strcmp(conversion_type, "C_to_F") == 0) {
        double fahrenheit = (value * 9.0 / 5.0) + 32.0;
        printf("%.2f C is equal to %.2f F\n", value, fahrenheit);
    } else if (strcmp(conversion_type, "F_to_C") == 0) {
        double celsius = (value - 32.0) * 5.0 / 9.0;
        printf("%.2f F is equal to %.2f C\n", value, celsius);
    } else {
        fprintf(stderr, "Invalid conversion type: %s\n", conversion_type);
        return 1;
    }

    return 0;
}
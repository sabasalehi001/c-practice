#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Base64 encoding table
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a string to base64
char* base64_encode(const char* data, size_t input_length) {
    size_t output_length = 4 * ((input_length + 2) / 3); // Calculate output length
    char* encoded_data = (char*)malloc(output_length + 1); // Allocate memory

    if (encoded_data == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = base64_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 0 * 6) & 0x3F];
    }

    // Handle padding
    for (size_t i = 0; i < (3 - input_length % 3) % 3; i++) {
        encoded_data[output_length - 1 - i] = '=';
    }

    encoded_data[output_length] = '\0';
    return encoded_data;
}

// Function to decode a base64 string
char* base64_decode(const char* data, size_t input_length) {
    if (input_length % 4 != 0) {
        fprintf(stderr, "Invalid base64 input length\n");
        return NULL;
    }

    size_t padding = 0;
    if (input_length > 0 && data[input_length - 1] == '=') {
        padding++;
    }
    if (input_length > 1 && data[input_length - 2] == '=') {
        padding++;
    }

    size_t output_length = (input_length * 3) / 4 - padding;
    char* decoded_data = (char*)malloc(output_length + 1);
    if (decoded_data == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < input_length;) {
        int char1 = data[i++];
        int char2 = data[i++];
        int char3 = data[i++];
        int char4 = data[i++];

        int val1 = (char1 >= 'A' && char1 <= 'Z') ? char1 - 'A' :
                   (char1 >= 'a' && char1 <= 'z') ? char1 - 'a' + 26 :
                   (char1 >= '0' && char1 <= '9') ? char1 - '0' + 52 :
                   (char1 == '+') ? 62 :
                   (char1 == '/') ? 63 : -1;
        int val2 = (char2 >= 'A' && char2 <= 'Z') ? char2 - 'A' :
                   (char2 >= 'a' && char2 <= 'z') ? char2 - 'a' + 26 :
                   (char2 >= '0' && char2 <= '9') ? char2 - '0' + 52 :
                   (char2 == '+') ? 62 :
                   (char2 == '/') ? 63 : -1;
        int val3 = (char3 >= 'A' && char3 <= 'Z') ? char3 - 'A' :
                   (char3 >= 'a' && char3 <= 'z') ? char3 - 'a' + 26 :
                   (char3 >= '0' && char3 <= '9') ? char3 - '0' + 52 :
                   (char3 == '+') ? 62 :
                   (char3 == '/') ? 63 :
                   (char3 == '=') ? 0 : -1;
        int val4 = (char4 >= 'A' && char4 <= 'Z') ? char4 - 'A' :
                   (char4 >= 'a' && char4 <= 'z') ? char4 - 'a' + 26 :
                   (char4 >= '0' && char4 <= '9') ? char4 - '0' + 52 :
                   (char4 == '+') ? 62 :
                   (char4 == '/') ? 63 :
                   (char4 == '=') ? 0 : -1;

        if (val1 == -1 || val2 == -1 || val3 == -1 || val4 == -1) {
            fprintf(stderr, "Invalid base64 character\n");
            free(decoded_data);
            return NULL;
        }

        decoded_data[j++] = (char)((val1 << 2) | (val2 >> 4));
        if (j < output_length) {
            decoded_data[j++] = (char)((val2 << 4) | (val3 >> 2));
        }
        if (j < output_length) {
            decoded_data[j++] = (char)((val3 << 6) | val4);
        }
    }

    decoded_data[output_length] = '\0';
    return decoded_data;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -e|-d <string>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        char* encoded = base64_encode(argv[2], strlen(argv[2]));
        if (encoded) {
            printf("%s\n", encoded);
            free(encoded);
        }
    } else if (strcmp(argv[1], "-d") == 0) {
        char* decoded = base64_decode(argv[2], strlen(argv[2]));
        if (decoded) {
            printf("%s\n", decoded);
            free(decoded);
        }
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        fprintf(stderr, "Usage: %s -e|-d <string>\n", argv[0]);
        return 1;
    }

    return 0;
}
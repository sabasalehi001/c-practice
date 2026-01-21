#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Base64 character set
static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a string to base64
char* base64_encode(const char* input) {
    size_t input_length = strlen(input);
    size_t output_length = 4 * ((input_length + 2) / 3);
    char* output = (char*)malloc(output_length + 1);
    if (output == NULL) {
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? (unsigned char)input[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)input[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)input[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        output[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        output[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        output[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        output[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }

    // Replace padding characters
    for (size_t k = 0; k < (3 - input_length % 3) % 3; k++) {
        output[output_length - 1 - k] = '=';
    }

    output[output_length] = '\0';
    return output;
}

// Function to decode a base64 string
char* base64_decode(const char* input) {
    size_t input_length = strlen(input);
    if (input_length % 4 != 0) {
        return NULL; // Invalid base64 string
    }

    size_t output_length = input_length / 4 * 3;
    if (input[input_length - 1] == '=') {
        output_length--;
    }
    if (input[input_length - 2] == '=') {
        output_length--;
    }

    char* output = (char*)malloc(output_length + 1);
    if (output == NULL) {
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_length;) {
        int char1 = input[i++];
        int char2 = input[i++];
        int char3 = input[i++];
        int char4 = input[i++];

        int val1 = (char1 >= 'A' && char1 <= 'Z') ? char1 - 'A' : ((char1 >= 'a' && char1 <= 'z') ? char1 - 'a' + 26 : ((char1 >= '0' && char1 <= '9') ? char1 - '0' + 52 : (char1 == '+' ? 62 : (char1 == '/' ? 63 : -1))));
        int val2 = (char2 >= 'A' && char2 <= 'Z') ? char2 - 'A' : ((char2 >= 'a' && char2 <= 'z') ? char2 - 'a' + 26 : ((char2 >= '0' && char2 <= '9') ? char2 - '0' + 52 : (char2 == '+' ? 62 : (char2 == '/' ? 63 : -1))));
        int val3 = (char3 >= 'A' && char3 <= 'Z') ? char3 - 'A' : ((char3 >= 'a' && char3 <= 'z') ? char3 - 'a' + 26 : ((char3 >= '0' && char3 <= '9') ? char3 - '0' + 52 : (char3 == '+' ? 62 : (char3 == '/' ? 63 : (char3 == '=' ? 0 : -1)))));
        int val4 = (char4 >= 'A' && char4 <= 'Z') ? char4 - 'A' : ((char4 >= 'a' && char4 <= 'z') ? char4 - 'a' + 26 : ((char4 >= '0' && char4 <= '9') ? char4 - '0' + 52 : (char4 == '+' ? 62 : (char4 == '/' ? 63 : (char4 == '=' ? 0 : -1)))));

        if (val1 == -1 || val2 == -1 || val3 == -1 || val4 == -1) {
            free(output);
            return NULL;
        }

        output[j++] = (char)((val1 << 2) | (val2 >> 4));
        if (val3 != 0) {
            output[j++] = (char)((val2 << 4) | (val3 >> 2));
        }
        if (val4 != 0) {
            output[j++] = (char)((val3 << 6) | val4);
        }
    }

    output[output_length] = '\0';
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -e <string> | -d <base64_string>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        char* encoded = base64_encode(argv[2]);
        if (encoded != NULL) {
            printf("%s\n", encoded);
            free(encoded);
        } else {
            fprintf(stderr, "Encoding failed.\n");
            return 1;
        }
    } else if (strcmp(argv[1], "-d") == 0) {
        char* decoded = base64_decode(argv[2]);
        if (decoded != NULL) {
            printf("%s\n", decoded);
            free(decoded);
        } else {
            fprintf(stderr, "Decoding failed. Invalid base64 string.\n");
            return 1;
        }
    } else {
        fprintf(stderr, "Invalid option. Use -e for encode or -d for decode.\n");
        return 1;
    }

    return 0;
}
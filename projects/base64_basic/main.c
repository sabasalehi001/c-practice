#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Base64 character table
static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a string to Base64
char* base64_encode(const char* data, size_t input_length) {
    size_t output_length = 4 * ((input_length + 2) / 3);

    char* encoded_data = (char*)malloc(output_length + 1);
    if (encoded_data == NULL) {
        return NULL;
    }

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < (3 - input_length % 3) % 3; i++) {
        encoded_data[output_length - 1 - i] = '=';
    }

    encoded_data[output_length] = '\0';

    return encoded_data;
}

// Function to decode a Base64 string
char* base64_decode(const char* data, size_t input_length) {
    if (input_length % 4 != 0) {
        return NULL; // Invalid Base64 length
    }

    size_t padding = 0;
    if (input_length > 0 && data[input_length - 1] == '=') padding++;
    if (input_length > 1 && data[input_length - 2] == '=') padding++;

    size_t output_length = (input_length * 3) / 4 - padding;

    char* decoded_data = (char*)malloc(output_length + 1);
    if (decoded_data == NULL) {
        return NULL;
    }

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t char_a = data[i] == '=' ? 0 & i++ : strchr(base64_chars, data[i]) - base64_chars, i++;
        uint32_t char_b = data[i] == '=' ? 0 & i++ : strchr(base64_chars, data[i]) - base64_chars, i++;
        uint32_t char_c = data[i] == '=' ? 0 & i++ : strchr(base64_chars, data[i]) - base64_chars, i++;
        uint32_t char_d = data[i] == '=' ? 0 & i++ : strchr(base64_chars, data[i]) - base64_chars, i++;

        uint32_t triple = (char_a << 3 * 6) + (char_b << 2 * 6) + (char_c << 1 * 6) + (char_d << 0 * 6);

        if(j < output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
        if(j < output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
        if(j < output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
    }

    decoded_data[output_length] = '\0';

    return decoded_data;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <encode|decode> <string>\n", argv[0]);
        return 1;
    }

    const char* operation = argv[1];
    const char* input_string = argv[2];

    if (strcmp(operation, "encode") == 0) {
        char* encoded_string = base64_encode(input_string, strlen(input_string));
        if (encoded_string == NULL) {
            fprintf(stderr, "Encoding failed\n");
            return 1;
        }
        printf("%s\n", encoded_string);
        free(encoded_string);
    } else if (strcmp(operation, "decode") == 0) {
        char* decoded_string = base64_decode(input_string, strlen(input_string));
        if (decoded_string == NULL) {
            fprintf(stderr, "Decoding failed\n");
            return 1;
        }
        printf("%s\n", decoded_string);
        free(decoded_string);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}

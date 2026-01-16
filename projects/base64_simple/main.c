#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Base64 character set
const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a string to Base64
char* base64_encode(const char* data, int data_len) {
    int encoded_len = 4 * ((data_len + 2) / 3); // Calculate encoded length
    char* encoded_data = (char*)malloc(encoded_len + 1); // Allocate memory for encoded data
    if (encoded_data == NULL) {
        return NULL; // Allocation failed
    }

    int i, j;
    for (i = 0, j = 0; i < data_len;) {
        unsigned char input[3] = {0, 0, 0};
        unsigned char output[4] = {0, 0, 0, 0};

        int remaining = data_len - i;
        if (remaining >= 3) {
            input[0] = data[i++];
            input[1] = data[i++];
            input[2] = data[i++];
        } else if (remaining == 2) {
            input[0] = data[i++];
            input[1] = data[i++];
        } else {
            input[0] = data[i++];
        }

        output[0] = (input[0] & 0xFC) >> 2;
        output[1] = ((input[0] & 0x03) << 4) | ((input[1] & 0xF0) >> 4);
        output[2] = ((input[1] & 0x0F) << 2) | ((input[2] & 0xC0) >> 6);
        output[3] = input[2] & 0x3F;

        encoded_data[j++] = base64_chars[output[0]];
        encoded_data[j++] = base64_chars[output[1]];
        if (remaining > 1) {
            encoded_data[j++] = base64_chars[output[2]];
        } else {
            encoded_data[j++] = '=';
        }
        if (remaining > 2) {
            encoded_data[j++] = base64_chars[output[3]];
        } else {
            encoded_data[j++] = '=';
        }
    }

    encoded_data[encoded_len] = '\0'; // Null-terminate the encoded string
    return encoded_data;
}

// Function to decode a Base64 string
char* base64_decode(const char* data, int data_len) {
    int padding = 0;
    if (data_len > 0 && data[data_len - 1] == '=') {
        padding++;
        if (data_len > 1 && data[data_len - 2] == '=') {
            padding++;
        }
    }

    int decoded_len = (data_len * 3) / 4 - padding;
    char* decoded_data = (char*)malloc(decoded_len + 1);
    if (decoded_data == NULL) {
        return NULL; // Allocation failed
    }

    int i, j;
    unsigned char char_array[4];
    for (i = 0, j = 0; i < data_len;) {
        int k = 0;
        while (i < data_len && k < 4) {
            if (isalnum(data[i]) || data[i] == '+' || data[i] == '/') {
                char_array[k++] = data[i];
            }
            i++;
        }

        if (k != 4) {
           break; // Invalid input, stop decoding
        }

        unsigned char val0 = strchr(base64_chars, char_array[0]) - base64_chars;
        unsigned char val1 = strchr(base64_chars, char_array[1]) - base64_chars;
        unsigned char val2 = strchr(base64_chars, char_array[2]) - base64_chars;
        unsigned char val3 = strchr(base64_chars, char_array[3]) - base64_chars;

        decoded_data[j++] = (val0 << 2) | (val1 >> 4);
        if (char_array[2] != '=') {
            decoded_data[j++] = ((val1 << 4) & 0xF0) | (val2 >> 2);
        }
        if (char_array[3] != '=') {
            decoded_data[j++] = ((val2 << 6) & 0xC0) | val3;
        }
    }

    decoded_data[decoded_len] = '\0'; // Null-terminate the decoded string
    return decoded_data;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [encode|decode] <string>\n", argv[0]);
        return 1;
    }

    const char* operation = argv[1];
    const char* input_string = argv[2];

    if (strcmp(operation, "encode") == 0) {
        char* encoded_string = base64_encode(input_string, strlen(input_string));
        if (encoded_string != NULL) {
            printf("%s\n", encoded_string);
            free(encoded_string);
        } else {
            fprintf(stderr, "Encoding failed.\n");
            return 1;
        }
    } else if (strcmp(operation, "decode") == 0) {
        char* decoded_string = base64_decode(input_string, strlen(input_string));
        if (decoded_string != NULL) {
            printf("%s\n", decoded_string);
            free(decoded_string);
        } else {
            fprintf(stderr, "Decoding failed.\n");
            return 1;
        }
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}

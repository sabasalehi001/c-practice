#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Base64 alphabet
const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a string to base64
char* base64_encode(const char* input) {
    size_t input_len = strlen(input);
    size_t output_len = 4 * ((input_len + 2) / 3); // Calculate output length
    char* output = (char*)malloc(output_len + 1);
    if (output == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_len;) {
        unsigned int octet_a = i < input_len ? (unsigned char)input[i++] : 0;
        unsigned int octet_b = i < input_len ? (unsigned char)input[i++] : 0;
        unsigned int octet_c = i < input_len ? (unsigned char)input[i++] : 0;

        unsigned int triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        output[j++] = base64_chars[(triple >> 18) & 0x3F];
        output[j++] = base64_chars[(triple >> 12) & 0x3F];
        output[j++] = (i > input_len + 1) ? '=' : base64_chars[(triple >> 6) & 0x3F];
        output[j++] = (i > input_len) ? '=' : base64_chars[triple & 0x3F];
    }

    output[output_len] = '\0';
    return output;
}

// Function to decode a base64 string
char* base64_decode(const char* input) {
    size_t input_len = strlen(input);
    size_t output_len = input_len / 4 * 3; // Approximate output length
    char* output = (char*)malloc(output_len + 1);
    if (output == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    size_t i, j;
    unsigned char char_array_4[4], char_array_3[3];

    i = 0;
    j = 0;
    while (input_len-- && (input[i] != '=') && is_base64(input[i])) {
        char_array_4[i++] = input[i];
    }

    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 64; k++) {
            if (base64_chars[k] == char_array_4[i]) {
                char_array_4[i] = k;
                break;
            }
        }
    }

    i = 0;

    for (i = 0; i < 4; i++){
         if (!is_base64(input[i])) {
             break;
         }
    }

    i = 0;
    while (input[i]) {

        for (int k = 0; k < 4; k++) {
			int index = -1;
			for(int l = 0; l < 64; l++){
				if(base64_chars[l] == input[i]){
					index = l;
					break;
				}
			}
			if(index != -1){
                char_array_4[k] = index; 
			} else {
				char_array_4[k] = 0; // handle padding '=' characters
			}
            i++;
        }

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (int k = 0; k < 3; k++){
            output[j++] = char_array_3[k];
        }
    }

    output[j] = '\0';
    return output;
}

// Helper function to check if a character is a valid base64 character
int is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s (encode|decode) <string>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        char* encoded_string = base64_encode(argv[2]);
        if (encoded_string != NULL) {
            printf("%s\n", encoded_string);
            free(encoded_string);
        }
    } else if (strcmp(argv[1], "decode") == 0) {
        char* decoded_string = base64_decode(argv[2]);
        if (decoded_string != NULL) {
            printf("%s\n", decoded_string);
            free(decoded_string);
        }
    } else {
        fprintf(stderr, "Invalid mode: %s.  Must be 'encode' or 'decode'.\n", argv[1]);
        return 1;
    }

    return 0;
}

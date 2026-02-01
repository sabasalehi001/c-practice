#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 64
#define MAX_WORDS 1024

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    int word_index = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalnum(c)) {
            if (word_index < MAX_WORD_LENGTH - 1) {
                word[word_index++] = tolower(c);
            }
        } else {
            if (word_index > 0) {
                word[word_index] = '\0';
                word_index = 0;

                int found = 0;
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(word_frequencies[i].word, word) == 0) {
                        word_frequencies[i].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    if (num_words < MAX_WORDS) {
                        strcpy(word_frequencies[num_words].word, word);
                        word_frequencies[num_words].count = 1;
                        num_words++;
                    } else {
                        fprintf(stderr, "Warning: Maximum number of words reached.\n");
                        break;
                    }
                }
            }
        }
    }

    fclose(fp);

    // Print the word frequencies
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    return 0;
}
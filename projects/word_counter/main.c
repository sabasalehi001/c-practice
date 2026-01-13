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

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    int wordCount = 0;

    char wordBuffer[MAX_WORD_LENGTH];
    int wordIndex = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            if (wordIndex < MAX_WORD_LENGTH - 1) {
                wordBuffer[wordIndex++] = tolower(c);
            }
        } else {
            if (wordIndex > 0) {
                wordBuffer[wordIndex] = '\0';
                wordIndex = 0;

                int found = 0;
                for (int i = 0; i < wordCount; i++) {
                    if (strcmp(wordFrequencies[i].word, wordBuffer) == 0) {
                        wordFrequencies[i].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    if (wordCount < MAX_WORDS) {
                        strcpy(wordFrequencies[wordCount].word, wordBuffer);
                        wordFrequencies[wordCount].count = 1;
                        wordCount++;
                    } else {
                        fprintf(stderr, "Warning: Maximum word limit reached. Ignoring further words.\n");
                    }
                }
            }
        }
    }

    // Process the last word in the file, if any
    if (wordIndex > 0) {
        wordBuffer[wordIndex] = '\0';

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFrequencies[i].word, wordBuffer) == 0) {
                wordFrequencies[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (wordCount < MAX_WORDS) {
                strcpy(wordFrequencies[wordCount].word, wordBuffer);
                wordFrequencies[wordCount].count = 1;
                wordCount++;
            } else {
                fprintf(stderr, "Warning: Maximum word limit reached. Ignoring further words.\n");
            }
        }
    }

    fclose(file);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}
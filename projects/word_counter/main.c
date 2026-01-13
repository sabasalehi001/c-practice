#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 64
#define MAX_WORDS 1024

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

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

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%63s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Remove punctuation from the end of the word
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }

        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word doesn't exist, add it to the array
        if (!found) {
            if (num_words < MAX_WORDS) {
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            } else {
                fprintf(stderr, "Warning: Maximum number of words reached. Ignoring further words.\n");
                break;
            }
        }
    }

    fclose(fp);

    // Print the word counts
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}
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
    int word_count = 0;

    char word[MAX_WORD_LENGTH];
    int i = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalnum(c)) {
            if (i < MAX_WORD_LENGTH - 1) {
                word[i++] = tolower(c);
            }
        } else if (i > 0) {
            word[i] = '\0';
            i = 0;

            int found = 0;
            for (int j = 0; j < word_count; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    found = 1;
                    break;
                }
            }

            if (!found && word_count < MAX_WORDS) {
                strcpy(word_counts[word_count].word, word);
                word_counts[word_count].count = 1;
                word_count++;
            }
        }
    }

    if (i > 0) { // Process the last word if any
        word[i] = '\0';

        int found = 0;
        for (int j = 0; j < word_count; j++) {
            if (strcmp(word, word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < MAX_WORDS) {
            strcpy(word_counts[word_count].word, word);
            word_counts[word_count].count = 1;
            word_count++;
        }
    }

    fclose(fp);

    for (int j = 0; j < word_count; j++) {
        printf("%s: %d\n", word_counts[j].word, word_counts[j].count);
    }

    return 0;
}
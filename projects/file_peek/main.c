#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *filename, const char *dirname) {
    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s/%s", dirname, filename);

    struct stat file_stat;
    if (stat(full_path, &file_stat) == 0) {
        printf("%s  ", filename);
    } else {
        perror("stat");
    }
}

int main(int argc, char *argv[]) {
    char *dirname = ".";

    if (argc > 1) {
        dirname = argv[1];
    }

    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        print_file_info(entry->d_name, dirname);
    }
    printf("\n");
    closedir(dir);

    return 0;
}

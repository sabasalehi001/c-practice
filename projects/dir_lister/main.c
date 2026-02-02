#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    char *dirname = "."; // Default to current directory

    if (argc > 1) {
        dirname = argv[1];
    }

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
    return 0;
}
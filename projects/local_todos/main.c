#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TODO_FILE "todos.txt"
#define MAX_TASKS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char task[MAX_LINE_LENGTH];
} TodoItem;

int load_todos(TodoItem todos[], int *count) {
    FILE *fp = fopen(TODO_FILE, "r");
    if (fp == NULL) {
        return 0; // File doesn't exist or cannot be opened
    }

    *count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL && *count < MAX_TASKS) {
        // Remove trailing newline
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        strncpy(todos[*count].task, line, sizeof(todos[*count].task) - 1);
        todos[*count].task[sizeof(todos[*count].task) - 1] = '\0'; // Ensure null termination
        (*count)++;
    }

    fclose(fp);
    return 1;
}

int save_todos(TodoItem todos[], int count) {
    FILE *fp = fopen(TODO_FILE, "w");
    if (fp == NULL) {
        perror("Error opening todo file for writing");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", todos[i].task);
    }

    fclose(fp);
    return 1;
}

void add_todo(TodoItem todos[], int *count, const char *task) {
    if (*count < MAX_TASKS) {
        strncpy(todos[*count].task, task, sizeof(todos[*count].task) - 1);
        todos[*count].task[sizeof(todos[*count].task) - 1] = '\0';
        (*count)++;
        printf("Added: %s\n", task);
    } else {
        printf("Todo list is full.\n");
    }
}

void list_todos(TodoItem todos[], int count) {
    if (count == 0) {
        printf("No todos yet!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, todos[i].task);
    }
}

void remove_todo(TodoItem todos[], int *count, int index) {
    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }

    // Shift tasks after the removed one
    for (int i = index - 1; i < *count - 1; i++) {
        strncpy(todos[i].task, todos[i + 1].task, sizeof(todos[i].task) - 1);
        todos[i].task[sizeof(todos[i].task) - 1] = '\0';
    }

    (*count)--;
    printf("Removed task %d\n", index);
}

void print_help() {
    printf("Usage: ./app <command> [arguments]\n");
    printf("Commands:\n");
    printf("  add <task> - Add a new task\n");
    printf("  list - List all tasks\n");
    printf("  done <index> - Mark a task as done (remove from list)\n");
    printf("  help - Display this help message\n");
}

int main(int argc, char *argv[]) {
    TodoItem todos[MAX_TASKS];
    int count = 0;

    load_todos(todos, &count);

    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc > 2) {
            add_todo(todos, &count, argv[2]);
        } else {
            printf("Please provide a task to add.\n");
            return 1;
        }
    } else if (strcmp(argv[1], "list") == 0) {
        list_todos(todos, count);
    } else if (strcmp(argv[1], "done") == 0) {
        if (argc > 2) {
            int index = atoi(argv[2]);
            remove_todo(todos, &count, index);
        } else {
            printf("Please provide an index to remove.\n");
            return 1;
        }
    } else if (strcmp(argv[1], "help") == 0) {
        print_help();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        print_help();
        return 1;
    }

    save_todos(todos, count);

    return 0;
}

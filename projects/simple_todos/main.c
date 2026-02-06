#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256
#define FILENAME "todos.txt"

typedef struct {
    char description[MAX_TASK_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

// Function prototypes
void load_tasks();
void save_tasks();
void add_task(const char *description);
void list_tasks();
void complete_task(int index);
void remove_task(int index);
void clear_tasks();
void print_help();

int main() {
    load_tasks();

    char command[20];
    char argument[MAX_TASK_LENGTH];

    while (1) {
        printf("> ");
        scanf("%19s", command);

        if (strcmp(command, "add") == 0) {
            // Consume the remaining characters in the input buffer after "add"
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Enter task description: ");
            if (fgets(argument, sizeof(argument), stdin) != NULL) {
                // Remove trailing newline character
                argument[strcspn(argument, "\n")] = 0;
                add_task(argument);
            } else {
                printf("Error reading task description.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            list_tasks();
        } else if (strcmp(command, "complete") == 0) {
            int index;
            if (scanf("%d", &index) == 1) {
                complete_task(index - 1);
            } else {
                printf("Invalid index.\n");
                // Clear the invalid input from stdin
                while (getchar() != '\n');
            }
        } else if (strcmp(command, "remove") == 0) {
            int index;
            if (scanf("%d", &index) == 1) {
                remove_task(index - 1);
            } else {
                printf("Invalid index.\n");
                // Clear the invalid input from stdin
                while (getchar() != '\n');
            }
        } else if (strcmp(command, "clear") == 0) {
            clear_tasks();
        } else if (strcmp(command, "help") == 0) {
            print_help();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    save_tasks();
    return 0;
}

void load_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file) {
        while (fgets(tasks[task_count].description, sizeof(tasks[task_count].description), file)) {
            tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = 0; // Remove trailing newline
            fscanf(file, "%d\n", &tasks[task_count].completed);
            task_count++;
            if (task_count >= MAX_TASKS) {
                printf("Warning: Maximum number of tasks reached.\n");
                break;
            }
        }
        fclose(file);
    }
}

void save_tasks() {
    FILE *file = fopen(FILENAME, "w");
    if (file) {
        for (int i = 0; i < task_count; i++) {
            fprintf(file, "%s\n", tasks[i].description);
            fprintf(file, "%d\n", tasks[i].completed);
        }
        fclose(file);
    }
}

void add_task(const char *description) {
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].description, description, MAX_TASK_LENGTH - 1);
        tasks[task_count].description[MAX_TASK_LENGTH - 1] = 0; // Ensure null termination
        tasks[task_count].completed = 0;
        task_count++;
        printf("Task added.\n");
    } else {
        printf("Todo list is full.\n");
    }
}

void list_tasks() {
    if (task_count == 0) {
        printf("No tasks in the todo list.\n");
    } else {
        for (int i = 0; i < task_count; i++) {
            printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'x' : ' ', tasks[i].description);
        }
    }
}

void complete_task(int index) {
    if (index >= 0 && index < task_count) {
        tasks[index].completed = 1;
        printf("Task marked as complete.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void remove_task(int index) {
    if (index >= 0 && index < task_count) {
        for (int i = index; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        printf("Task removed.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void clear_tasks() {
    task_count = 0;
    printf("All tasks cleared.\n");
}

void print_help() {
    printf("Commands:\n");
    printf("  add <task>   - Adds a new task\n");
    printf("  list         - Lists all tasks\n");
    printf("  complete <index> - Marks a task as complete\n");
    printf("  remove <index> - Removes a task\n");
    printf("  clear        - Clears all tasks\n");
    printf("  help         - Displays this help message\n");
    printf("  exit         - Exits the program\n");
}
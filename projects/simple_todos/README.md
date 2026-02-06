# Simple Todo List

A simple command-line todo list application that saves tasks to a local file.

## Build

To build the application, use the following command:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

To run the application, use the following command:

```bash
./app
```

The application provides the following commands:

*   `add <task>`: Adds a new task to the todo list.
*   `list`: Lists all tasks in the todo list.
*   `complete <index>`: Marks a task as complete.
*   `remove <index>`: Removes a task from the todo list.
*   `help`: Displays the help message.
*   `clear`: Clears all tasks from the todo list.
*   `exit`: Exits the application.

## Example

```
./app
> add Buy groceries
Task added.
> add Walk the dog
Task added.
> list
1. [ ] Buy groceries
2. [ ] Walk the dog
> complete 1
Task marked as complete.
> list
1. [x] Buy groceries
2. [ ] Walk the dog
> remove 2
Task removed.
> list
1. [x] Buy groceries
> exit
```
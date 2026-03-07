# Local Todos

A simple command-line todo list application that saves tasks to a local file.

## Build

To build the application, run:

```bash
make
```

This will create an executable file named `app`.

## Run

To run the application, execute:

```bash
./app
```

## Usage

The application provides the following commands:

*   `add <task>`: Adds a new task to the todo list.
*   `list`: Lists all tasks in the todo list.
*   `done <index>`: Marks a task as done (removes it from the list).
*   `help`: Displays a help message.

## Example

```bash
./app add "Buy groceries"
./app add "Walk the dog"
./app list
./app done 1
./app list
```

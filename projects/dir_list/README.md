# Directory Lister (dir_list)

This is a simple C program that lists the files and directories within a specified directory, similar to a basic `ls` command.

## Build

To build the program, use the provided Makefile:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

To run the program, execute the compiled binary. You can optionally provide a directory path as a command-line argument. If no directory is provided, it will list the contents of the current directory.

```bash
./app [directory_path]
```

**Example:**

To list the files in the current directory:

```bash
./app
```

To list the files in the `/tmp` directory:

```bash
./app /tmp
```
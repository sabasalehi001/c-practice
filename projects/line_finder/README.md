# Line Finder

A simple command-line tool to search for lines containing a specific substring within a file.

## Build

To build the application, use the following command:

```bash
make
```

This will compile the `main.c` source file and create an executable named `app`.

## Run

To run the application, use the following command:

```bash
./app <substring> <filename>
```

where:

*   `<substring>` is the string you want to search for.
*   `<filename>` is the name of the file you want to search in.

**Example:**

To search for the word "example" in the file `input.txt`, run:

```bash
./app example input.txt
```

This will print all lines from `input.txt` that contain the word "example".

# Simple Search

A simple command-line tool that searches for lines containing a specified substring within a file.

## Build

To build the project, use the following command:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

To run the program, use the following command:

```bash
./app <substring> <filename>
```

Where:

*   `<substring>` is the string you want to search for.
*   `<filename>` is the name of the file you want to search in.

## Example

To search for the word "example" in the file `test.txt`, you would use the following command:

```bash
./app example test.txt
```

This will print all lines in `test.txt` that contain the word "example".

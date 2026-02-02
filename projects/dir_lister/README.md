# Directory Lister (dir_lister)

This is a simple C program that lists the files and directories in a specified directory, similar to the `ls` command.

## Build

To build the program, use the provided Makefile:

```bash
make
```

This will create an executable named `app`.

## Run

To run the program, provide a directory as a command-line argument:

```bash
./app <directory>
```

If no directory is specified, it will list the current directory.

### Example

To list the files in the `/tmp` directory:

```bash
./app /tmp
```

This will print a list of files and directories within `/tmp` to standard output.

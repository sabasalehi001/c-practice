# hex_printer

A simple command-line tool to display the contents of a file in hexadecimal and ASCII format.

## Build

```bash
make
```

This will compile the `main.c` file into an executable named `app`.

## Run

```bash
./app <filename>
```

Replace `<filename>` with the name of the file you want to view.

## Example

Let's say you have a file named `test.txt` with the following content:

```
Hello, world!
This is a test file.
```

Running the command:

```bash
./app test.txt
```

Will produce output similar to:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a 54 68  Hello, world!.Th
00000010: 69 73 20 69 73 20 61 20 74 65 73 74 20 66 69 6c  is is a test fil
00000020: 65 2e 0a                                          e..
```

# Hex Dump

A simple hex viewer that prints file bytes as hexadecimal and ASCII.

## Build

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

```bash
./app <filename>
```

Replace `<filename>` with the path to the file you want to view.

## Example

If you have a file named `test.txt` with the content "Hello, world!\n", running the program will produce output similar to this:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a  Hello, world!.
```
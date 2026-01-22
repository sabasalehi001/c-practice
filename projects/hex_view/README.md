# Hex Viewer

This is a simple hex viewer program written in C. It takes a file as input and prints its contents to the console, displaying each byte in hexadecimal format along with its ASCII representation (if printable).

## Build

To build the program, use the provided `Makefile`:

```bash
make
```

This will create an executable file named `app`.

## Run

To run the program, provide the file you want to view as a command-line argument:

```bash
./app <filename>
```

For example, to view the contents of a file named `test.txt`, you would run:

```bash
./app test.txt
```

## Example

If `test.txt` contains the string "Hello, world!\n", the output would look something like this:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a  Hello, world!.
```
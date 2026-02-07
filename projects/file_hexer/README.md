# File Hexer

A simple command-line tool to display the contents of a file in hexadecimal and ASCII format.

## Build

```bash
make
```

## Run

```bash
./app input.txt
```

Replace `input.txt` with the name of the file you want to view.

## Example

If `input.txt` contains the string "Hello, world!\n", the output will be similar to:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a       Hello, world!.
```

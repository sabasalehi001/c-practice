# File Viewer

A simple command-line tool to view the contents of a file in hexadecimal and ASCII format.

## Build

```bash
make
```

## Run

```bash
./app <filename>
```

Example:

```bash
echo "Hello, world!" > test.txt
./app test.txt
```

Output (example):

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a          Hello, world!.
```
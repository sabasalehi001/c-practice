# hex_show

A simple hex viewer that prints file bytes as hex and ASCII.

## Build

```bash
make
```

## Run

```bash
./app input.txt
```

Replace `input.txt` with the path to the file you want to view.  If no file is specified, it attempts to read from stdin.

For example, if `input.txt` contains the text "Hello, world!\n", the output will be similar to:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a           Hello, world!.
```

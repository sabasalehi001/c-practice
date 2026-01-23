# hex_peek

A simple hex viewer that prints the contents of a file in hexadecimal and ASCII.

## Build

```bash
make
```

## Run

```bash
./app <filename>
```

For example, to view the contents of `test.txt`:

```bash
echo "Hello, world!" > test.txt
./app test.txt
```

This will output something like:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a       Hello, world!.
```
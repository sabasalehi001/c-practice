# Mini Grep

A simple implementation of grep in C.

## Build

```bash
make
```

## Run

```bash
./app <search_string> <file>
```

For example, to search for the word "hello" in the file "test.txt":

```bash
./app hello test.txt
```

This will print all lines in `test.txt` that contain the string "hello".
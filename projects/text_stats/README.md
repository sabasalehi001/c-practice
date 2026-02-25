# Text Statistics

A simple command-line tool to count word frequencies in a text file.

## Build

```bash
make
```

## Run

```bash
./app input.txt
```

This will print the word frequencies to standard output.

## Example

Create a file named `input.txt` with the following content:

```
This is a test.
This is another test.
```

Run the program:

```bash
./app input.txt
```

Expected output (order may vary):

```
this: 2
is: 2
a: 1
test: 2
another: 1
```
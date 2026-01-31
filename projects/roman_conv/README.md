# Roman Numeral Converter

A simple C program that converts integers to Roman numerals.

## Build

To build the program, use the provided `Makefile`:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

To run the program, execute the compiled binary:

```bash
./app <integer>
```

Replace `<integer>` with the integer you want to convert to a Roman numeral. The integer must be between 1 and 3999 inclusive.

## Example

```bash
./app 1984
```

This will output:

```
MCMLXXXIV
```

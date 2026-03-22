# Password Strength Checker

This simple C program checks the strength of a password based on its length and the character classes it contains (uppercase, lowercase, digits, and symbols).

## Build

To build the program, run:

```bash
make
```

This will create an executable named `app`.

## Run

To run the program, execute:

```bash
./app <password>
```

Replace `<password>` with the password you want to check.

## Example

```bash
./app MyP@sswOrd123
```

The program will output a strength score (0-100) indicating the password's strength.

# Password Strength Checker

This simple C program checks the strength of a password based on its length and the character classes it contains (uppercase letters, lowercase letters, digits, and special characters).

## Build

To build the program, use the provided `Makefile`:

```bash
make
```

This will create an executable file named `app`.

## Run

To run the program, execute the `app` file:

```bash
./app
```

The program will prompt you to enter a password.  After you enter the password, it will display a strength rating.

## Example

```
./app
Enter password: P@sswOrd123
Password strength: Strong
```
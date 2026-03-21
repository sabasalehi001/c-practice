# Strong Password Checker

This simple C program checks the strength of a password based on its length and the character classes it contains (uppercase, lowercase, digits, and symbols).

## Building

To build the program, use the provided Makefile:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Running

To run the program, execute the `app` executable:

```bash
./app
```

The program will prompt you to enter a password.  After you enter the password, it will print a strength rating (Weak, Moderate, Strong) based on the following criteria:

*   **Weak:** Less than 8 characters, or only contains one character class.
*   **Moderate:** 8-12 characters, and contains at least two character classes.
*   **Strong:** More than 12 characters, and contains at least three character classes.

## Example

```
./app
Enter password: P@sswOrd123
Password strength: Strong
```

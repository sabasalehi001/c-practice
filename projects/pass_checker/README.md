# Password Strength Checker

This is a simple command-line tool to check the strength of a password based on its length and the character classes it contains (lowercase, uppercase, digits, and special characters).

## Build

To build the program, use the following command:

```bash
make
```

This will create an executable file named `app`.

## Run

To run the program, use the following command:

```bash
./app <password>
```

where `<password>` is the password you want to check.

## Example

```bash
./app MyP@sswOrd123
```

This will output a score (0-100) representing the password strength and a textual description.

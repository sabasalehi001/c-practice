# Password Strength Checker

This simple C program checks the strength of a password based on its length and the character classes it contains (uppercase, lowercase, digits, and special characters).

## Building

To build the program, use the provided `Makefile`:

```bash
make
```

This will create an executable file named `app`.

## Running

To run the program, execute the `app` file and provide the password as a command-line argument:

```bash
./app "MyP@sswOrd123"
```

## Example Output

For the password "MyP@sswOrd123", the output might be:

```
Password strength: Strong
```

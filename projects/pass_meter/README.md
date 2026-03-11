# Password Strength Meter

This simple C program checks the strength of a password based on its length and the character classes it contains (uppercase, lowercase, digits, and special characters).

## Build

```bash
make
```

## Run

```bash
./app <password>
```

For example:

```bash
./app P@sswOrd123
```

This will output a strength score (0-100) and a textual rating.

## Strength Levels

*   0-25: Very Weak
*   26-50: Weak
*   51-75: Medium
*   76-99: Strong
*   100: Very Strong

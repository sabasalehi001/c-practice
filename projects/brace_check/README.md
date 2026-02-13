# Brace Check

A simple validator for a tiny subset of JSON-like syntax, checking for balanced braces and properly quoted strings.

## Build

```bash
make
```

## Run

```bash
./app '{"key": "value"}'
```

This will output:

```
Valid
```

Example of invalid input:
```bash
./app '{"key": "value"' 
```

This will output:
```
Invalid
```
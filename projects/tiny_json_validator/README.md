# Tiny JSON Validator

This project implements a simple JSON-like validator that checks for properly balanced braces and quotes in a string.

## Build

```bash
make
```

## Run

```bash
./app "{\"name\": \"value\"}"
./app "{\"name\": value}" # Invalid: missing quotes around value
./app "{\"name\": \"value\"" # Invalid: unclosed brace
```

## Example

```bash
./app "{\"key\": \"value\", \"number\": 123}"
```
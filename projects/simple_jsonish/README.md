# Simple JSONish Validator

This project provides a simple validator for a tiny subset of JSON, focusing on correctly matched braces and quoted strings.

## Build

```bash
make
```

## Run

```bash
./app '{"key": "value"}'
```

This will output "Valid JSONish" if the input is considered valid based on the simple rules.  Otherwise, it will print "Invalid JSONish".

Another example:

```bash
./app '{ "key": "value", "another": 123 }'
```

Valid.

```bash
./app '{ "key": "value", "another": "'123'" }'
```

Invalid (single quotes not supported).

# Base64 Simple Encoder/Decoder

This is a simple command-line tool for encoding and decoding strings using Base64. It's designed for small inputs and educational purposes.

## Build

To build the application, run:

```bash
make
```

This will create an executable file named `app`.

## Usage

```bash
./app encode "Hello, world!"
./app decode "SGVsbG8sIHdvcmxkIQ=="
```

## Example

Encoding the string "test" to Base64:

```bash
./app encode "test"
```

Output:

```
dGVzdA==
```

Decoding the Base64 string "dGVzdA==":

```bash
./app decode "dGVzdA=="
```

Output:

```
test
```
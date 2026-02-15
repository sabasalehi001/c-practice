# Base64 Basic Encoder/Decoder

A simple command-line tool for encoding and decoding strings using Base64.

## Build

```bash
make
```

## Run

To encode a string:

```bash
./app encode "Hello, world!"
```

To decode a Base64 string:

```bash
./app decode "SGVsbG8sIHdvcmxkIQ=="
```

## Example

```bash
./app encode "This is a test"
# Output: VGhpcyBpcyBhIHRlc3Q=

./app decode "VGhpcyBpcyBhIHRlc3Q="
# Output: This is a test
```
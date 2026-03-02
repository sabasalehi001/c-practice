# Base64 Encoder/Decoder (Small Inputs)

This is a simple command-line tool for encoding and decoding base64 strings. It's designed for small inputs and meant as a beginner-friendly C project.

## Building

To build the project, use the following command:

```bash
make
```

This will create an executable named `app`.

## Running

To encode a string:

```bash
./app -e "Hello, World!"
```

This will output the base64 encoded string.

To decode a string:

```bash
./app -d "SGVsbG8sIFdvcmxkIQ=="
```

This will output the decoded string.

## Example

Encoding the string "test":

```bash
./app -e "test"
```

Output:

```
dGVzdA==
```
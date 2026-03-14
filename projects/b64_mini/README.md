# b64_mini

A simple base64 encoder/decoder for small inputs.

## Build

```bash
make
```

## Run

```bash
./app encode "Hello, world!"
./app decode "SGVsbG8sIHdvcmxkIQ=="
```

## Example

Encoding "Hello, world!" results in "SGVsbG8sIHdvcmxkIQ==".
Decoding "SGVsbG8sIHdvcmxkIQ==" results in "Hello, world!".

# Base64 Encoder/Decoder

This is a simple base64 encoder and decoder for small inputs.

## Build

```bash
make
```

## Run

**Encode:**
```bash
./app -e "Hello, World!"
```
Output:
```
HZWxsbywgV29ybGQh
```

**Decode:**
```bash
./app -d "HZWxsbywgV29ybGQh"
```
Output:
```
Hello, World!
```
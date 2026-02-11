# text_seeker

A simple command-line tool that searches for lines containing a specified substring within a file.

## Build

```bash
make
```

## Run

```bash
./app <substring> <filename>
```

For example, to find all lines containing the word "hello" in the file "input.txt":

```bash
./app hello input.txt
```

## Example input.txt

```
This is a line.
This line contains hello.
Another line here.
hello world!
```

## Example Output

```
This line contains hello.
hello world!
```
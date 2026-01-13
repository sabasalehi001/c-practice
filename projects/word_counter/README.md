# Word Counter

This simple C program reads a text file and counts the frequency of each word.

## Build

To build the program, use the provided Makefile:

```bash
make
```

This will create an executable named `app`.

## Run

To run the program, provide the path to the text file as a command-line argument:

```bash
./app input.txt
```

Replace `input.txt` with the actual path to your file.

## Example

If `input.txt` contains:

```
The quick brown fox jumps over the lazy fox.
```

Then running `./app input.txt` might produce the following output:

```
the: 2
quick: 1
brown: 1
fox: 2
jumps: 1
over: 1
lazy: 1
```

(Note: the exact output order may vary.)
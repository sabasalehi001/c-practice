# Word Counter

This project is a simple word frequency counter that reads a text file and outputs the frequency of each word.

## Build

To build the project, you need to have `gcc` and `make` installed.

1.  Clone the repository.
2.  Navigate to the project directory.
3.  Run `make`.

This will create an executable file named `app`.

## Run

To run the program, use the following command:

```bash
./app <input_file>
```

where `<input_file>` is the path to the text file you want to analyze.

## Example

Let's say you have a file named `example.txt` with the following content:

```text
This is a simple example. This example is simple.
```

Running the command:

```bash
./app example.txt
```

Will produce output similar to:

```text
this: 2
is: 2
a: 1
simple: 2
example: 2
```
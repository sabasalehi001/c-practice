# CSV Statistics Tool

This simple C program calculates basic statistics (mean, min, max) for a specified numeric column in a CSV file.

## Build

To build the program, use the provided `Makefile`:

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

To run the program, provide the CSV file path and the column number (starting from 1) as command-line arguments:

```bash
./app <csv_file_path> <column_number>
```

For example, if you have a CSV file named `data.csv` and you want to calculate statistics for the second column:

```bash
./app data.csv 2
```

## Example CSV (`data.csv`)

```csv
Name,Age,City
Alice,30,New York
Bob,25,London
Charlie,35,Paris
David,28,Tokyo
```

Running `./app data.csv 2` will output:

```
Mean: 29.500000
Min: 25.000000
Max: 35.000000
```

## Notes

*   The program assumes the first line of the CSV file is a header row and skips it.
*   The program expects the column to contain only numeric values. Non-numeric values will be treated as 0.
*   Error handling is basic.  Invalid input or file errors may cause unexpected behavior.

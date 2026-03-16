# Basic CSV Statistics

This project calculates the mean, minimum, and maximum of a specified numeric column in a CSV file.

## Build

```bash
make
```

This will compile the `main.c` file into an executable named `app`.

## Run

```bash
./app <csv_file> <column_index>
```

*   `<csv_file>`: The path to the CSV file.
*   `<column_index>`: The index of the numeric column to analyze (0-based).

## Example

Consider a CSV file named `data.csv` with the following content:

```csv
Name,Age,Salary
Alice,30,50000
Bob,25,60000
Charlie,35,70000
```

To calculate statistics for the `Salary` column (index 2), run:

```bash
./app data.csv 2
```

The program will output the mean, minimum, and maximum salary values to the console in JSON format.

# col_stats

A simple C program to calculate statistics (mean, min, max) for a numeric column in a CSV file.

## Build

```bash
make
```

## Run

```bash
./app data.csv 1
```

This will process `data.csv` and calculate statistics for the column at index 1 (0-based).

## Example `data.csv`

```csv
Name,Age,Salary
John,30,50000
Jane,25,60000
Peter,40,75000
Mary,35,55000
```

Running the program with `./app data.csv 2` would output the mean, min, and max of the `Salary` column.

# Log Level Counter

This simple C program analyzes a log file and counts the occurrences of different log levels (INFO, WARN, ERROR).

## Build

```bash
make
```

## Run

```bash
./app logfile.txt
```

Replace `logfile.txt` with the path to your log file.

## Example

If `logfile.txt` contains:

```
INFO: This is an informational message.
WARN: This is a warning message.
ERROR: This is an error message.
INFO: Another info message.
```

The output will be similar to:

```
INFO: 2
WARN: 1
ERROR: 1
```
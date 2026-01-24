# Log Analyzer

A simple C program to analyze log files and count the occurrences of different log levels (INFO, WARN, ERROR).

## Build

To build the program, use the provided Makefile:

```bash
make
```

This will create an executable named `app`.

## Run

To run the program, provide the log file as a command-line argument:

```bash
./app logfile.txt
```

## Example

Consider a log file named `example.log` with the following content:

```
2024-10-27 10:00:00 INFO: System started
2024-10-27 10:01:00 WARN: Low memory
2024-10-27 10:02:00 INFO: User logged in
2024-10-27 10:03:00 ERROR: Connection failed
2024-10-27 10:04:00 INFO: Data processed
2024-10-27 10:05:00 WARN: Disk almost full
2024-10-27 10:06:00 ERROR: File not found
```

Running the analyzer:

```bash
./app example.log
```

The output will be similar to:

```
INFO: 3
WARN: 2
ERROR: 2
```
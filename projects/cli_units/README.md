# Command-Line Unit Converter

This is a simple command-line unit converter written in C.

## Supported Conversions

*   Kilometers to Miles (km to mi)
*   Miles to Kilometers (mi to km)
*   Celsius to Fahrenheit (C to F)
*   Fahrenheit to Celsius (F to C)

## Building

To build the program, you need `gcc` and `make`.

1.  Save the provided `main.c` and `Makefile` in the same directory.
2.  Open a terminal in that directory.
3.  Run `make`.

This will create an executable file named `app`.

## Running

To run the program, execute the `app` executable with the appropriate arguments:

```bash
./app <conversion_type> <value>
```

Where:

*   `<conversion_type>` can be one of: `km_to_mi`, `mi_to_km`, `C_to_F`, `F_to_C`
*   `<value>` is the numerical value to convert.

## Example

To convert 10 kilometers to miles:

```bash
./app km_to_mi 10
```

This will output:

```
10.00 km is equal to 6.21 mi
```

To convert 212 Fahrenheit to Celsius:

```bash
./app F_to_C 212
```

This will output:

```
212.00 F is equal to 100.00 C
```
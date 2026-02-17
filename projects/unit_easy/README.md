# Unit Converter

A simple command-line unit converter written in C.

## Supported Conversions

*   Kilometers to Miles (km to mi)
*   Miles to Kilometers (mi to km)
*   Celsius to Fahrenheit (C to F)
*   Fahrenheit to Celsius (F to C)

## Building

To build the program, use the provided Makefile:

```bash
make
```

This will create an executable named `app`.

## Running

Run the program from the command line:

```bash
./app <conversion_type> <value>
```

Where:

*   `<conversion_type>` is one of: `km_to_mi`, `mi_to_km`, `c_to_f`, `f_to_c`
*   `<value>` is the numerical value to convert.

## Example

To convert 10 kilometers to miles:

```bash
./app km_to_mi 10
```

This will output the equivalent value in miles.

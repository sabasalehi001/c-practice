# Command-Line Unit Converter

A simple command-line tool for converting between different units.

## Supported Conversions:

*   Kilometers to Miles (km <-> mi)
*   Celsius to Fahrenheit (C <-> F)

## Build Instructions:

1.  Ensure you have `gcc` and `make` installed.
2.  Clone this repository.
3.  Navigate to the project directory.
4.  Run `make` in the terminal. This will create an executable named `app`.

## Usage:

```bash
./app <conversion_type> <value>
```

Where:

*   `<conversion_type>` can be:
    *   `km_to_mi`
    *   `mi_to_km`
    *   `c_to_f`
    *   `f_to_c`
*   `<value>` is the numerical value to convert.

## Example:

To convert 25 kilometers to miles:

```bash
./app km_to_mi 25
```

This will output the equivalent value in miles.

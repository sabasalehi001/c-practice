# Unit Converter

A simple command-line unit converter written in C.

## Supported Conversions:

*   Kilometers to Miles (km <-> mi)
*   Celsius to Fahrenheit (C <-> F)

## Build Instructions

1.  Make sure you have `gcc` and `make` installed.
2.  Clone the repository.
3.  Navigate to the project directory.
4.  Run `make` to build the executable.

## Usage

```bash
./app <conversion_type> <value>
```

*   `<conversion_type>` can be `km_to_mi`, `mi_to_km`, `c_to_f`, or `f_to_c`.
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
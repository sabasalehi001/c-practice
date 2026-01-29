# Simple Converter

A command-line tool for converting between various units.

## Supported Conversions:

*   Kilometers to Miles (km to mi)
*   Miles to Kilometers (mi to km)
*   Celsius to Fahrenheit (C to F)
*   Fahrenheit to Celsius (F to C)

## Building

To build the program, use the following command:

```bash
make
```

This will create an executable file named `app`.

## Running

To run the program, use the following command:

```bash
./app <conversion_type> <value>
```

Where `<conversion_type>` is one of the following:

*   `km_to_mi`
*   `mi_to_km`
*   `c_to_f`
*   `f_to_c`

And `<value>` is the numerical value to convert.

## Example

To convert 10 kilometers to miles:

```bash
./app km_to_mi 10
```

This will output:

```
10.00 km is equal to 6.21 mi
```
# Simple Convert

A command-line unit converter.

## Supported Conversions

*   Kilometers to Miles (km <-> mi)
*   Celsius to Fahrenheit (C <-> F)

## Build

```bash
make
```

This will compile the `main.c` file and create an executable named `app`.

## Run

```bash
./app <conversion_type> <value>
```

where:

*   `<conversion_type>` can be `km_to_mi`, `mi_to_km`, `c_to_f`, or `f_to_c`.
*   `<value>` is the numerical value to convert.

## Example

To convert 10 kilometers to miles:

```bash
./app km_to_mi 10
```

This will output the equivalent value in miles.

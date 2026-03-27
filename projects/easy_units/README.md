# Easy Units

A simple command-line unit converter written in C.

## Supported Conversions

*   Kilometers to Miles (km to mi)
*   Miles to Kilometers (mi to km)
*   Celsius to Fahrenheit (C to F)
*   Fahrenheit to Celsius (F to C)

## Building

To build the application, run:

```bash
make
```

This will create an executable named `app`.

## Running

To run the application, use the following syntax:

```bash
./app <value> <unit_from> <unit_to>
```

Where:

*   `<value>` is the numerical value to convert.
*   `<unit_from>` is the original unit (e.g., km, mi, C, F).
*   `<unit_to>` is the target unit (e.g., mi, km, F, C).

## Example

To convert 10 kilometers to miles:

```bash
./app 10 km mi
```

This will output the equivalent value in miles.

# Unit Converter

A simple command-line unit converter written in C.

## Supported Conversions

*   Kilometers to Miles (km <-> mi)
*   Celsius to Fahrenheit (C <-> F)

## Build

To build the application, use the following command:

```bash
make
```

## Run

To run the application, use the following command:

```bash
./app <value> <unit_from> <unit_to>
```

where:

*   `<value>` is the numerical value to convert.
*   `<unit_from>` is the original unit (km, mi, C, F).
*   `<unit_to>` is the desired unit (km, mi, C, F).

## Example

To convert 10 kilometers to miles:

```bash
./app 10 km mi
```

This will output the equivalent value in miles.


# SNMP Agent Sample (C++)

This is a simple example of an SNMP agent in C++ using Net-SNMP libraries.
It responds to a GET request for a custom OID with the string "hello world".

## Requirements

- Net-SNMP development libraries (e.g., `libsnmp-dev snmp snmpd`)
- CMake
- g++

## Build

```bash
mkdir build && cd build
cmake ..
make
```

## Run

```bash
sudo ./agent
```

## Test with snmpget

```bash
snmpget -v2c -c public localhost 1.3.6.1.4.1.8072.9999.1
```

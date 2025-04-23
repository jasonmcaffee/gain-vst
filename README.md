# Gain VST Plugin

A simple gain control VST plugin built with JUCE framework.

## Prerequisites

- CMake (version 3.15 or higher)
- C++ compiler with C++17 support
- JUCE framework (included as a submodule)

## Building the Project

```bash
rm -rf build && mkdir build && cd build && cmake .. && cmake --build .
```

The built plugin will be located in the `build` directory.

## Running Tests

The project uses Catch2 for unit testing. To run the tests:

```bash
cd build && ctest
```

Or to run the tests with more detailed output:

```bash
./build/gain-vst-tests_artefacts/gain-vst-tests
```

## Plugin Features

- Simple gain control with rotary knob
- Range: 0.0 to 2.0
- Default value: 1.0

## Development

This project uses JUCE framework for audio plugin development. The main source files are located in the `Source` directory.

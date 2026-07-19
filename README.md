# apexdyn

A command-line toolkit for vehicle dynamics engineering, built as a learning project in modern C++, object-oriented design, and Git workflows.

## Motivation

`apexdyn` reads physical vehicle parameters and characterizes/simulates vehicle behavior (starting with simple longitudinal dynamics, such as estimated acceleration). Development data is extracted locally from Assetto Corsa vehicle files (`.ini`/`.lut`), which provides a practical reference point: simulation results can be compared against a commercial simulator's behavior for the same vehicle, instead of validating assumptions in a vacuum.

Assetto Corsa data files are not included in this repository (see [Data](#data) below). The public repository focuses on the tool itself; synthetic/sample data will be added for demonstration purposes as the project progresses.

This project is being developed step by step as a learning exercise in:
- Modern C++ (C++17)
- Object-oriented design applied incrementally, driven by real needs rather than upfront speculation
- Git workflows (small, focused commits)
- CMake-based build systems

## Current status

**Implemented:**
- `apexdyn inspect <data-directory>` — validates a directory path and counts `.ini`/`.lut` files within it, returning appropriate exit codes for scripting/automation use.

**Planned next:**
- Parsing vehicle parameters from `.ini`/`.lut` files into an independent `VehicleParameters` model
- Basic vehicle characterization (power-to-weight ratio, gear ratios, etc.)
- Longitudinal acceleration simulation
- CSV/report output
- Comparison against Assetto Corsa telemetry data

## Building

**Requirements:**
- CMake 3.31+
- A C++17-capable compiler (developed with MinGW/GCC on Windows)

```powershell
cmake -B cmake-build-debug -S .
cmake --build cmake-build-debug
```

The executable will be generated at `cmake-build-debug/apexdyn.exe`.

## Usage

```powershell
apexdyn inspect <data-directory>
```

Validates that `<data-directory>` exists and is a directory, then counts `.ini` and `.lut` files within it.

**Example:**
```powershell
apexdyn inspect C:\path\to\vehicle\data
found 28 .ini file(s) and 18 .lut file(s) in C:\path\to\vehicle\data
```

**Exit codes:**
- `0` — success
- `1` — invalid arguments, or the path does not exist / is not a directory

## Data

This project is developed against Assetto Corsa vehicle data files, extracted locally. These files are **not** committed to this repository, as they are third-party game assets. If you want to experiment with the tool, point it at any directory containing `.ini`/`.lut` files, or a directory of your own synthetic test files.

## Architecture

The codebase separates concerns as the project grows:

- `include/InspectionOutcome.h` — plain data type representing the result of inspecting a directory
- `include/DirectoryInspection.h` / `src/DirectoryInspection.cpp` — inspection logic, decoupled from CLI argument handling
- `src/main.cpp` — thin orchestration layer (argument parsing, invoking inspection, reporting results)

Design decisions are logged in [`docs/decisions.md`](docs/decisions.md) as the project evolves.
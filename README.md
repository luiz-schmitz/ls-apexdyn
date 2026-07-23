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

`apexdyn` can inspect a vehicle's data directory, load its physical parameters (mass, drivetrain, suspension, tyres) from Assetto Corsa `.ini` files, parse the engine's torque curve from `.lut` files, and compute wheel force at a given gear and vehicle speed — the first real engineering calculation in the project, combining torque curve interpolation with drivetrain ratios.

See [`CHANGELOG.md`](CHANGELOG.md) for the full history of what has been implemented, and [`docs/decisions.md`](docs/decisions.md) for the reasoning behind key architectural decisions.

**Planned next:**
- Wheel force vs. vehicle speed curves across all gears (for CSV export)
- Longitudinal resistances (drag, rolling resistance)
- Longitudinal acceleration simulation
- Comparison against Assetto Corsa telemetry data

## Building

**Requirements:**
- CMake 3.20+
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

Validates that `<data-directory>` exists and is a directory, counts `.ini`/`.lut` files within it, and loads available vehicle parameters.

**Exit codes:**
- `0` — success
- `1` — invalid arguments, or the path does not exist / is not a directory

## Data

This project is developed against Assetto Corsa vehicle data files, extracted locally. These files are **not** committed to this repository, as they are third-party game assets. If you want to experiment with the tool, point it at any directory containing `.ini`/`.lut` files, or a directory of your own synthetic test files.

## Architecture

The codebase separates concerns as the project grows:

- `include/InspectionOutcome.h` / `include/DirectoryInspection.h` + `src/DirectoryInspection.cpp` - directory validation and file counting, decoupled from CLI argument handling
- `include/IniValueParsing.h` + `src/IniValueParsing.cpp` - generic, typed extraction of values from INI files (via the [mINI](https://github.com/pulzed/mINI) library)
- `include/VehicleParameters.h` - a data-only model of a vehicle's physical parameters, independent of its data source
- `include/VehicleLoader.h` + `src/VehicleLoader.cpp` - translates Assetto Corsa files into a `VehicleParameters` instance
- `include/TorqueCurve.h` + `src/TorqueCurve.cpp` - parses engine torque curves from `.lut` files and interpolates torque at a given RPM
- `include/Drivetrain.h` + `src/Drivetrain.cpp` - RPM/speed conversions and wheel force calculations for a given gear
- `src/main.cpp` - thin orchestration layer (argument parsing, invoking inspection/loading, reporting results)

Design decisions are logged in [`docs/decisions.md`](docs/decisions.md) as the project evolves.
# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

### Added
- Project scaffold with CMake, C++17, and MinGW toolchain
- `apexdyn inspect <data-directory>` command: validates a directory path and counts `.ini`/`.lut` files within it
- `InspectionOutcome` struct and `inspectDataDirectory` function, decoupling directory inspection logic from CLI orchestration in `main.cpp`
- Integration of the [mINI](https://github.com/pulzed/mINI) library via CMake `FetchContent`, pinned to a fixed commit
- `IniValueParsing` module (`readDoubleValue`, `readIntValue`, `readStringValue`) for extracting typed values from INI files, stripping inline comments and surrounding whitespace
- `VehicleParameters` struct: an independent, typed model of a vehicle's physical parameters
- `VehicleLoader` module (`loadVehicleParameters`): aggregates `car.ini`, `drivetrain.ini`, and `suspensions.ini` from a vehicle's data directory into a `VehicleParameters` instance
    - Fields: car name, total mass, traction type, gear count, front/rear suspension type
- `docs/decisions.md`: architecture decision log (ADR 001–004)
- Project `README.md`

### Changed
- `loadVehicleParameters` now accepts a vehicle data directory instead of a single `car.ini` path, resolving all required files internally

## Notes

This project is developed incrementally as a C++/OOP/Git learning exercise, documented alongside [`docs/decisions.md`](docs/decisions.md) for the reasoning behind each architectural choice.
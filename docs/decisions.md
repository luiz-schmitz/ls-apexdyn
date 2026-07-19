## ADR 001: Separate InspectionOutcome from inspection logic

**Date:** 2026-07-18

**Context:** main.cpp mixed argument parsing, validation, and file
counting in a single function.

**Decision:** Introduce a data-only struct (InspectionOutcome) to
carry results, decoupled from how the inspection is performed.

**Consequences:** main.cpp becomes a thin orchestrator; inspection
logic becomes independently testable.

## ADR 002: Use mINI library for INI parsing instead of a custom parser

**Date:** 2026-07-18

**Context:** Assetto Corsa vehicle files use an Ini-like format with
inline comments (`;`) after values. Writing a custom parser was
considered, but it would consume learning time better spent on
vehicle dynamics modeling rather than generic text parsing.

**Decision:** Integrate the mINI library via CMake FetchContent for
raw INI parsing. Application-specific concerns (stripping inline
comments, trimming whitespace, converting to numeric types) are
handled separately in IniValueParsing, keeping the third-party
library's responsibility limited to raw section/key/value access.

**Consequences:** Faster progress toward vehicle parameter modeling.
Introduces an external dependency, managed cleanly through CMake
rather than manual file management.

## ADR 003: Introduce VehicleParameters and VehicleLoader

**Date:** 2026-07-18

**Context:** Vehicle physical parameters (e.g. total mass) needed to
be extracted from car.ini without coupling the rest of the
application to Assetto Corsa's file format or the mINI library.

**Decision:** Introduce VehicleParameters as a data-only struct
representing a vehicle independently of its data source, and
VehicleLoader as a function that translates car.ini contents into a
VehicleParameters instance.

**Consequences:** Vehicle-related logic (simulation, reporting) can
depend on VehicleParameters alone, without ever referencing INI
files or the mINI library directly. This mirrors the architecture
outlined for the project: Assetto Corsa files → loader → independent
vehicle model → simulation modules.

## ADR 004: Load VehicleParameters from a data directory, not a single file

**Date:** 2026-07-19

**Context:** VehicleParameters now pulls fields from multiple files
(car.ini, drivetrain.ini, suspensions.ini), not just car.ini.

**Decision:** loadVehicleParameters now takes the vehicle's data
directory and resolves each file internally, instead of the caller
passing a single file path.

**Consequences:** Adding a new field means editing the struct and
loadVehicleParameters — a small, acceptable cost for keeping
VehicleParameters typed and explicit instead of a generic key lookup.
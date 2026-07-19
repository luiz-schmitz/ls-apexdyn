## ADR 001: Separate InspectionOutcome from inspection logic

**Context:** main.cpp mixed argument parsing, validation, and file
counting in a single function.

**Decision:** Introduce a data-only struct (InspectionOutcome) to
carry results, decoupled from how the inspection is performed.

**Consequences:** main.cpp becomes a thin orchestrator; inspection
logic becomes independently testable.
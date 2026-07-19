#pragma once

#include <string>

/// Represents the outcome of inspecting a data directory,
/// including validity, diagnostic message, and file counts.
struct InspectionOutcome {
    bool isValid;
    std::string message;
    int iniCount = 0;
    int lutCount = 0;
};
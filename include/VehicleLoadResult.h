#pragma once

#include <string>
#include "VehicleParameters.h"

/// Result of attempting to load VehicleParameters from a data directory.
/// isValid indicates whether all required fields were successfully read;
/// message carries a diagnostic string when isValid is false.
struct VehicleLoadResult {
    bool isValid = false;
    std::string message;
    VehicleParameters parameters;
};
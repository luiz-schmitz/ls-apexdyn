#pragma once

#include <string>

/// Physical parameters describing a vehicle, independent of the
/// data source they were loaded from (e.g. Assetto Corsa files).
struct VehicleParameters {
    std::string carName;
    double totalMass = 0.0;
    std::string traction;
    int gearCount = 0;
    std::string frontSuspensionType;
    std::string rearSuspensionType;
};
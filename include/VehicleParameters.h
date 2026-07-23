#pragma once

#include <string>
#include <vector>

/// Physical parameters describing a vehicle, independent of the
/// data source they were loaded from (e.g. Assetto Corsa files).
struct VehicleParameters {
    std::string carName;
    double totalMass = 0.0;
    std::string traction;
    int gearCount = 0;
    std::vector<double> gearRatios;
    double finalDriveRatio = 0.0;
    std::string frontSuspensionType;
    std::string rearSuspensionType;
    double wheelBase = 0.0;
    double cgLocation = 0.0;
    double frontTyreRadius = 0.0;
    double rearTyreRadius = 0.0;
};

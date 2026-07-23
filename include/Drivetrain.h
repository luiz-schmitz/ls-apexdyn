#pragma once

#include <vector>
#include <optional>
#include "TorqueCurve.h"

// Converts engine RPM to vehicle speed, for a given gear
double vehicleSpeed(double rpm, double gearRatio, double finalDriveRatio, double tyreRadius);

// Converts vehicle speed to engine RPM, for a given gear (inverse of vehicleSpeed)
double engineRpm(double speed, double gearRatio, double finalDriveRatio, double tyreRadius);

// Computes the wheel force available at a given gear and vehicle speed
std::optional<double> wheelForce(const std::vector<TorqueCurvePoint>& torqueCurve, double gearRatio, double finalDriveRatio, double tyreRadius, double speed);
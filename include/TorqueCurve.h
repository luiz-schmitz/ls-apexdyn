#pragma once

#include <vector>
#include <filesystem>

/// A single point on an engine's torque curve: torque (Nm) at a given RPM.
struct TorqueCurvePoint {
    double rpm = 0.0;
    double torque = 0.0;
};

/// Reads a .lut file (RPM|Torque pairs, one per line) into a vector of points.
std::vector<TorqueCurvePoint> loadTorqueCurve(const std::filesystem::path& lutPath);
#pragma once

#include <vector>
#include <string>
#include <filesystem>

/// A single point on an engine's torque curve: torque (Nm) at a given RPM.
struct TorqueCurvePoint {
    double rpm = 0.0;
    double torque = 0.0;
};

/// Result of attempting to load a torque curve from a .lut file.
struct TorqueCurveLoadResult {
    bool isValid = false;
    std::string message;
    std::vector<TorqueCurvePoint> points;
};

/// Reads a .lut file (RPM|Torque pairs, one per line) into a vector of points.
TorqueCurveLoadResult loadTorqueCurve(const std::filesystem::path& lutPath);
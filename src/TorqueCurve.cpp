#include "TorqueCurve.h"
#include <fstream>

TorqueCurveLoadResult loadTorqueCurve(const std::filesystem::path& lutPath) {
    TorqueCurveLoadResult result;

    if (!std::filesystem::exists(lutPath)) {
        result.isValid = false;
        result.message = "missing file: " + lutPath.string();
        return result;
    }

    std::ifstream file(lutPath.string());
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        size_t separatorPos = line.find('|');
        if (separatorPos == std::string::npos) {
            result.isValid = false;
            result.message = "malformed line (missing '|'): " + line;
            return result;
        }

        std::string rpmPart = line.substr(0, separatorPos);
        std::string torquePart = line.substr(separatorPos + 1);

        TorqueCurvePoint point;
        try {
            point.rpm = std::stod(rpmPart);
            point.torque = std::stod(torquePart);
        } catch (...) {
            result.isValid = false;
            result.message = "invalid numeric value in line: " + line;
            return result;
        }

        result.points.push_back(point);
    }

    if (result.points.empty()) {
        result.isValid = false;
        result.message = "no valid data points found in: " + lutPath.string();
        return result;
    }

    result.isValid = true;
    result.message = "success";
    return result;
}
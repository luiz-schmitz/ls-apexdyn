#include "TorqueCurve.h"
#include <fstream>

std::vector<TorqueCurvePoint> loadTorqueCurve(const std::filesystem::path& lutPath) {
    std::vector<TorqueCurvePoint> curve;

    std::ifstream file(lutPath.string());
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        size_t separatorPos = line.find('|');
        std::string rpmPart = line.substr(0, separatorPos);
        std::string torquePart = line.substr(separatorPos + 1);

        TorqueCurvePoint point;
        point.rpm = std::stod(rpmPart);
        point.torque = std::stod(torquePart);

        curve.push_back(point);
    }

    return curve;
}
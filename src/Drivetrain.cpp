#include "Drivetrain.h"

double vehicleSpeed(double rpm, double gearRatio, double finalDriveRatio, double tyreRadius) {
    constexpr double pi = 3.14159265358979323846;
    return (rpm * 2 * pi / 60 * tyreRadius)/(gearRatio * finalDriveRatio) ;
}

double engineRpm(double speed, double gearRatio, double finalDriveRatio, double tyreRadius) {
    constexpr double pi = 3.14159265358979323846;
    double angularVelocity = (speed * gearRatio * finalDriveRatio) / tyreRadius;
    return angularVelocity * 60 / (2 * pi);
}

std::optional<double> wheelForce(const std::vector<TorqueCurvePoint>& torqueCurve, double gearRatio, double finalDriveRatio, double tyreRadius, double speed) {
    double rpm = engineRpm(speed, gearRatio, finalDriveRatio, tyreRadius);
    std::optional<double> torque = interpolateTorque(torqueCurve, rpm);

    if (!torque) {
        return std::nullopt;
    }

    return (*torque * gearRatio * finalDriveRatio) / tyreRadius;
}
#include <iostream>
#include "DirectoryInspection.h"
#include "VehicleLoader.h"
#include "TorqueCurve.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "usage: apexdyn <command> <data-directory>" << std::endl;
        return 1;
    }

    std::filesystem::path dataDir(argv[2]);
    InspectionOutcome outcome = inspectDataDirectory(dataDir);

    std::cout << outcome.message << std::endl;

    if (!outcome.isValid) {
        return 1;
    }

    VehicleLoadResult result = loadVehicleParameters(dataDir);
    if (!result.isValid) {
        std::cout << "error: " << result.message << std::endl;
        return 1;
    }
    VehicleParameters vehicle = result.parameters;

    std::cout << "car name: " << vehicle.carName << std::endl;
    std::cout << "total mass: " << vehicle.totalMass << " kg" << std::endl;
    std::cout << "traction: " << vehicle.traction << std::endl;
    std::cout << "gear count: " << vehicle.gearCount << std::endl;
    std::cout << "front suspension: " << vehicle.frontSuspensionType << std::endl;
    std::cout << "rear suspension: " << vehicle.rearSuspensionType << std::endl;
    std::cout << "final drive ratio: " << vehicle.finalDriveRatio << std::endl;
    std::cout << "wheelbase: " << vehicle.wheelBase << " m" << std::endl;
    std::cout << "cg location (front weight %): " << vehicle.cgLocation << std::endl;
    std::cout << "front tyre radius: " << vehicle.frontTyreRadius << " m" << std::endl;
    std::cout << "rear tyre radius: " << vehicle.rearTyreRadius << " m" << std::endl;

    std::filesystem::path lutPath = dataDir / "power.lut";
    loadTorqueCurve(lutPath);
    std::vector<TorqueCurvePoint> curve = loadTorqueCurve(lutPath);
    std::cout << "torque curve points: " << curve.size() << std::endl;

    std::cout << "first point: rpm=" << curve.front().rpm << " torque=" << curve.front().torque << std::endl;
    std::cout << "last point: rpm=" << curve.back().rpm << " torque=" << curve.back().torque << std::endl;

    return 0;
}
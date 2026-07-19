#include <iostream>
#include <cassert>
#include "VehicleLoader.h"
#include "TestConfig.h"

int main() {
    std::filesystem::path sampleVehicleDir = std::filesystem::path(kTestFixturesDir) / "sample_vehicle";

    VehicleLoadResult result = loadVehicleParameters(sampleVehicleDir);
    assert(result.isValid);
    VehicleParameters vehicle = result.parameters;
    assert(vehicle.carName == "Synthetic Test Car");
    assert(vehicle.totalMass == 1000.0);
    assert(vehicle.traction == "RWD");
    assert(vehicle.gearCount == 5);
    assert(vehicle.finalDriveRatio == 4.0);
    assert(vehicle.wheelBase == 2.5);
    assert(vehicle.cgLocation == 0.5);
    assert(vehicle.frontSuspensionType == "STRUT");
    assert(vehicle.rearSuspensionType == "AXLE");
    assert(vehicle.frontTyreRadius == 0.3);
    assert(vehicle.rearTyreRadius == 0.32);

    std::cout << "All VehicleLoader tests passed." << std::endl;
    return 0;
}
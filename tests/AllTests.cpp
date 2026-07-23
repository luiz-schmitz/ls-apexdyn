#include <iostream>
#include <cassert>
#include "VehicleLoader.h"
#include "TestConfig.h"
#include "TorqueCurve.h"

int main() {
    std::filesystem::path sampleVehicleDir = std::filesystem::path(kTestFixturesDir) / "sample_vehicle";

    VehicleLoadResult result = loadVehicleParameters(sampleVehicleDir);
    assert(result.isValid);
    VehicleParameters vehicle = result.parameters;
    assert(vehicle.carName == "Synthetic Test Car");
    assert(vehicle.totalMass == 1000.0);
    assert(vehicle.traction == "RWD");
    assert(vehicle.gearCount == 5);
    assert(vehicle.gearRatios.size() == 5);
    assert(vehicle.gearRatios[0] == 3.0);
    assert(vehicle.gearRatios[1] == 2.0);
    assert(vehicle.gearRatios[2] == 1.5);
    assert(vehicle.gearRatios[3] == 1.0);
    assert(vehicle.gearRatios[4] == 0.8);
    assert(vehicle.finalDriveRatio == 4.0);
    assert(vehicle.wheelBase == 2.5);
    assert(vehicle.cgLocation == 0.5);
    assert(vehicle.frontSuspensionType == "STRUT");
    assert(vehicle.rearSuspensionType == "AXLE");
    assert(vehicle.frontTyreRadius == 0.3);
    assert(vehicle.rearTyreRadius == 0.32);


    std::cout << "All VehicleLoader tests passed." << std::endl;

    std::vector<TorqueCurvePoint> curve = {
        {1000.0, 100.0},
        {2000.0, 200.0},
        {3000.0, 150.0}
    };

    std::vector<TorqueCurvePoint> emptyCurve;
    auto emptyResult = interpolateTorque(emptyCurve, 1500.0);
    assert(!emptyResult.has_value());

    auto belowResult = interpolateTorque(curve, 500.0);
    assert(belowResult.has_value());
    assert(*belowResult == 100.0);

    auto aboveResult = interpolateTorque(curve, 5000.0);
    assert(aboveResult.has_value());
    assert(*aboveResult == 150.0);

    auto averageResult = interpolateTorque(curve, 1500.0);
    assert(averageResult.has_value());
    assert(*averageResult == 150.0);

    std::cout << "All TorqueCurve tests passed." << std::endl;
    return 0;
}
#include "VehicleLoader.h"
#include "IniValueParsing.h"
#include "mini/ini.h"

static VehicleLoadResult fail(const std::string& message) {
    VehicleLoadResult result;
    result.isValid = false;
    result.message = message;
    return result;
}

VehicleLoadResult loadVehicleParameters(const std::filesystem::path& dataDir) {
    std::filesystem::path carIniPath = dataDir / "car.ini";
    std::filesystem::path drivetrainIniPath = dataDir / "drivetrain.ini";
    std::filesystem::path suspensionsIniPath = dataDir / "suspensions.ini";
    std::filesystem::path tyresIniPath = dataDir / "tyres.ini";

    if (!std::filesystem::exists(carIniPath)) {
        return fail("missing file: " + carIniPath.string());
    }
    if (!std::filesystem::exists(drivetrainIniPath)) {
        return fail("missing file: " + drivetrainIniPath.string());
    }
    if (!std::filesystem::exists(suspensionsIniPath)) {
        return fail("missing file: " + suspensionsIniPath.string());
    }
    if (!std::filesystem::exists(tyresIniPath)) {
        return fail("missing file: " + tyresIniPath.string());
    }

    mINI::INIFile carFile(carIniPath.string());
    mINI::INIStructure carIni;
    carFile.read(carIni);

    mINI::INIFile drivetrainFile(drivetrainIniPath.string());
    mINI::INIStructure drivetrainIni;
    drivetrainFile.read(drivetrainIni);

    mINI::INIFile suspensionFile(suspensionsIniPath.string());
    mINI::INIStructure suspensionIni;
    suspensionFile.read(suspensionIni);

    mINI::INIFile tyresFile(tyresIniPath.string());
    mINI::INIStructure tyresIni;
    tyresFile.read(tyresIni);

    VehicleParameters params;

    auto carName = readStringValue(carIni, "INFO", "SCREEN_NAME");
    if (!carName) return fail("missing or invalid car.ini [INFO] SCREEN_NAME");
    params.carName = *carName;

    auto totalMass = readDoubleValue(carIni, "BASIC", "TOTALMASS");
    if (!totalMass) return fail("missing or invalid car.ini [BASIC] TOTALMASS");
    params.totalMass = *totalMass;

    auto traction = readStringValue(drivetrainIni, "TRACTION", "TYPE");
    if (!traction) return fail("missing or invalid drivetrain.ini [TRACTION] TYPE");
    params.traction = *traction;

    auto gearCount = readIntValue(drivetrainIni, "GEARS", "COUNT");
    if (!gearCount) return fail("missing or invalid drivetrain.ini [GEARS] COUNT");
    params.gearCount = *gearCount;

    auto finalDriveRatio = readDoubleValue(drivetrainIni, "GEARS", "FINAL");
    if (!finalDriveRatio) return fail("missing or invalid drivetrain.ini [GEARS] FINAL");
    params.finalDriveRatio = *finalDriveRatio;

    auto frontSuspensionType = readStringValue(suspensionIni, "FRONT", "TYPE");
    if (!frontSuspensionType) return fail("missing or invalid suspensions.ini [FRONT] TYPE");
    params.frontSuspensionType = *frontSuspensionType;

    auto rearSuspensionType = readStringValue(suspensionIni, "REAR", "TYPE");
    if (!rearSuspensionType) return fail("missing or invalid suspensions.ini [REAR] TYPE");
    params.rearSuspensionType = *rearSuspensionType;

    auto wheelBase = readDoubleValue(suspensionIni, "BASIC", "WHEELBASE");
    if (!wheelBase) return fail("missing or invalid suspensions.ini [BASIC] WHEELBASE");
    params.wheelBase = *wheelBase;

    auto cgLocation = readDoubleValue(suspensionIni, "BASIC", "CG_LOCATION");
    if (!cgLocation) return fail("missing or invalid suspensions.ini [BASIC] CG_LOCATION");
    params.cgLocation = *cgLocation;

    auto frontTyreRadius = readDoubleValue(tyresIni, "FRONT", "RADIUS");
    if (!frontTyreRadius) return fail("missing or invalid tyres.ini [FRONT] RADIUS");
    params.frontTyreRadius = *frontTyreRadius;

    auto rearTyreRadius = readDoubleValue(tyresIni, "REAR", "RADIUS");
    if (!rearTyreRadius) return fail("missing or invalid tyres.ini [REAR] RADIUS");
    params.rearTyreRadius = *rearTyreRadius;

    VehicleLoadResult result;
    result.isValid = true;
    result.message = "success";
    result.parameters = params;
    return result;
}
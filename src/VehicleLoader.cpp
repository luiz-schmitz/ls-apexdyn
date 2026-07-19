#include "VehicleLoader.h"
#include "IniValueParsing.h"
#include "mini/ini.h"

VehicleParameters loadVehicleParameters(const std::filesystem::path& dataDir) {
    VehicleParameters params;

    std::filesystem::path carIniPath = dataDir / "car.ini";
    std::filesystem::path drivetrainIniPath = dataDir / "drivetrain.ini";
    std::filesystem::path suspensionsIniPath = dataDir / "suspensions.ini";
    std::filesystem::path tyresIniPath = dataDir / "tyres.ini";

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

    params.carName = readStringValue(carIni, "INFO", "SCREEN_NAME");
    params.totalMass = readDoubleValue(carIni, "BASIC", "TOTALMASS");
    params.traction = readStringValue(drivetrainIni, "TRACTION", "TYPE");
    params.gearCount = readIntValue(drivetrainIni, "GEARS", "COUNT");
    params.frontSuspensionType = readStringValue(suspensionIni, "FRONT", "TYPE");
    params.rearSuspensionType = readStringValue(suspensionIni, "REAR", "TYPE");
    params.finalDriveRatio = readDoubleValue(drivetrainIni, "GEARS", "FINAL");
    params.wheelBase = readDoubleValue(suspensionIni, "BASIC", "WHEELBASE");
    params.cgLocation = readDoubleValue(suspensionIni, "BASIC", "CG_LOCATION");
    params.frontTyreRadius = readDoubleValue(tyresIni, "FRONT", "RADIUS");
    params.rearTyreRadius = readDoubleValue(tyresIni, "REAR", "RADIUS");

    return params;
}
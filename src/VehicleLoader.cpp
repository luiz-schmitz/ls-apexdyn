#include "VehicleLoader.h"
#include "IniValueParsing.h"
#include "mini/ini.h"

VehicleParameters loadVehicleParameters(const std::filesystem::path& carIniPath) {
    VehicleParameters params;

    mINI::INIFile file(carIniPath.string());
    mINI::INIStructure ini;
    file.read(ini);

    params.totalMass = readDoubleValue(ini, "BASIC", "TOTALMASS");

    return params;
}
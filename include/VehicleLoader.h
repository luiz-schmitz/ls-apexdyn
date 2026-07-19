#pragma once

#include <filesystem>
#include "VehicleParameters.h"

VehicleParameters loadVehicleParameters(const std::filesystem::path& carIniPath);
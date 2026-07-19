#pragma once
#include <filesystem>
#include "VehicleLoadResult.h"

VehicleLoadResult loadVehicleParameters(const std::filesystem::path& dataDir);
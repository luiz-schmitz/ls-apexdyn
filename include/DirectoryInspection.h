#pragma once

#include <filesystem>
#include "InspectionOutcome.h"

InspectionOutcome inspectDataDirectory(const std::filesystem::path& dataDir);
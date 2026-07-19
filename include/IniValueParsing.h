#pragma once

#include <string>
#include <optional>
#include "mini/ini.h"

/// Reads a value from an INI structure, stripping inline comments (starting with ';') and surrounding whitespace,
/// then parses it as a double, int or string.
std::optional<double> readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
std::optional<int> readIntValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
std::optional<std::string> readStringValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
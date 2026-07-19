#pragma once

#include <string>
#include "mini/ini.h"

/// Reads a value from an INI structure, stripping inline comments (starting with ';') and surrounding whitespace,
/// then parses it as a double, int or string.
double readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
int readIntValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
std::string readStringValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
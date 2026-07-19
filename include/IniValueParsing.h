#pragma once

#include <string>
#include "mini/ini.h"

/// Reads a value from an INI structure, stripping inline comments
/// (starting with ';') and surrounding whitespace, then parses it as a double.
double readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key);
#include "IniValueParsing.h"

double readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string raw = ini[section][key];
    size_t semicolonPos = raw.find(';');
    std::string valueOnly = raw.substr(0, semicolonPos);

    size_t start = valueOnly.find_first_not_of(" \t");
    size_t end = valueOnly.find_last_not_of(" \t");
    std::string trimmed = valueOnly.substr(start, end - start + 1);

    return std::stod(trimmed);
}
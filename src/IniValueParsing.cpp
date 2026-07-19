#include "IniValueParsing.h"

static std::string extractCleanValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string raw = ini[section][key];
    size_t semicolonPos = raw.find(';');
    std::string valueOnly = raw.substr(0, semicolonPos);

    size_t start = valueOnly.find_first_not_of(" \t");
    size_t end = valueOnly.find_last_not_of(" \t");
    return valueOnly.substr(start, end - start + 1);
}

double readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    return std::stod(extractCleanValue(ini, section, key));
}

int readIntValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    return std::stoi(extractCleanValue(ini, section, key));
}

std::string readStringValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    return extractCleanValue(ini, section, key);
}
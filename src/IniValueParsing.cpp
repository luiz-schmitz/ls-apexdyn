// IniValueParsing.cpp
#include "IniValueParsing.h"

static std::string extractCleanValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string raw = ini[section][key];
    size_t semicolonPos = raw.find(';');
    std::string valueOnly = raw.substr(0, semicolonPos);

    size_t start = valueOnly.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = valueOnly.find_last_not_of(" \t");
    return valueOnly.substr(start, end - start + 1);
}

std::optional<double> readDoubleValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string cleaned = extractCleanValue(ini, section, key);
    if (cleaned.empty()) {
        return std::nullopt;
    }
    try {
        return std::stod(cleaned);
    } catch (...) {
        return std::nullopt;
    }
}

std::optional<int> readIntValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string cleaned = extractCleanValue(ini, section, key);
    if (cleaned.empty()) {
        return std::nullopt;
    }
    try {
        return std::stoi(cleaned);
    } catch (...) {
        return std::nullopt;
    }
}

std::optional<std::string> readStringValue(mINI::INIStructure& ini, const std::string& section, const std::string& key) {
    std::string cleaned = extractCleanValue(ini, section, key);
    if (cleaned.empty()) {
        return std::nullopt;
    }
    return cleaned;
}
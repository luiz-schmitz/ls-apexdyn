#include "DirectoryInspection.h"

InspectionOutcome inspectDataDirectory(const std::filesystem::path& dataDir) {
    InspectionOutcome outcome;
    if (!std::filesystem::exists(dataDir)) {
        outcome.isValid = false;
        outcome.message = "error: path does not exist: " + dataDir.string();
    }else if (!std::filesystem::is_directory(dataDir)){
        outcome.isValid = false;
        outcome.message = "error: path is not a directory: " + dataDir.string();
    } else {
        outcome.isValid = true;

        for (const auto& entry : std::filesystem::directory_iterator(dataDir)) {
            if (entry.is_regular_file()) {
                if (entry.path().extension() == ".ini") {
                    outcome.iniCount++;
                } else if (entry.path().extension() == ".lut") {
                    outcome.lutCount++;
                }
            }
        }
        outcome.message = "found " + std::to_string(outcome.iniCount) + " .ini file(s) and "
                        + std::to_string(outcome.lutCount) + " .lut file(s) in " + dataDir.string();
    }
    return outcome;
}
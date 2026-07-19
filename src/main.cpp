#include <iostream>
#include "DirectoryInspection.h"
#include "mini/ini.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "usage: apexdyn <command> <data-directory>" << std::endl;
        return 1;
    }

    std::filesystem::path dataDir(argv[2]);
    InspectionOutcome outcome = inspectDataDirectory(dataDir);

    std::cout << outcome.message << std::endl;

    if (!outcome.isValid) {
        return 1;
    }

    return 0;
}
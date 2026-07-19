#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "usage: apexdyn <command> <data-directory>" << std::endl;
        return 1;
    }
    std::filesystem::path dataDir(argv[2]);
    if (!std::filesystem::exists(dataDir)) {
        std::cout << "error: path does not exist: " << dataDir << std::endl;
        return 1;
    }else if (!std::filesystem::is_directory(dataDir)){
        std::cout << "error: path is not a directory: " << dataDir << std::endl;
        return 1;
    } else {
        int iniCount = 0;
        int lutCount = 0;

        for (const auto& entry : std::filesystem::directory_iterator(dataDir)) {
            if (entry.is_regular_file()) {
                if (entry.path().extension() == ".ini") {
                    iniCount++;
                } else if (entry.path().extension() == ".lut") {
                    lutCount++;
                }
            }
        }
        std::cout << "found " << iniCount << " .ini file(s) and "
                  << lutCount << " .lut file(s) in " << dataDir << std::endl;
    }

    return 0;
}
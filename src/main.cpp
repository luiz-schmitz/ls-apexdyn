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
    }else {
        std::cout << "path exists: " << dataDir << std::endl;
    }
    return 0;
}
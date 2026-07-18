#include <iostream>

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cout << "usage: apexdyn <command> [args...]" << std::endl;
        return 1;
    }
    std::cout << "argc: " << argc << ". argv[1]: " << argv[1] << std::endl;
    return 0;
}
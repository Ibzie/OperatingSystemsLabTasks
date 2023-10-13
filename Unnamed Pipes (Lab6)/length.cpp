#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    std::string inputString = argv[1];
    int length = inputString.length();
    std::cout << "Length: " << length << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    std::string inputString = argv[1];
    std::reverse(inputString.begin(), inputString.end());
    std::cout << "Reversed: " << inputString << std::endl;

    return 0;
}

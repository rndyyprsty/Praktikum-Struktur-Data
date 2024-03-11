#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> umur;

    umur["Birdway"] = 25;
    umur["Misaka"] = 30;
    umur["Othinus"] = 20;

    std::cout << "Umur Birdway: " << umur["Birdway"] << std::endl;

    std::cout << "Semua Umur:" << std::endl;
    for (const auto& pair : umur) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
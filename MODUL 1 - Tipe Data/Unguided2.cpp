#include <iostream>

class Animal {
public:
    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() {
        return name;
    }

private:
    std::string name;
};

int main() {
    Animal dog;
    dog.setName("Buddy");
    std::cout << dog.getName() << std::endl;

    return 0;
}
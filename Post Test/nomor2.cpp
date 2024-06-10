#include <iostream>

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } 
    else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int bilangan;

    std::cout << "input bilangan bulat: ";
    std::cin >> bilangan;

    int hasil = faktorial(bilangan);

    std::cout << "faktorial" << bilangan << " yaitu: " << hasil << std::endl;

    return 0;
}
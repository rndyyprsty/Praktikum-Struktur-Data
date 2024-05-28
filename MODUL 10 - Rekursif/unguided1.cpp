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

    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> bilangan;

    if (bilangan < 0) {
        std::cerr << "Input harus bilangan positif." << std::endl;
        return 1;
    }

    int hasil = faktorial(bilangan);

    std::cout << "Faktorial dari " << bilangan << " adalah: " << hasil << std::endl;

    return 0;
}
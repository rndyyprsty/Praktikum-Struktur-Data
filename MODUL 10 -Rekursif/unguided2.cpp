#include <iostream>

int faktorialA(int n);
int faktorialB(int n);

int faktorialA(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * faktorialB(n - 1);
    }
}

int faktorialB(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return faktorialA(n);
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

    int hasil = faktorialA(bilangan);

    std::cout << "Faktorial dari " << bilangan << " adalah: " << hasil << std::endl;

    return 0;
}
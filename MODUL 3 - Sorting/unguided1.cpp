#include <iostream>

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        double temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    double IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(IPS) / sizeof(IPS[0]);

    selectionSort(IPS, n);

    std::cout << "\nNilai setelah diurutkan:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Mahasiswa " << i + 1 << ": " << IPS[i] << std::endl;
    }

    return 0;
}
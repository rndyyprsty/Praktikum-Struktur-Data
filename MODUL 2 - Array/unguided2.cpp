#include <iostream>
using namespace std;

int main() {
    int size1, size2, size3;

    // Input ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size1 >> size2 >> size3;

    int arr[size1][size2][size3];

    // Input elemen array
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    cout << "Data Array:" << endl;
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    cout << "Tampilan Array:" << endl;
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
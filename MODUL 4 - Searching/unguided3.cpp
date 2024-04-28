#include <iostream>
#include <vector>

using namespace std;

int hitungEmpat(const vector<int> &data) {
    int hitung = 0;
    for (int num : data) {
        if (num == 4) {
            hitung++;
        }
    }
    return hitung;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    
    int jumlahEmpat = hitungEmpat(data);
    
    cout << "Jumlah angka 4 ada: " << jumlahEmpat << endl;
    
    return 0;
}
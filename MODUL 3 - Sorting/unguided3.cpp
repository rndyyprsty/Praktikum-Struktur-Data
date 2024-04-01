#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter: ";
    cin >> n;
    
    char karakter[n];
    
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> karakter[i];
    }
    
    sort(karakter, karakter + n);
    
    cout << "Sorting Ascending: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }
    cout << endl;
    
    sort(karakter, karakter + n, greater<char>());
    
    cout << "Sorting Descending: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }
    cout << endl;
    
    return 0;
}
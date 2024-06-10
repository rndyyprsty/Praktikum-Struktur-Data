#include <iostream>
using namespace std;

void sequential(int arr[], int n, int x) {
    bool ketemu = false;
    cout << "nilai " << x << " ada di index: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << i << " ";
            ketemu = true;
        }
    }
    if (!ketemu) {
        cout << "ga ada.";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    sequential(arr, n, x);
    return 0;
}
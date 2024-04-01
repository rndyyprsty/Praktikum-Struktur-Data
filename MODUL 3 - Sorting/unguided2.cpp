#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names) / sizeof(names[0]);

    bubbleSort(names, n);

    cout << "Sesudah Diurutkan:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << names[i] << " ";
    }
    cout << endl;

    return 0;
}
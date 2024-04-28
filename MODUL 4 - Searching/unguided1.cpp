#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// melakukan binary search pada string
bool binarySearch(const string &str, char target) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (str[mid] == target)
            return true;
        else if (str[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}

int main() {
    string sentence = "ayam geprek enak.";
    cout << "Kalimatnya: " << sentence << endl;
    char searchChar;
    
    // Mengurutkan kalimat
    sort(sentence.begin(), sentence.end());
    
    // Mencari huruf
    cout << "cari huruf: ";
    cin >> searchChar;
    
    bool found = binarySearch(sentence, searchChar);
    
    if (found)
        cout << "Huruf ada." << endl;
    else
        cout << "Huruf tidak ada." << endl;
    
    return 0;
}
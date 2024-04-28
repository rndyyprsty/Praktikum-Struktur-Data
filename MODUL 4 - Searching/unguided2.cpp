#include <iostream>
#include <string>

using namespace std;

int hitungVokal(const string &kalimat) {
    int jumlahVokal = 0;
    for (char ch : kalimat) {
        // mengatur huruf jadi lowercase
        char lowercaseCh = tolower(ch);
        // mengecek huruf vokal
        if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    string kalimat = "ayo main star rail.";
    cout << "Kalimatnya: " << kalimat << endl;
    
    int jumlahVokal = hitungVokal(kalimat);
    
    cout << "jumlah huruf vokal ada: " << jumlahVokal << endl;
    
    return 0;
}
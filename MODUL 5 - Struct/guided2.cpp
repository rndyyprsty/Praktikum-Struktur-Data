#include <iostream>
#include <string>
using namespace std;

struct HewanDarat {
    int Jumlah_Kaki;
    bool Apakah_menyusui;
    string Suara;
};

struct HewanLaut {
    string Bentuk_sirip;
    string Bentuk_pertahanan_diri;
};

struct Hewan {
    string Nama_hewan;
    string Jenis_kelamin;
    string Cara_berkembangbiak;
    string Alat_pernafasan;
    string Tempat_hidup;
    bool Apakah_Karnivora;
    HewanDarat darat_detail;
    HewanLaut laut_detail;
};

int main() {
    // Objek hewan darat
    Hewan hewan_darat;
    hewan_darat.Nama_hewan = "Lynx";
    hewan_darat.Jenis_kelamin = "Betina";
    hewan_darat.Cara_berkembangbiak = "Melahirkan";
    hewan_darat.Alat_pernafasan = "Paru-paru";
    hewan_darat.Tempat_hidup = "Hutan";
    hewan_darat.Apakah_Karnivora = true;
    hewan_darat.darat_detail.Jumlah_Kaki = 4;
    hewan_darat.darat_detail.Apakah_menyusui = true;
    hewan_darat.darat_detail.Suara = "Roar";

    // Objek hewan laut
    Hewan hewan_laut;
    hewan_laut.Nama_hewan = "Hiu BaNtEnG";
    hewan_laut.Jenis_kelamin = "Jantan";
    hewan_laut.Cara_berkembangbiak = "Bertelur";
    hewan_laut.Alat_pernafasan = "Insang";
    hewan_laut.Tempat_hidup = "Laut";
    hewan_laut.Apakah_Karnivora = true;
    hewan_laut.laut_detail.Bentuk_sirip = "Berkurang";
    hewan_laut.laut_detail.Bentuk_pertahanan_diri = "Sirip ekor panjang";

    // Tampil hasil
    cout << "Informasi Hewan Darat:" << endl;
    cout << "Nama: " << hewan_darat.Nama_hewan << endl;
    cout << "Jenis Kelamin: " << hewan_darat.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak: " << hewan_darat.Cara_berkembangbiak << endl;
    cout << "Alat Pernafasan: " << hewan_darat.Alat_pernafasan << endl;
    cout << "Tempat Hidup: " << hewan_darat.Tempat_hidup << endl;
    cout << "Apakah Karnivora: " << (hewan_darat.Apakah_Karnivora ? "Ya" : "Tidak") << endl;
    cout << "Jumlah Kaki: " << hewan_darat.darat_detail.Jumlah_Kaki << endl;
    cout << "Apakah Menyusui: " << (hewan_darat.darat_detail.Apakah_menyusui ? "Ya" : "Tidak") << endl;
    cout << "Suara: " << hewan_darat.darat_detail.Suara << endl;

    cout << "\nInformasi Hewan Laut:" << endl;
    cout << "Nama: " << hewan_laut.Nama_hewan << endl;
    cout << "Jenis Kelamin: " << hewan_laut.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak: " << hewan_laut.Cara_berkembangbiak << endl;
    cout << "Alat Pernafasan: " << hewan_laut.Alat_pernafasan << endl;
    cout << "Tempat Hidup: " << hewan_laut.Tempat_hidup << endl;
    cout << "Apakah Karnivora: " << (hewan_laut.Apakah_Karnivora ? "Ya" : "Tidak") << endl;
    cout << "Bentuk Sirip: " << hewan_laut.laut_detail.Bentuk_sirip << endl;
    cout << "Bentuk Pertahanan Diri: " << hewan_laut.laut_detail.Bentuk_pertahanan_diri << endl;

    return 0;
}
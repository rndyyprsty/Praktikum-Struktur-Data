#include <iostream>
#include <string>

// Contoh penggunaan class
class Mahasiswa {
private:
    std::string nama;
    int umur;
public:
    void setNama(std::string n) {
        nama = n;
    }
    void setUmur(int u) {
        umur = u;
    }
    void display() {
        std::cout << "Nama: " << nama << ", Umur: " << umur << std::endl;
    }
};

// Contoh penggunaan struct
struct Person {
    std::string name;
    int age;
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Mahasiswa mhs;
    mhs.setNama("Sherlock");
    mhs.setUmur(20);
    mhs.display();

    Person person;
    person.name = "Watson";
    person.age = 25;
    person.display();

    return 0;
}
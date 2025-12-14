#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;

    Contact(string n, string p) {
        name = n;
        phone = p;
    }
};

class Phonebook {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        string name, phone;
        cin.ignore();
        cout << "Masukkan nama  : ";
        getline(cin, name);
        cout << "Masukkan nomor : ";
        getline(cin, phone);

        contacts.push_back(Contact(name, phone));
        cout << "Kontak berhasil ditambahkan.\n";
    }

    void showContacts() {
        if (contacts.empty()) {
            cout << "Tidak ada kontak.\n";
            return;
        }

        for (int i = 0; i < contacts.size(); i++) {
            cout << i + 1 << ". "
                 << contacts[i].name << " - "
                 << contacts[i].phone << endl;
        }
    }

    // 🔍 Cari kontak (nama / nomor)
    void searchContact() {
        string keyword;
        cin.ignore();
        cout << "Masukkan nama atau nomor yang dicari: ";
        getline(cin, keyword);

        bool found = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == keyword || contacts[i].phone == keyword) {
                cout << "\nKontak ditemukan:\n";
                cout << "Nama  : " << contacts[i].name << endl;
                cout << "Nomor : " << contacts[i].phone << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Kontak tidak ditemukan.\n";
        }
    }

    // ✏ Edit kontak
    void editContact() {
        showContacts();
        if (contacts.empty()) return;

        int index;
        cout << "Pilih nomor kontak yang akan diedit: ";
        cin >> index;

        if (index < 1 || index > contacts.size()) {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cin.ignore();
        cout << "Masukkan nama baru  : ";
        getline(cin, contacts[index - 1].name);
        cout << "Masukkan nomor baru : ";
        getline(cin, contacts[index - 1].phone);

        cout << "Kontak berhasil diperbarui.\n";
    }

    // 🗑 Hapus kontak
    void deleteContact() {
        showContacts();
        if (contacts.empty()) return;

        int index;
        cout << "Pilih nomor kontak yang akan dihapus: ";
        cin >> index;

        if (index < 1 || index > contacts.size()) {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        contacts.erase(contacts.begin() + index - 1);
        cout << "Kontak berhasil dihapus.\n";
    }
};

int main() {
    Phonebook pb;
    int choice;

    do {
        cout << "\n=== MENU PHONEBOOK ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Edit Kontak\n";
        cout << "5. Hapus Kontak\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
        case 1:
            pb.addContact();
            break;
        case 2:
            pb.showContacts();
            break;
        case 3:
            pb.searchContact();
            break;
        case 4:
            pb.editContact();
            break;
        case 5:
            pb.deleteContact();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan Phonebook.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string jurusan;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

void tambahMahasiswa(string nama, string nim, string jurusan) {
    Mahasiswa* baru = new Mahasiswa();
    baru->nama = nama;
    baru->nim = nim;
    baru->jurusan = jurusan;
    baru->next = head;
    head = baru;
}

void tampilkanMahasiswa() {
    Mahasiswa* temp = head;
    cout << "\nDaftar Mahasiswa:\n";
    while (temp != NULL) {
        cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << ", Jurusan: " << temp->jurusan << endl;
        temp = temp->next;
    }
}

void cariMahasiswa(string nim) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (temp->nim == nim) {
            cout << "Mahasiswa ditemukan: Nama: " << temp->nama << ", Jurusan: " << temp->jurusan << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

void hapusMahasiswa(string nim) {
    Mahasiswa *temp = head, *prev = NULL;

    if (temp != NULL && temp->nim == nim) {
        head = temp->next;
        delete temp;
        cout << "Mahasiswa berhasil dihapus.\n";
        return;
    }

    while (temp != NULL && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Mahasiswa berhasil dihapus.\n";
}

void menu() {
    int pilihan;
    string nama, nim, jurusan;

    do {
        cout << "\n=== Menu Sistem Data Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Semua Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama: "; cin.ignore(); getline(cin, nama);
                cout << "NIM: "; getline(cin, nim);
                cout << "Jurusan: "; getline(cin, jurusan);
                tambahMahasiswa(nama, nim, jurusan);
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 3:
                cout << "Masukkan NIM yang dicari: "; cin.ignore(); getline(cin, nim);
                cariMahasiswa(nim);
                break;
            case 4:
                cout << "Masukkan NIM yang dihapus: "; cin.ignore(); getline(cin, nim);
                hapusMahasiswa(nim);
                break;
            case 5:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}

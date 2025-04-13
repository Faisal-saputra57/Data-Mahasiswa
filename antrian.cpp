#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> antrian;

void tambahPasien() {
    string nama;
    cout << "Masukkan nama pasien: ";
    cin.ignore();
    getline(cin, nama);
    antrian.push(nama);
    cout << "Pasien atas nama " << nama << " berhasil ditambahkan ke antrian.\n";
}

void layaniPasien() {
    if (!antrian.empty()) {
        cout << "Pasien atas nama " << antrian.front() << " sedang dilayani.\n";
        antrian.pop();
    } else {
        cout << "Antrian kosong. Tidak ada pasien yang dilayani.\n";
    }
}

void tampilkanAntrian() {
    if (antrian.empty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\nDaftar Antrian Pasien:\n";
    queue<string> temp = antrian;
    int nomor = 1;
    while (!temp.empty()) {
        cout << nomor++ << ". " << temp.front() << endl;
        temp.pop();
    }
}

void jumlahPasien() {
    cout << "Jumlah pasien dalam antrian: " << antrian.size() << endl;
}

void menu() {
    int pilihan;
    do {
        cout << "\n=== Sistem Antrian Rumah Sakit ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Layani Pasien\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Jumlah Pasien dalam Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPasien();
                break;
            case 2:
                layaniPasien();
                break;
            case 3:
                tampilkanAntrian();
                break;
            case 4:
                jumlahPasien();
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

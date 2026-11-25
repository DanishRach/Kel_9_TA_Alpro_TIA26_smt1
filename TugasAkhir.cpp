// Sistem Manajemen Jadwal Mingguan dan Tugas Mahasiswa

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ================= DATA =================

enum Status { BELUM, PROSES, SELESAI };
enum Prioritas { RENDAH, SEDANG, TINGGI };

struct Tanggal {
    int hari, bulan, tahun;
};

union Detail {
    int jumlahHalaman;
    char linkTugas[50];
};

struct Tugas {
    int id;
    string judul;
    string matkul;
    Tanggal deadline;
    Prioritas prioritas;
    Status status;
    int jenis;
    Detail detail;
};

Tugas *daftarTugas = NULL;
int jumlahTugas = 0;
int kapasitas = 2;
int idBerikutnya = 1;
Tanggal hariIni;

string jadwal[7][3];
string namaHari[7] = {
    "Senin", "Selasa", "Rabu", "Kamis",
    "Jumat", "Sabtu", "Minggu"
};

// ================= FUNGSI BANTU =================

string namaStatus(Status s) {
    if (s == BELUM) return "Belum";
    if (s == PROSES) return "Proses";
    return "Selesai";
}

string namaPrioritas(Prioritas p) {
    if (p == RENDAH) return "Rendah";
    if (p == SEDANG) return "Sedang";
    return "Tinggi";
}

int bacaAngka(string pesan, int minimum, int maksimum) {
    int angka;
    while (true) {
        cout << pesan;
        cin >> angka;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!\n";
        } else if (angka < minimum || angka > maksimum) {
            cout << "Angka harus antara " << minimum
                 << " dan " << maksimum << "!\n";
        } else {
            cin.ignore(1000, '\n');
            return angka;
        }
    }
}

// Setiap bagian ada di file masing-masing
#include "bagian_danish.h"
#include "bagian_ali.h"
#include "bagian_danis.h"

// ================= MENU UTAMA =================

void tampilMenu() {
    cout << "\n===== MANAJEMEN JADWAL DAN TUGAS MAHASISWA =====\n";
    cout << "1. Tambah tugas\n";
    cout << "2. Lihat semua tugas\n";
    cout << "3. Ubah status tugas\n";
    cout << "4. Hapus tugas\n";
    cout << "5. Cari tugas (per mata kuliah)\n";
    cout << "6. Urutkan tugas\n";
    cout << "7. Lihat jadwal kuliah mingguan\n";
    cout << "8. Cek deadline\n";
    cout << "0. Keluar\n";
}

int main() {
    siapkanArray();
    isiJadwal();
    isiDataContoh();

    cout << "Masukkan tanggal hari ini:\n";
    hariIni.hari = bacaAngka("  Tanggal (1-31) : ", 1, 31);
    hariIni.bulan = bacaAngka("  Bulan (1-12)   : ", 1, 12);
    hariIni.tahun = bacaAngka("  Tahun          : ", 2026, 2100);

    int pilihan;
    do {
        tampilMenu();
        pilihan = bacaAngka("Pilih menu: ", 0, 8);

        switch (pilihan) {
            case 1: tambahTugas(); break;
            case 2: tampilTugas(); break;
            case 3: menuUbahStatus(); break;
            case 4: hapusTugas(); break;
            case 5: cariTugas(); break;
            case 6: urutkanTugas(); break;
            case 7: tampilJadwal(); break;
            case 8: cekDeadline(); break;
            case 0:
                cout << "Terima kasih, program selesai.\n";
                break;
        }
    } while (pilihan != 0);

    delete[] daftarTugas;
    return 0;
}

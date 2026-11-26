
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
        }
        else if (angka < minimum || angka > maksimum) {
            cout << "Angka harus antara " << minimum
                 << " dan " << maksimum << "!\n";
        }
        else {
            cin.ignore(1000, '\n');
            return angka;
        }
    }
}

// ================= ARRAY DINAMIS =================

void siapkanArray() {
    daftarTugas = new Tugas[kapasitas];
}

void perbesarArray() {
    int kapasitasBaru = kapasitas * 2;
    Tugas *baru = new Tugas[kapasitasBaru];

    for (int i = 0; i < jumlahTugas; i++) {
        baru[i] = daftarTugas[i];
    }

    delete[] daftarTugas;
    daftarTugas = baru;
    kapasitas = kapasitasBaru;
}

// ================= FITUR UTAMA =================

// Menambahkan tugas baru
void tambahTugas() {
    if (jumlahTugas == kapasitas) {
        perbesarArray();
    }

    Tugas t;
    t.id = idBerikutnya;

    cout << "\n--- Tambah Tugas Baru ---\n";

    cout << "Judul tugas : ";
    getline(cin, t.judul);

    cout << "Mata kuliah : ";
    getline(cin, t.matkul);

    cout << "Deadline:\n";

    t.deadline.hari = bacaAngka("  Tanggal (1-31) : ", 1, 31);
    t.deadline.bulan = bacaAngka("  Bulan (1-12)   : ", 1, 12);
    t.deadline.tahun = bacaAngka("  Tahun          : ", 2026, 2100);

    int p = bacaAngka(
        "Prioritas (1=Rendah, 2=Sedang, 3=Tinggi): ", 1, 3
    );

    t.prioritas = (Prioritas)(p - 1);
    t.status = BELUM;

    t.jenis = bacaAngka(
        "Jenis tugas (1=Tulis, 2=Online): ", 1, 2
    );

    if (t.jenis == 1) {
        t.detail.jumlahHalaman = bacaAngka(
            "Jumlah halaman : ", 1, 1000
        );
    }
    else {
        cout << "Link tugas     : ";
        cin.getline(t.detail.linkTugas, 50);
    }

    daftarTugas[jumlahTugas] = t;

    jumlahTugas++;
    idBerikutnya++;

    cout << "Tugas berhasil ditambahkan!\n";
}

// Menampilkan seluruh tugas
void tampilTugas() {
    cout << "\n--- Daftar Tugas ---\n";

    if (jumlahTugas == 0) {
        cout << "Belum ada tugas.\n";
        return;
    }

    cout << left << setw(4) << "ID"
         << setw(22) << "Judul"
         << setw(18) << "Matkul"
         << setw(12) << "Deadline"
         << setw(10) << "Prioritas"
         << setw(8) << "Status" << endl;

    cout << string(74, '-') << endl;

    for (int i = 0; i < jumlahTugas; i++) {
        Tugas *t = &daftarTugas[i];

        string tgl = to_string(t->deadline.hari) + "/" +
                     to_string(t->deadline.bulan) + "/" +
                     to_string(t->deadline.tahun);

        cout << left << setw(4) << t->id
             << setw(22) << t->judul
             << setw(18) << t->matkul
             << setw(12) << tgl
             << setw(10) << namaPrioritas(t->prioritas)
             << setw(8) << namaStatus(t->status) << endl;
    }
}

// Mengubah status tugas menggunakan pointer
void ubahStatus(Tugas *t, Status statusBaru) {
    t->status = statusBaru;
}

// Menu untuk mengubah status tugas
void menuUbahStatus() {
    tampilTugas();

    if (jumlahTugas == 0) return;

    int id = bacaAngka("\nMasukkan ID tugas: ", 1, 100000);

    for (int i = 0; i < jumlahTugas; i++) {
        if (daftarTugas[i].id == id) {
            int s = bacaAngka(
                "Status baru (1=Belum, 2=Proses, 3=Selesai): ",
                1, 3
            );

            ubahStatus(&daftarTugas[i], (Status)(s - 1));

            cout << "Status berhasil diubah.\n";
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

// Menghapus tugas berdasarkan ID
void hapusTugas() {
    tampilTugas();

    if (jumlahTugas == 0) return;

    int id = bacaAngka(
        "\nMasukkan ID tugas yang dihapus: ", 1, 100000
    );

    for (int i = 0; i < jumlahTugas; i++) {
        if (daftarTugas[i].id == id) {
            for (int j = i; j < jumlahTugas - 1; j++) {
                daftarTugas[j] = daftarTugas[j + 1];
            }

            jumlahTugas--;

            cout << "Tugas berhasil dihapus.\n";
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

// Menambahkan tiga data contoh
void isiDataContoh() {
    string judul[3] = {
        "Laprak Looping",
        "Esai K3 Burnout",
        "Proposal PKM"
    };

    string matkul[3] = {
        "Alpro", "K3", "PKM"
    };

    int hari[3] = {20, 25, 30};

    for (int i = 0; i < 3; i++) {
        if (jumlahTugas == kapasitas) {
            perbesarArray();
        }

        Tugas t;

        t.id = idBerikutnya++;
        t.judul = judul[i];
        t.matkul = matkul[i];

        t.deadline.hari = hari[i];
        t.deadline.bulan = 11;
        t.deadline.tahun = 2026;

        t.prioritas = (Prioritas)i;
        t.status = BELUM;

        t.jenis = 1;
        t.detail.jumlahHalaman = 5 + i;

        daftarTugas[jumlahTugas++] = t;
    }
}

// ================= SORTING =================

// Menukar dua data tugas menggunakan pointer
void tukar(Tugas *a, Tugas *b) {
    Tugas sementara = *a;
    *a = *b;
    *b = sementara;
}

// Mengurutkan tugas menggunakan Bubble Sort
void urutkanTugas() {
    if (jumlahTugas == 0) {
        cout << "Belum ada tugas untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlahTugas - 1; i++) {
        for (int j = 0; j < jumlahTugas - i - 1; j++) {
            int tanggal1 = daftarTugas[j].deadline.tahun * 10000 +
                           daftarTugas[j].deadline.bulan * 100 +
                           daftarTugas[j].deadline.hari;

            int tanggal2 = daftarTugas[j + 1].deadline.tahun * 10000 +
                           daftarTugas[j + 1].deadline.bulan * 100 +
                           daftarTugas[j + 1].deadline.hari;

            if (tanggal1 > tanggal2) {
                tukar(&daftarTugas[j], &daftarTugas[j + 1]);
            }
        }
    }

    cout << "\nTugas berhasil diurutkan berdasarkan deadline terdekat.\n";

    tampilTugas();
}

// ================= SEARCHING =================

// Mencari tugas berdasarkan nama mata kuliah
void cariTugas() {
    cout << "\n--- Cari Tugas Berdasarkan Mata Kuliah ---\n";

    if (jumlahTugas == 0) {
        cout << "Belum ada tugas.\n";
        return;
    }

    string cariMatkul;

    cout << "Masukkan nama mata kuliah: ";
    getline(cin, cariMatkul);

    bool ditemukan = false;

    for (int i = 0; i < jumlahTugas; i++) {
        if (daftarTugas[i].matkul == cariMatkul) {
            if (!ditemukan) {
                cout << "\nTugas dari mata kuliah "
                     << cariMatkul << ":\n";

                cout << left << setw(4) << "ID"
                     << setw(22) << "Judul"
                     << setw(18) << "Matkul"
                     << setw(12) << "Deadline"
                     << setw(10) << "Prioritas"
                     << setw(8) << "Status" << endl;

                cout << string(74, '-') << endl;
            }

            Tugas *t = &daftarTugas[i];

            string tgl = to_string(t->deadline.hari) + "/" +
                         to_string(t->deadline.bulan) + "/" +
                         to_string(t->deadline.tahun);

            cout << left << setw(4) << t->id
                 << setw(22) << t->judul
                 << setw(18) << t->matkul
                 << setw(12) << tgl
                 << setw(10) << namaPrioritas(t->prioritas)
                 << setw(8) << namaStatus(t->status) << endl;

            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tugas tidak ditemukan.\n";
    }
}

// ================= CEK DEADLINE =================

// Menghitung sisa hari antara deadline dan hari ini
int hitungSisaHari(Tanggal deadline) {
    int angkaDeadline = deadline.tahun * 365 +
                        deadline.bulan * 30 +
                        deadline.hari;

    int angkaHariIni = hariIni.tahun * 365 +
                       hariIni.bulan * 30 +
                       hariIni.hari;

    return angkaDeadline - angkaHariIni;
}

// Mengecek tugas yang hampir atau sudah melewati deadline
void cekDeadline() {
    cout << "\n--- Cek Deadline Tugas ---\n";

    if (jumlahTugas == 0) {
        cout << "Belum ada tugas.\n";
        return;
    }

    bool adaTugasBelumSelesai = false;

    for (int i = 0; i < jumlahTugas; i++) {
        if (daftarTugas[i].status == SELESAI) {
            continue;
        }

        adaTugasBelumSelesai = true;

        int sisaHari = hitungSisaHari(
            daftarTugas[i].deadline
        );

        cout << "\nJudul tugas : "
             << daftarTugas[i].judul << endl;

        cout << "Mata kuliah : "
             << daftarTugas[i].matkul << endl;

        cout << "Deadline    : "
             << daftarTugas[i].deadline.hari << "/"
             << daftarTugas[i].deadline.bulan << "/"
             << daftarTugas[i].deadline.tahun << endl;

        if (sisaHari < 0) {
            cout << "Status      : SUDAH LEWAT DEADLINE ("
                 << -sisaHari << " hari yang lalu)\n";
        }
        else if (sisaHari <= 3) {
            cout << "Status      : HAMPIR DEADLINE ("
                 << sisaHari << " hari lagi)\n";
        }
        else {
            cout << "Status      : Masih aman ("
                 << sisaHari << " hari lagi)\n";
        }
    }

    if (!adaTugasBelumSelesai) {
        cout << "Semua tugas sudah selesai.\n";
    }
}

// ================= MENU UTAMA =================

void tampilMenu() {
    cout << "\n===== SISTEM MANAJEMEN TUGAS MAHASISWA =====\n";

    cout << "1. Tambah tugas\n";
    cout << "2. Lihat semua tugas\n";
    cout << "3. Ubah status tugas\n";
    cout << "4. Hapus tugas\n";
    cout << "5. Cari tugas (per mata kuliah)\n";
    cout << "6. Urutkan tugas\n";
    cout << "7. Cek deadline\n";
    cout << "0. Keluar\n";
}

// ================= MAIN =================

int main() {
    siapkanArray();
    isiDataContoh();

    cout << "Masukkan tanggal hari ini:\n";

    hariIni.hari = bacaAngka("  Tanggal (1-31) : ", 1, 31);
    hariIni.bulan = bacaAngka("  Bulan (1-12)   : ", 1, 12);
    hariIni.tahun = bacaAngka("  Tahun          : ", 2026, 2100);

    int pilihan;

    do {
        tampilMenu();

        pilihan = bacaAngka("Pilih menu: ", 0, 7);

        switch (pilihan) {
            case 1:
                tambahTugas();
                break;

            case 2:
                tampilTugas();
                break;

            case 3:
                menuUbahStatus();
                break;

            case 4:
                hapusTugas();
                break;

            case 5:
                cariTugas();
                break;

            case 6:
                urutkanTugas();
                break;

            case 7:
                cekDeadline();
                break;

            case 0:
                cout << "Terima kasih, program selesai.\n";
                break;
        }

    } while (pilihan != 0);

    delete[] daftarTugas;

    return 0;
}

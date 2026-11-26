# Sistem Manajemen Tugas Mahasiswa

Program berbasis console (C++) untuk mencatat, mengelola, dan memantau tugas kuliah mahasiswa. Dibuat sebagai Tugas Akhir mata kuliah Algoritma dan Pemrograman.

Data tugas hanya tersimpan selama program berjalan (belum menggunakan database atau file eksternal). Program menyediakan 3 data contoh agar fitur bisa langsung dicoba.

## Fitur

| Menu | Fitur | Keterangan |
|---|---|---|
| 1 | Tambah tugas | Input judul, mata kuliah, deadline, prioritas, dan jenis tugas |
| 2 | Lihat semua tugas | Menampilkan seluruh tugas dalam bentuk tabel |
| 3 | Ubah status tugas | Mengubah status menjadi Belum, Proses, atau Selesai berdasarkan ID |
| 4 | Hapus tugas | Menghapus tugas berdasarkan ID |
| 5 | Cari tugas | Mencari tugas berdasarkan nama mata kuliah |
| 6 | Urutkan tugas | Mengurutkan tugas berdasarkan deadline terdekat |
| 7 | Cek deadline | Menampilkan tugas yang sudah lewat, hampir, atau masih aman dari deadline |
| 0 | Keluar | Menutup program |

## Materi yang Diterapkan

| Materi | Penerapan |
|---|---|
| Input/Output | `cin`, `getline`, `cout`, dan `setw` untuk menampilkan tabel |
| Struktur kontrol | `if-else` untuk pengecekan deadline dan validasi, `switch-case` untuk menu |
| Perulangan | `do-while` untuk menu, `for` dan `while` untuk pengolahan data dan validasi input |
| Function | Menggunakan fungsi terpisah untuk setiap fitur program |
| Array | Array untuk menyimpan data contoh tugas |
| Pointer | Mengubah status tugas dan menukar data saat sorting |
| Array dinamis | Daftar tugas menggunakan `new`, kapasitas bertambah otomatis saat penuh, dan `delete[]` untuk membebaskan memori |
| Struct, Union, Enum | `struct Tugas`, `struct Tanggal`, `enum Status`, `enum Prioritas`, dan `union Detail` untuk menyimpan jumlah halaman atau link tugas |
| Searching | Linear Search untuk mencari tugas berdasarkan mata kuliah |
| Sorting | Bubble Sort untuk mengurutkan tugas berdasarkan deadline |

## Pembagian Tugas

| Anggota | File | Fungsi |
|---|---|---|
| Danish | `bagian_danish.h` | `siapkanArray`, `perbesarArray`, `tambahTugas`, `tampilTugas`, `ubahStatus`, `menuUbahStatus`, `hapusTugas`, `isiDataContoh` |
| Ali | `bagian_ali.h` | `tukar`, `urutkanTugas`, `cariTugas` |
| Danis | `bagian_danis.h` | `hitungSisaHari`, `cekDeadline` |

## Cara Menjalankan

Jika menggunakan versi satu file, simpan kode program sebagai `main.cpp`, kemudian compile:

```bash
g++ main.cpp -o program
```

Jalankan program:

```bash
./program       # Linux/Mac
program.exe     # Windows
```

Jika menggunakan Code::Blocks atau Dev-C++, buka `main.cpp`, kemudian klik Build and Run.

## Cara Memakai

1. Saat program dimulai, masukkan tanggal hari ini (tanggal, bulan, dan tahun).
2. Pilih menu dengan mengetik angka 0–7.
3. Program menyediakan 3 data contoh:
   - Laprak Looping — Alpro — 20 November 2026.
   - Esai K3 Burnout — K3 — 25 November 2026.
   - Proposal PKM — PKM — 30 November 2026.
4. Gunakan menu 1 untuk menambahkan tugas baru.
5. Gunakan menu 6 untuk mengurutkan tugas berdasarkan deadline.
6. Gunakan menu 7 untuk memantau status deadline tugas.

**Catatan:** Perhitungan sisa hari menggunakan pendekatan 30 hari per bulan, sehingga hasilnya belum sepenuhnya akurat mengikuti kalender sebenarnya. Data tugas juga akan hilang ketika program ditutup.
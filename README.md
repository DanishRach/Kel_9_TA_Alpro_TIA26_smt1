# Sistem Manajemen Jadwal Mingguan dan Tugas Mahasiswa

Program berbasis console (C++) untuk mencatat tugas kuliah dan melihat jadwal kuliah mingguan dalam satu tempat. Dibuat sebagai Tugas Akhir mata kuliah Algoritma dan Pemrograman.

Data tugas hanya tersimpan selama program berjalan. Program ini sudah menyediakan 3 data contoh agar fitur bisa langsung dicoba.

## Fitur

| Menu | Fitur | Keterangan |
|---|---|---|
| 1 | Tambah tugas | Input judul, mata kuliah, deadline, prioritas, dan jenis tugas |
| 2 | Lihat semua tugas | Ditampilkan dalam bentuk tabel |
| 3 | Ubah status tugas | Belum, Proses, atau Selesai (berdasarkan ID) |
| 4 | Hapus tugas | Berdasarkan ID |
| 5 | Cari tugas | Mencari tugas berdasarkan nama mata kuliah |
| 6 | Urutkan tugas | Diurutkan dari deadline terdekat |
| 7 | Jadwal kuliah mingguan | Jadwal 7 hari dengan 3 sesi per hari |
| 8 | Cek deadline | Menandai tugas yang sudah lewat, hampir, atau masih aman |
| 0 | Keluar | Menutup program |

## Materi yang Diterapkan

| Materi | Penerapan |
|---|---|
| Input/Output | `cin`, `getline`, `cout`, `setw` untuk tabel |
| Struktur kontrol | `if-else` untuk cek deadline dan validasi, `switch-case` untuk menu |
| Perulangan | `do-while` untuk menu, `for` dan `while` untuk data dan validasi input |
| Function | Satu fungsi untuk setiap fitur |
| Array | `jadwal[7][3]` untuk jadwal kuliah mingguan |
| Pointer | Mengubah status tugas dan menukar data saat sorting |
| Array dinamis | Daftar tugas memakai `new`, membesar otomatis saat penuh, `delete[]` di akhir |
| Struct, union, enum | `struct Tugas`, `enum Status` dan `Prioritas`, `union Detail` (jumlah halaman atau link) |
| Searching | Pencarian linear berdasarkan mata kuliah |
| Sorting | Bubble sort berdasarkan deadline |

## Pembagian Tugas

| Anggota | File | Fungsi |
|---|---|---|
| Danish | `bagian_danish.h` | `siapkanArray`, `perbesarArray`, `tambahTugas`, `tampilTugas`, `ubahStatus`, `menuUbahStatus`, `hapusTugas`, `isiDataContoh` |
| Ali | `bagian_ali.h` | `tukar`, `urutkanTugas`, `cariTugas` |
| Danis | `bagian_danis.h` | `hitungSisaHari`, `cekDeadline`, `isiJadwal`, `tampilJadwal` |

## Cara Menjalankan

Pastikan keempat file berada di satu folder, lalu compile `main.cpp` saja:

```bash
g++ main.cpp -o program
./program        # Linux/Mac
program.exe      # Windows
```

Jika memakai Code::Blocks atau Dev-C++, buka `main.cpp` lalu klik Build and Run.

## Cara Memakai

1. Saat program mulai, masukkan tanggal hari ini (tanggal, bulan, tahun).
2. Pilih menu dengan mengetik angka 0-8.
3. Data contoh punya deadline 20, 25, dan 30 November 2026. Isi tanggal hari ini di sekitar tanggal itu untuk melihat ketiga kategori pada menu 8.

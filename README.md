# RosettaKos

**RosettaKos** adalah sistem manajemen kos sederhana berbasis terminal, ditulis dalam bahasa C++. Program ini dirancang untuk membantu pengelola kos dalam mengelola data kamar, penyewa, tagihan, dan pembayaran secara efisien.

---

## 🎯 Fitur Utama

1. **Manajemen Kamar**
   - Tambah kamar baru dengan informasi nomor, harga, dan status.
   - Lihat daftar kamar lengkap dengan statusnya (kosong/terisi).
   - Ubah status kamar ketika ada penyewa baru atau kamar kosong.

2. **Manajemen Tagihan**
   - Buat tagihan bulanan secara otomatis untuk kamar yang "terisi".
   - Lihat status tagihan (belum bayar/sudah bayar).
   - Perbarui status tagihan setelah pembayaran dilakukan.

3. **Manajemen Pembayaran**
   - Catat pembayaran baru dengan informasi detail.
   - Lihat pembayaran yang belum diverifikasi.
   - Verifikasi pembayaran untuk memperbarui status tagihan terkait.

4. **Menu Interaktif**
   - Antarmuka berbasis teks untuk administrator kos.

---

## 🛠️ Struktur Program

- **Konstanta**: Batas maksimum data untuk kamar, penyewa, tagihan, dan pembayaran.
- **Data Kamar**: Informasi kamar seperti nomor, harga, status, dan password.
- **Data Penyewa**: ID dan nama penyewa, serta kamar yang ditempati.
- **Data Tagihan**: ID tagihan, bulan, tahun, jumlah tagihan, dan status pembayaran.
- **Data Pembayaran**: ID pembayaran, tanggal, metode, jumlah pembayaran, dan status verifikasi.

---

## 🚀 Cara Menggunakan

1. **Clone Repository**
   ```bash
   git clone https://github.com/username/RosettaKos.git
   cd RosettaKos

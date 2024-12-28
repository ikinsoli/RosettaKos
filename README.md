# Dokumentasi Detail RosettaKos

## Informasi Kelompok
- **Nomor Kelompok**: 07
- **Nama & NIM Anggota**
1. Ikin Solihin - 24130300007 
2. Randi Ranata - 24130500004 
3. Muhammad Reza Nur Akbar - 24130500012 
4. Isfan Fazar Satria - 24130300011

## 1. KONSTANTA DAN ARRAY DASAR

### Konstanta
```cpp
const int MAX_KAMAR = 100;
const int MAX_PENYEWA = 100;
const int MAX_TAGIHAN = 200;
const int MAX_PEMBAYARAN = 300;
```
- `const int`: Tipe data konstanta integer yang nilainya tidak bisa diubah
- Digunakan untuk membatasi ukuran maksimum array
- Nilai bisa disesuaikan dengan kebutuhan sistem

### Array Global
```cpp
// Data Kamar
int nomorKamar[MAX_KAMAR];
double hargaKamar[MAX_KAMAR];
string statusKamar[MAX_KAMAR];
string passwordKamar[MAX_KAMAR];
int jumlahKamar = 0;
```
- Array parallel untuk menyimpan data kamar
- `jumlahKamar`: Counter untuk melacak jumlah kamar aktif
- `string`: Tipe data untuk teks (membutuhkan `#include <string>`)

## 2. FUNGSI MANAJEMEN KAMAR

### Fungsi tambahKamar()
```cpp
void tambahKamar() {
    if (jumlahKamar >= MAX_KAMAR) {
        cout << "Kapasitas kamar penuh!" << endl;
        return;
    }

    cout << "Masukkan nomor kamar: ";
    cin >> nomorKamar[jumlahKamar];
    // ...
    jumlahKamar++;
}
```
- `void`: Fungsi tidak mengembalikan nilai
- Pemeriksaan kapasitas dengan `if`
- `cin`: Input dari keyboard
- Increment `jumlahKamar` setelah penambahan

### Fungsi lihatDaftarKamar()
```cpp
void lihatDaftarKamar() {
    cout << "\n====== DAFTAR KAMAR ======" << endl;
    for (int i = 0; i < jumlahKamar; i++) {
        cout << (i+1) << ".\t" 
             << nomorKamar[i] << "\t"
             << hargaKamar[i] << "\t"
             << statusKamar[i] << endl;
    }
}
```
- Loop `for` untuk menampilkan semua data
- `\t`: Tab untuk format tabel
- `endl`: New line (baris baru)

## 3. FUNGSI MANAJEMEN TAGIHAN

### Fungsi buatTagihanBulanan()
```cpp
void buatTagihanBulanan() {
    string bulan;
    int tahun;
    
    cout << "Masukkan bulan (contoh: Januari): ";
    cin >> bulan;
    
    for (int i = 0; i < jumlahKamar; i++) {
        if (statusKamar[i] == "terisi") {
            // Membuat tagihan untuk kamar terisi
            idTagihan[jumlahDataTagihan] = jumlahDataTagihan + 1;
            // ...
        }
    }
}
```
- Membuat tagihan untuk semua kamar terisi
- Penggunaan string comparison (`==`)
- Auto-increment ID tagihan

## 4. FUNGSI MANAJEMEN PEMBAYARAN

### Fungsi catatPembayaran()
```cpp
void catatPembayaran() {
    if (jumlahDataPembayaran >= MAX_PEMBAYARAN) {
        cout << "Kapasitas data pembayaran penuh!" << endl;
        return;
    }
    
    cout << "Masukkan ID tagihan: ";
    cin >> tagihanPembayaran[jumlahDataPembayaran];
    // ...
    statusVerifikasi[jumlahDataPembayaran] = false;
}
```
- Validasi kapasitas
- Set status verifikasi awal = false
- Menggunakan index array terakhir (`jumlahDataPembayaran`)

### Fungsi verifikasiPembayaran()
```cpp
void verifikasiPembayaran() {
    int idPembayaranVerifikasi;
    cout << "Masukkan ID pembayaran yang akan diverifikasi: ";
    cin >> idPembayaranVerifikasi;
    
    for (int i = 0; i < jumlahDataPembayaran; i++) {
        if (idPembayaran[i] == idPembayaranVerifikasi) {
            if (!statusVerifikasi[i]) {
                statusVerifikasi[i] = true;
                updateStatusTagihan(tagihanPembayaran[i]);
                // ...
            }
        }
    }
}
```
- Pencarian ID menggunakan loop
- Pemeriksaan status ganda dengan nested if
- Pemanggilan fungsi lain (`updateStatusTagihan`)

## 5. MENU DAN NAVIGASI

### Fungsi menuAdmin()
```cpp
void menuAdmin() {
    while (true) {
        cout << "\n====== MENU ADMIN ======" << endl;
        cout << "1. Manajemen Kamar" << endl;
        // ...
        
        int pilihan;
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: {
                // Sub-menu Manajemen Kamar
                break;
            }
            case 0: return;
        }
    }
}
```
- `while(true)`: Loop infinite untuk menu
- `switch-case`: Percabangan menu
- Nested menu dengan sub-pilihan
- `return`: Keluar dari fungsi

## 6. TIPS PENGGUNAAN

1. Array Parallel:
   - Index array harus selalu sinkron
   - Gunakan counter global (`jumlahKamar`, dll)
   - Validasi index sebelum akses

2. Input/Output:
   - Selalu validasi input
   - Berikan feedback ke user
   - Format output untuk keterbacaan

3. Verifikasi Data:
   - Periksa kapasitas array
   - Validasi relasi antar data
   - Handle error cases

4. Best Practices:
   - Komentar untuk kode kompleks
   - Nama variabel yang deskriptif
   - Konsisten dalam format

## 7. CONTOH PENGGUNAAN

```cpp
int main() {
    // Tambah kamar
    tambahKamar();  // Input: nomor=101, harga=500000
    tambahKamar();  // Input: nomor=102, harga=600000
    
    // Buat tagihan
    buatTagihanBulanan();  // Input: bulan=Januari, tahun=2024
    
    // Catat pembayaran
    catatPembayaran();  // Input: ID tagihan=1, jumlah=500000
    
    // Verifikasi
    verifikasiPembayaran();  // Input: ID pembayaran=1
    
    return 0;
}
```

## 8. TROUBLESHOOTING UMUM

1. Array Full:
   - Periksa nilai MAX_* 
   - Clear data lama jika perlu

2. Data Tidak Sinkron:
   - Periksa index array
   - Validasi counter global

3. Input Error:
   - Tambahkan validasi tipe data
   - Handle input buffer

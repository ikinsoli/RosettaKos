// file: RosettaKos.cpp
#include <iostream>
#include <string>
using namespace std;

// ================ KONSTANTA ================
const int MAX_KAMAR = 100;
const int MAX_PENYEWA = 100;
const int MAX_TAGIHAN = 200;
const int MAX_PEMBAYARAN = 300;

// ================ DATA KAMAR ================
int nomorKamar[MAX_KAMAR];
double hargaKamar[MAX_KAMAR];
string statusKamar[MAX_KAMAR];        // "terisi" atau "kosong"
string passwordKamar[MAX_KAMAR];
int jumlahKamar = 0;

// ================ DATA PENYEWA ================
int idPenyewa[MAX_PENYEWA];
string namaPenyewa[MAX_PENYEWA];
int kamarPenyewa[MAX_PENYEWA];
int jumlahPenyewa = 0;

// ================ DATA TAGIHAN ================
int idTagihan[MAX_TAGIHAN];
int kamarTagihan[MAX_TAGIHAN];
string bulanTagihan[MAX_TAGIHAN];
int tahunTagihan[MAX_TAGIHAN];
double jumlahTagihan[MAX_TAGIHAN];
string statusTagihan[MAX_TAGIHAN];    // "belum bayar" atau "sudah bayar"
int jumlahDataTagihan = 0;

// ================ DATA PEMBAYARAN ================
int idPembayaran[MAX_PEMBAYARAN];
int tagihanPembayaran[MAX_PEMBAYARAN];
int kamarPembayaran[MAX_PEMBAYARAN];
double jumlahPembayaran[MAX_PEMBAYARAN];
string tanggalPembayaran[MAX_PEMBAYARAN];
string metodePembayaran[MAX_PEMBAYARAN];
bool statusVerifikasi[MAX_PEMBAYARAN];
int jumlahDataPembayaran = 0;

// ================ FUNGSI MANAJEMEN KAMAR ================
void tambahKamar() {
    if (jumlahKamar >= MAX_KAMAR) {
        cout << "Kapasitas kamar penuh!" << endl;
        return;
    }

    cout << "Masukkan nomor kamar: ";
    cin >> nomorKamar[jumlahKamar];
    
    cout << "Masukkan harga kamar: ";
    cin >> hargaKamar[jumlahKamar];
    
    cout << "Masukkan password default: ";
    cin >> passwordKamar[jumlahKamar];
    
    statusKamar[jumlahKamar] = "kosong";
    jumlahKamar++;
    
    cout << "Kamar berhasil ditambahkan!" << endl;
}

void lihatDaftarKamar() {
    cout << "\n====== DAFTAR KAMAR ======" << endl;
    cout << "No.\tNomor\tHarga\tStatus" << endl;
    for (int i = 0; i < jumlahKamar; i++) {
        cout << (i+1) << ".\t" 
             << nomorKamar[i] << "\t"
             << hargaKamar[i] << "\t"
             << statusKamar[i] << endl;
    }
}

void ubahStatusKamar() {
    int nomor;
    string status;
    
    cout << "Masukkan nomor kamar: ";
    cin >> nomor;
    
    cout << "Masukkan status baru (terisi/kosong): ";
    cin >> status;
    
    for (int i = 0; i < jumlahKamar; i++) {
        if (nomorKamar[i] == nomor) {
            statusKamar[i] = status;
            cout << "Status kamar berhasil diubah!" << endl;
            return;
        }
    }
    cout << "Kamar tidak ditemukan!" << endl;
}

// ================ FUNGSI MANAJEMEN TAGIHAN ================
void buatTagihanBulanan() {
    string bulan;
    int tahun;
    
    cout << "Masukkan bulan (contoh: Januari): ";
    cin >> bulan;
    cout << "Masukkan tahun: ";
    cin >> tahun;
    
    for (int i = 0; i < jumlahKamar; i++) {
        if (statusKamar[i] == "terisi" && jumlahDataTagihan < MAX_TAGIHAN) {
            idTagihan[jumlahDataTagihan] = jumlahDataTagihan + 1;
            kamarTagihan[jumlahDataTagihan] = nomorKamar[i];
            bulanTagihan[jumlahDataTagihan] = bulan;
            tahunTagihan[jumlahDataTagihan] = tahun;
            jumlahTagihan[jumlahDataTagihan] = hargaKamar[i];
            statusTagihan[jumlahDataTagihan] = "belum bayar";
            jumlahDataTagihan++;
        }
    }
    cout << "Tagihan bulanan berhasil dibuat!" << endl;
}

void lihatStatusTagihan() {
    cout << "\n====== STATUS TAGIHAN ======" << endl;
    cout << "ID\tKamar\tBulan\tTahun\tJumlah\tStatus" << endl;
    for (int i = 0; i < jumlahDataTagihan; i++) {
        cout << idTagihan[i] << "\t"
             << kamarTagihan[i] << "\t"
             << bulanTagihan[i] << "\t"
             << tahunTagihan[i] << "\t"
             << jumlahTagihan[i] << "\t"
             << statusTagihan[i] << endl;
    }
}

void updateStatusTagihan(int idTagihanUpdate) {
    for (int i = 0; i < jumlahDataTagihan; i++) {
        if (idTagihan[i] == idTagihanUpdate) {
            statusTagihan[i] = "sudah bayar";
            cout << "Status tagihan berhasil diupdate!" << endl;
            return;
        }
    }
    cout << "Tagihan tidak ditemukan!" << endl;
}

// ================ FUNGSI MANAJEMEN PEMBAYARAN ================
void catatPembayaran() {
    if (jumlahDataPembayaran >= MAX_PEMBAYARAN) {
        cout << "Kapasitas data pembayaran penuh!" << endl;
        return;
    }

    cout << "Masukkan ID tagihan: ";
    cin >> tagihanPembayaran[jumlahDataPembayaran];
    
    cout << "Masukkan jumlah pembayaran: ";
    cin >> jumlahPembayaran[jumlahDataPembayaran];
    
    cout << "Masukkan tanggal pembayaran: ";
    cin >> tanggalPembayaran[jumlahDataPembayaran];
    
    cout << "Masukkan metode pembayaran: ";
    cin >> metodePembayaran[jumlahDataPembayaran];
    
    idPembayaran[jumlahDataPembayaran] = jumlahDataPembayaran + 1;
    statusVerifikasi[jumlahDataPembayaran] = false;
    
    cout << "Pembayaran berhasil dicatat dengan ID: " 
         << idPembayaran[jumlahDataPembayaran] << endl;
    
    jumlahDataPembayaran++;
}

void lihatPembayaranBelumVerifikasi() {
    cout << "\n====== PEMBAYARAN BELUM VERIFIKASI ======" << endl;
    cout << "ID\tTagihan\tJumlah\tTanggal\tMetode" << endl;
    bool ada = false;
    
    for (int i = 0; i < jumlahDataPembayaran; i++) {
        if (!statusVerifikasi[i]) {
            cout << idPembayaran[i] << "\t"
                 << tagihanPembayaran[i] << "\t"
                 << jumlahPembayaran[i] << "\t"
                 << tanggalPembayaran[i] << "\t"
                 << metodePembayaran[i] << endl;
            ada = true;
        }
    }
    
    if (!ada) {
        cout << "Tidak ada pembayaran yang menunggu verifikasi." << endl;
    }
}

void verifikasiPembayaran() {
    int idPembayaranVerifikasi;
    cout << "Masukkan ID pembayaran yang akan diverifikasi: ";
    cin >> idPembayaranVerifikasi;
    
    for (int i = 0; i < jumlahDataPembayaran; i++) {
        if (idPembayaran[i] == idPembayaranVerifikasi) {
            if (!statusVerifikasi[i]) {
                statusVerifikasi[i] = true;
                updateStatusTagihan(tagihanPembayaran[i]);
                cout << "Pembayaran berhasil diverifikasi!" << endl;
            } else {
                cout << "Pembayaran ini sudah diverifikasi sebelumnya!" << endl;
            }
            return;
        }
    }
    cout << "ID Pembayaran tidak ditemukan!" << endl;
}

// ================ FUNGSI MENU ================
void menuAdmin() {
    while (true) {
        cout << "\n====== MENU ADMIN ======" << endl;
        cout << "1. Manajemen Kamar" << endl;
        cout << "2. Manajemen Tagihan" << endl;
        cout << "3. Manajemen Pembayaran" << endl;
        cout << "0. Keluar" << endl;
        
        int pilihan;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: {
                cout << "\n=== MANAJEMEN KAMAR ===" << endl;
                cout << "1. Tambah Kamar" << endl;
                cout << "2. Lihat Daftar Kamar" << endl;
                cout << "3. Ubah Status Kamar" << endl;
                int subPilihan;
                cout << "Pilihan: ";
                cin >> subPilihan;
                
                switch(subPilihan) {
                    case 1: tambahKamar(); break;
                    case 2: lihatDaftarKamar(); break;
                    case 3: ubahStatusKamar(); break;
                }
                break;
            }
            case 2: {
                cout << "\n=== MANAJEMEN TAGIHAN ===" << endl;
                cout << "1. Buat Tagihan Bulanan" << endl;
                cout << "2. Lihat Status Tagihan" << endl;
                int subPilihan;
                cout << "Pilihan: ";
                cin >> subPilihan;
                
                switch(subPilihan) {
                    case 1: buatTagihanBulanan(); break;
                    case 2: lihatStatusTagihan(); break;
                }
                break;
            }
            case 3: {
                cout << "\n=== MANAJEMEN PEMBAYARAN ===" << endl;
                cout << "1. Catat Pembayaran" << endl;
                cout << "2. Lihat Pembayaran Belum Verifikasi" << endl;
                cout << "3. Verifikasi Pembayaran" << endl;
                int subPilihan;
                cout << "Pilihan: ";
                cin >> subPilihan;
                
                switch(subPilihan) {
                    case 1: catatPembayaran(); break;
                    case 2: lihatPembayaranBelumVerifikasi(); break;
                    case 3: verifikasiPembayaran(); break;
                }
                break;
            }
            case 0: return;
        }
    }
}

int main() {
    menuAdmin();
    return 0;
}
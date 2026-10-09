/*
1. Lihat Smue data
2. Cek stok asc 
3. Search barang
4. Tambah barang
5. Edit barang
6. Hapus barang
0. Back
*/
#include <iostream>
#include <string.h>
#include "data.h"
using namespace std;

void kelolaDataBarang();
void lihatSemuaData(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang);
void cekStokKritis(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang);
void cariBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int& totalBarang);
void tambahBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang);
void editBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang);
void hapusBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang);
void laporanPenjualan(int total[], int totalPelanggan);

void tekanEnterKembali() {
    cout << "[Tekan Enter Untuk Kembali...]";
    cin.ignore();
    cout << endl;
}

void kelolaDataBarang() {
        int pilihan;

        do {
            cout << "============================================================" << endl;
            cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
            cout << "============================================================" << endl;
            cout << " User: " << usernameAdmin << endl;
            cout << " Status: ADMIN" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << ">> KELOLA DATA BARANG" << endl;
            cout << "[1] Lihat Semua Data" << endl;
            cout << "[2] Cek Stok Kritis" << endl;
            cout << "[3] Cari Barang (Smart Search)" << endl;
            cout << "[4] Tambah Barang" << endl;
            cout << "[5] Edit Barang" << endl;
            cout << "[6] Hapus Barang" << endl;
            cout << "[0] Kembali" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            cout << endl;

            switch (pilihan) {
                case 1:
                    lihatSemuaData(kodeBarang, namaBarang, katBarang, hargaBarang, stokBarang, totalBarangGudang);
                    break;

                case 2:
                    cekStokKritis(kodeBarang, namaBarang, katBarang, hargaBarang, stokBarang, totalBarangGudang);
                    break;

                case 3:
                    cariBarang(kodeBarang, namaBarang, katBarang, hargaBarang, totalBarangGudang);
                    break;

                case 4:
                    tambahBarang(kodeBarang, namaBarang, katBarang, hargaBarang, stokBarang, totalBarangGudang);
                    break;

                case 5:
                    editBarang(kodeBarang, namaBarang, katBarang, hargaBarang, stokBarang, totalBarangGudang);
                    break;

                case 6:
                    hapusBarang(kodeBarang, namaBarang, katBarang, hargaBarang, stokBarang, totalBarangGudang);
                    break;

                case 0:
                    break;
                
                default: 
                    cout << "Input tidak valid. Coba lagi" << endl;
                    break;
            }
        } while (pilihan != 0);       
}

void lihatSemuaData(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang) {
    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "NO  KODE    NAMA BARANG\t\t KAT\t  HARGA(Rp)    STOK" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    if (totalBarang == 0) {
        cout << "Belum Ada Data Barang." << endl;
    }

    for (int i = 0; i < totalBarangGudang; i++) {
        cout << i + 1<< "   " << kodeBarang[i] 
              << "   " << namaBarang[i] 
              << "  \t" << katBarang[i] 
              << "\t   " << hargaBarang[i] 
              << " \t" << stokBarang[i] << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << endl;

    tekanEnterKembali();
}

void cekStokKritis(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang) {
    int index[100];
    
    for (int i = 0; i < totalBarang; i++) {
        index[i] = i;
    }

    for (int i = 0; i < totalBarang; i++) {
        for (int j = 0; j < totalBarang - i - 1; j++) {
            if (stokBarang[index[j]] > stokBarang[index[j + 1]]) {
                int temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> FILTER STOK TERKECIL" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "NO  KODE    NAMA BARANG\t\t KAT\tHARGA(Rp)    STOK" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    if (totalBarang == 0) {
        cout << "Belum Ada Data Barang." << endl;
    }

    for (int i = 0; i < totalBarangGudang; i++) {
        cout << i + 1 << "   " << kodeBarang[index[i]] << "    " << namaBarang[index[i]] << "\t" << katBarang[index[i]] << "\t  " << hargaBarang[index[i]] << "\t      " << stokBarang[index[i]] << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;

    tekanEnterKembali();
}

string toLowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;
}

bool cek(string nama, string key) {
    if (key.length() > nama.length()) {
        return false;
    }

    for (int i = 0; i <= nama.length() - key.length(); i++) {
        bool ketemu = true;
        for (int j = 0; j < key.length(); j++) {
            if (nama[i + j] != key[j]) {
                ketemu = false;
                break;
            }
        }
        if (ketemu) {
            return true;
        }
    }

    return false;
}

void cariBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int& totalBarang) {
    string inputSearch;
    string nama, kat;
    bool ketemu = false;

    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> SMART SEARCH (CASE INSENSITIVE)" << endl;
    cout << "Kata Kunci (Nama/Kategori): ";
    getline(cin, inputSearch);
    cout << endl;

    inputSearch = toLowercase(inputSearch);

    cout << "HASIL PENCARIAN:" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < totalBarang; i++) {
        nama = toLowercase(namaBarang[i]);
        kat = toLowercase(katBarang[i]);

        if (cek(nama, inputSearch) || cek(kat, inputSearch)) {
            ketemu = true;
            cout << "[" << kodeBarang[i] << "] " << namaBarang[i] << "\t\t Rp " << hargaBarang[i] << " (" << katBarang[i] << ")" << endl;
        }
    }
    if (!ketemu) {
        cout << "Barang Tidak Ditemukan." << endl;
    }
    cout << endl;
    tekanEnterKembali();
}

void tambahBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang) {
    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> TAMBAH BARANG BARU" << endl;
    cout << "------------------------------------------------------------" << endl;
    totalBarang++;

    kodeBarang[totalBarang - 1] = "P00" + to_string(totalBarang);
    cout <<  "Kode Otomatis\t: " << kodeBarang[totalBarang - 1];
    cout << " (Tekan Enter)";
    cin.ignore();

    cout << "Nama\t\t: ";
    getline(cin, namaBarang[totalBarang - 1]);

    cout << "Kategori\t: ";
    getline(cin, katBarang[totalBarang - 1]);

    cout << "Harga\t\t: Rp ";
    cin >> hargaBarang[totalBarang - 1];

    cout << "Stok\t\t: ";
    cin >> stokBarang[totalBarang - 1];
    
    cout << "\n[OK] Sukses Tambah Data." << endl;
    cin.ignore();
    tekanEnterKembali();
}

void editBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang) {
    string kodeEdit, nama;
    int idx, harga, stok;
    bool ketemu = false;
    
    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> EDIT BARANG" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "NO  KODE    NAMA BARANG\t\t KAT\tHARGA(Rp)    STOK" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    if (totalBarang == 0) {
        cout << "Belum Ada Data Barang." << endl << endl;
        cout << "------------------------------------------------------------" << endl;
    } else {
        for (int i = 0; i < totalBarang; i++) {
            cout << i + 1<< "   " << kodeBarang[i] << "    " << namaBarang[i] << "\t" << katBarang[i] << "\t  " << hargaBarang[i] << "\t      " << stokBarang[i] << endl;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Kode Barang Edit: ";
        cin >> kodeEdit;
        cin.ignore();
        
        for (int i = 0; i < totalBarang; i++) {
            if (kodeBarang[i] == kodeEdit) {
                ketemu = true;
                idx = i;  
            }
        }

        if (ketemu) {
            cout << "\nDetail Produk:" << endl;
            cout << "Nama\t: " << namaBarang[idx]
                << "\nHarga\t: " << hargaBarang[idx] 
                << "\nStok\t: " << stokBarang[idx] << endl;
            cout << "----------------------------------" << endl;

            cout << "Nama Baru (Enter Skip)\t: ";
            getline(cin, nama);

            cout << "Harga Baru (0 skip)\t: ";
            cin >> harga;

            cout << "Stok Baru (-1 skip)\t: ";
            cin >> stok;

            if (!nama.empty()) {
                namaBarang[idx] = nama;
            }

            if (harga != 0) {
                hargaBarang[idx] = harga;
            }

            if (stok != -1) {
                stokBarang[idx] = stok;
            }

            cout << "\n[OK] Update Sukses." << endl << endl;
            cin.ignore();
        } else {
            cout << "Kode Barang Tidak Ditemukan." << endl << endl;
        }
    }

    tekanEnterKembali();
}

void hapusBarang(string kodeBarang[], string namaBarang[], string katBarang[], int hargaBarang[], int stokBarang[], int& totalBarang) {
    string kode;
    int idx;
    bool ketemu = false;
    char yakin;
    
    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> HAPUS BARANG" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "NO  KODE    NAMA BARANG\t\t KAT\tHARGA(Rp)    STOK" << endl;
    cout << "------------------------------------------------------------" << endl;

    if (totalBarang == 0) {
        cout << "Tidak ada Data Barang." << endl;
        cout << "------------------------------------------------------------" << endl;
    } else {
        for (int i = 0; i < totalBarangGudang; i++) {
            cout << i + 1 << "   " << kodeBarang[i] << "    " << namaBarang[i] << "\t" << katBarang[i] << "\t  " << hargaBarang[i] << "\t      " << stokBarang[i] << endl;
        }

        cout << "------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Kode Barang Dihapus: ";
        cin >> kode;

        for (int i = 0; i < totalBarang; i++) {
            if (kodeBarang[i] == kode) {
                ketemu = true;
                idx = i;
            }
        }

        if (ketemu) {
            cout << "Menghapus '" << namaBarang[idx] << "'..." << endl;
            cout << "Yakin? (y/n): ";
            cin >> yakin;

            if (yakin == 'y') {
                for (int i = idx; i < totalBarang - 1; i++) {
                    kodeBarang[i] = "P00" + to_string(i + 1);
                    namaBarang[i] = namaBarang[i + 1];
                    katBarang[i] = katBarang[i + 1];
                    hargaBarang[i] = hargaBarang[i + 1];
                    stokBarang[i] = stokBarang[i + 1];
                }

                totalBarang--;

                kodeBarang[totalBarang] = "";
                namaBarang[totalBarang] = "";
                katBarang[totalBarang] = "";
                hargaBarang[totalBarang] = 0;
                stokBarang[totalBarang] = 0;

                cout << "[OK] Data Terhapus." << endl << endl;
            } else {
                cout << "[X] Data Batal Dihapus." << endl << endl;
            }
        } else {
            cout << "Kode Barang Tidak Ditemukan." << endl << endl;
        }
        cin.ignore();

    }
    
    tekanEnterKembali();
}

void laporanPenjualan(int total[], int totalPelanggan, int totalPenjualanKotor) {
    cout << "============================================================" << endl;
    cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
    cout << "============================================================" << endl;
    cout << " User: " << usernameAdmin << endl;
    cout << " Status: ADMIN" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << ">> LAPORAN OMZET HARIAN" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    if (totalPelanggan == 0) {
        cout << "Belum Ada Penjualan." << endl;
    }

    for (int i = 0; i < totalPelanggan; i++) {
        cout << "TRX-" << i + 1 
             << "\t\tKasir: " << usernameKasir 
             << "\t\tTotal: Rp" << totalSementara[i] << endl;
        totalPenjualanKotor += totalSementara[i];
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "TOTAL PENJUALAN KOTOR: Rp " << totalPenjualanKotor << endl << endl;

    tekanEnterKembali();

}

/*
1. Scan item
2. Bayar
0. Cancel 
*/
#include <iostream>
#include "data.h"
using namespace std;

int pilihan;

void transaksiKasir(int& totalPelanggan);
void scanItem(string kodeBarang[], string namaBarang[], int hargaBarang[], int stokBarang[], int& totalBarang, int& totalItem);
void bayar(int subtotal[100], int totalPelanggan, int totalItem, string namaPelanggan);
void struk(string namaBarangPelanggan[][100], int qtyBarangPelanggan[][100],  int hargaBarangPelanggan[][100], int subtotalPelanggan[][100], int subtotal[], int diskon, int netto, int nominal, int totalItem);

void tekanEnter() {
    cout << "[Tekan Enter Untuk Kembali...]";
    cin.ignore();
    cout << endl;
}

void transaksiKasir(int& totalPelanggan) {
    string namaPelanggan;
    int totalItem = 0;
    
    if (totalBarangGudang == 0) {
        cout << "Tidak Ada Barang." << endl;
    } else {
        do {
            cout << "============================================================" << endl;
            cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
            cout << "============================================================" << endl;
            cout << " User: " << usernameKasir << endl;
            cout << " Status: KASIR" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << ">> TRANSAKSI: ";

            if (namaPelanggan.empty()) {
                getline(cin, namaPelanggan);
            } else {
                cout << namaPelanggan << endl;
            }

            cout << "-------------------------------------------------------------" << endl;
            cout << "NO ITEM\t\t\tQTY\t  DISKON\t  SUBTOTAL" << endl;
            cout << "-------------------------------------------------------------" << endl;
            
            for (int i = 0; i < totalItem; i++) {
                cout << i + 1 << "  " 
                    << namaBarangPelanggan[totalPelanggan][i]
                    << "   \t" << qtyBarangPelanggan[totalPelanggan][i] 
                    << "\tRp " << diskonBarangPelanggan[totalPelanggan][i] << "/pcs" 
                    << "\t  Rp " << subtotalPelanggan[totalPelanggan][i] << endl;
            }

            cout << "-------------------------------------------------------------" << endl;
            cout << "TOTAL SEMENTARA\t\t\t\t\t: Rp " << totalSementara[totalPelanggan] << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "[1] Scan Item | [2] Bayar | [0] Batal" << endl;
            cout << ">> ";
            cin  >> pilihan;
            cin.ignore();
            cout << endl;

            if (pilihan == 1) {
                scanItem(kodeBarang, namaBarang, hargaBarang, stokBarang, totalBarangGudang, totalItem);
            } else if (pilihan == 2 ) {
                bayar(totalSementara, totalPelanggan, totalItem, namaPelanggan);
            } else if (pilihan == 0) {
                return;
            }
        } while (pilihan != 0);
    }
}

void scanItem(string kodeBarang[], string namaBarang[], int hargaBarang[], int stokBarang[], int& totalBarang, int& totalItem) {
    string kode;
    bool ketemu = false;
    int idx, qty, diskonGrosir = 0;

    cout << "Kode Barang: ";
    cin >> kode;

    for (int i = 0; i < totalBarang; i++) {
        if (kodeBarang[i] == kode) {
            ketemu = true;
            idx = i;
        }
    }

    if (ketemu) {
        cout << ">> " << namaBarang[idx] << " @" << hargaBarang[idx] << " (Stok: " << stokBarang[idx] << ")" << endl;

        if (stokBarang[idx] != 0) {
            do {
                cout << "Qty: ";
                cin >> qty;

                if (qty > stokBarang[idx]) {
                    cout <<  "Stok Tidak Cukup." << endl;
                }
            } while (qty > stokBarang[idx]);
        
            if (qty > 5) {
                diskonGrosir = hargaBarang[idx] * 0.1667;
                cout << " [INFO] Dapat Diskon Grosir Rp " << diskonGrosir << "/pcs!" << endl;
            }

            namaBarangPelanggan[totalPelanggan][totalItem] = namaBarang[idx];
            qtyBarangPelanggan[totalPelanggan][totalItem] = qty;
            diskonBarangPelanggan[totalPelanggan][totalItem] = diskonGrosir;
            hargaBarangPelanggan[totalPelanggan][totalItem] = hargaBarang[idx] - diskonGrosir;
            subtotalPelanggan[totalPelanggan][totalItem] = qty * (hargaBarang[idx] - diskonGrosir);

            totalSementara[totalPelanggan] += subtotalPelanggan[totalPelanggan][totalItem];
            stokBarang[idx] -= qty;
            totalItem++;
        } else {
            cout << "Stok Habis." << endl;
        }
        
    } else {
        cout << "Kode Barang Tidak Ditemukan." << endl;
    }

    cout << endl;
}

void bayar(int subtotal[100], int totalPelanggan, int totalItem, string namaPelanggan) {
    int nominal;
    int netto, diskon = 0;

    if (subtotal[totalPelanggan] >= 100000) {
        diskon += subtotal[totalPelanggan] * 0.05;
    }

    string nama = namaPelanggan.erase(member.length(), (namaPelanggan.length() - member.length()));
    if (nama == member) {
        diskon += subtotal[totalPelanggan] * 0.02;
    }
    
    netto = subtotal[totalPelanggan] - diskon;

    cout << "----- PEMBAYARAN -----" << endl;
    cout << "Subtotal  : Rp " << subtotal[totalPelanggan] << endl;
    cout << "Diskon\t  : Rp " << diskon << endl;
    cout << "Netto\t  : Rp " << netto << endl;

    do {
        cout << "Nominal\t  : Rp ";
        cin >> nominal;

        if (nominal < netto) {
            cout << "Uang Tidak Cukup." << endl;
        }
    } while (nominal < netto);

    cout << endl;
    struk(namaBarangPelanggan, qtyBarangPelanggan, hargaBarangPelanggan, subtotalPelanggan, totalSementara, diskon, netto, nominal, totalItem);
}

void struk(string namaBarangPelanggan[][100], int qtyBarangPelanggan[][100],  int hargaBarangPelanggan[][100], int subtotalPelanggan[][100], int subtotal[], int diskon, int netto, int nominal, int totalItem) {
    cout << "================================================" << endl;
    cout << "|                TOKO SERBA ADA                |" << endl;
    cout << "|          Jln. Koding No. 1, Jakarta          |" << endl;
    cout << "================================================" << endl;
    cout << "Tgl\t: 09/01/2026 12:00                        " << endl;
    cout << "Kasir\t: " << usernameKasir << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < totalItem; i++) {
        cout << namaBarangPelanggan[totalPelanggan][i] << endl;
        cout << "  " << qtyBarangPelanggan[totalPelanggan][i] << " x Rp " 
             << hargaBarangPelanggan[totalPelanggan][i] 
             << "\t\t\tRp " << subtotalPelanggan[totalPelanggan][i] << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << "Subtotal: \t\t\tRp " << subtotal[totalPelanggan] << endl;
    cout << "Diskon  : \t\t\tRp " << diskon << endl;
    cout << "------------------------------------------------" << endl;
    cout << "TOTAL   : \t\t\tRp " << netto << endl;
    cout << "BAYAR   : \t\t\tRp " << nominal << endl;
    cout << "KEMBALI : \t\t\tRp " << nominal - netto << endl;
    cout << "================================================" << endl;
    cout << "|         TERIMA KASIH TELAH BERBELANJA        |" << endl;
    cout << "|           BARANG YANG SUDAH DIBELI           |" << endl;
    cout << "|          TIDAK DAPAT DITUKAR KEMBALI         |" << endl;
    cout << "================================================" << endl;

    cout << "\n Simulasi Cetak Struk Selesai...." << endl << endl;

    totalPelanggan++;
    pilihan = 0;
    cin.ignore();
    tekanEnter();

}
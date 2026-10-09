/*
1. Menu Dashboard both 
2. Login
*/
#include <iostream>
#include "kasir.h"
#include "admin.h"
#include "data.h"
using namespace std;

// DATA DUMMY
string kodeBarang[100] = {"P001", "P002", "P003", "P004", "P005"};
string namaBarang[100] = {"Indomie Goreng", "Ultramilk Cokelat", "Buku Sinar Dunia", "Pulpet Pilot", "Chitato Rasa Ayam"};
string katBarang[100] = {"Makanan", "Minuman", "ATK", "ATK", "Snack"};
int hargaBarang[100] = {3000, 6000, 4500, 2500, 12000};
int stokBarang[100] = {50, 24, 100, 85, 10};
int totalBarangGudang = 5;

string namaBarangPelanggan[100][100];
int hargaBarangPelanggan[100][100];
int qtyBarangPelanggan[100][100];
int diskonBarangPelanggan[100][100];
int subtotalPelanggan[100][100];
int totalSementara[100];
int totalDiskonPelanggan[100];
int totalPelanggan = 0;
string member = "TSA";
int totalPenjualanKotor = 0;

// DATA LOGIN
string usernameAdmin = "admin";
string passwordAdmin = "admin";
string usernameKasir = "kasir";
string passwordKasir = "kasir";
string inputUsername, inputPassword;

void userLogin();
void menuDashboard();

void userLogin() {
    int jumlahPercobaan = 0;
    bool loginBerhasil = false;

    cout << "============================================================" << endl;
    cout << "|                          LOGIN                           |" << endl;
    cout << "============================================================" << endl;
    while (jumlahPercobaan < 3) {
        cout << "Masukkan Username: ";
        getline(cin, inputUsername);

        cout << "Masukkan Password: ";
        getline(cin, inputPassword);

        if ((inputUsername == usernameAdmin && inputPassword == passwordAdmin) || (inputUsername == usernameKasir && inputPassword == passwordKasir)) {
            loginBerhasil = true;
            cout << endl;
            menuDashboard();
        } else {
            jumlahPercobaan++;

            if (jumlahPercobaan > 2) {
                cout << "Terlalu banyak percobaan. Akun anda diblokir." << endl;
                return;
            } else {
                cout << "Username atau password salah. Coba lagi." << endl;
            }
        } 

        if (loginBerhasil) return;
    }
    
}

void menuDashboard() {
    int pilihan;

    do {
        cout << "============================================================" << endl;
        cout << "|              SISTEM POS MANAJEMEN TOKO V.PRO             |" << endl;
        cout << "============================================================" << endl;
        cout << " User: " << inputUsername << endl;
        cout << " Status: " << (inputUsername == "admin" ? "ADMIN" : "KASIR" ) << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << ">> MENU DASHBOARD" << endl;
        cout << "[1] Kelola Data Barang" << (inputUsername == "kasir" ? " (LOCKED)" : "") << endl;
        cout << "[2] Transaksi Kasir" << (inputUsername == "admin" ? " (LOCKED)" : "") << endl;
        cout << "[3] Laporan Penjualan" << (inputUsername == "kasir" ? " (LOCKED)" : "") << endl;
        cout << "[9] Logout" << endl;
        cout << "[0] Keluar Aplikasi" << endl;
        cout << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;
        cin.ignore();

        switch (pilihan) {
            case 1: 
                if (inputUsername == "admin") {
                    kelolaDataBarang();
                } else {
                  cout << "Anda tidak memiliki akses." << endl;
                }

                break;
            
            case 2:
                if (inputUsername == "kasir") {
                    transaksiKasir(totalPelanggan);
                } else {
                  cout << "Anda tidak memiliki akses." << endl;
                }

                break;

            case 3:
                if (inputUsername == "admin") {
                    laporanPenjualan(totalSementara, totalPelanggan, totalPenjualanKotor);
                } else {
                  cout << "Anda tidak memiliki akses." << endl;
                }
                break;

            case 9:
                userLogin();
                return;

            case 0:
                cout << "Terima Kasih." << endl;
                return;
        }
    } while (pilihan != 0 || pilihan != 9);
}

int main() {
    userLogin();
}
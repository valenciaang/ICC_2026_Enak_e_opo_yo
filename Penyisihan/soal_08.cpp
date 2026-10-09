#include <iostream>
using namespace std;

int main() {
    int array[100], jumlahElemen, nilaiTerbesarPertama, nilaiTerbesarKedua;
    bool ada = false;

    cout << "Masukkan Jumlah Elemen: ";
    cin >> jumlahElemen;

    cout << "Elemen Array: ";
    for (int i = 0; i < jumlahElemen; i++) {
        cin >> array[i];
    }

    nilaiTerbesarPertama = array[0];

    for (int i = 0; i < jumlahElemen; i++) {
        if (array[i] > nilaiTerbesarPertama) {
            nilaiTerbesarKedua = nilaiTerbesarPertama;
            nilaiTerbesarPertama = array[i];
            ada = true;
        } else if (array[i] < nilaiTerbesarPertama) {
            if (!ada || array[i] > nilaiTerbesarKedua) {
                nilaiTerbesarKedua = array[i];
                ada = true;
            }
        }
    }

    if (ada) {
        cout << "Nilai Terbesar Kedua: " << nilaiTerbesarKedua << endl;
    } else {
        cout << "Tidak ada nilai terbesar kedua (semua nilai pada array sama).";
    }

    return 0;
}
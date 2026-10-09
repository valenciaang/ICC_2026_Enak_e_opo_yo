#include <iostream>
using namespace std;

int main() {
    int array[100], arrayGanjil[100], arrayGenap[100], 
        jumlahElemen, jumlahGanjil = 0, jumlahGenap = 0;

    cout << "Masukkan Jumlah Elemen: "; 
    cin >> jumlahElemen;

    cout << "Elemen Array: " << endl;
    for (int i = 0; i < jumlahElemen; i++) {
        cin >> array[i];

        if (array[i] % 2 == 0) {
            arrayGenap[jumlahGenap] = array[i];
            jumlahGenap++;
        } else {
            arrayGanjil[jumlahGanjil] = array[i];
            jumlahGanjil++;
        }

    }

    cout << "Array Ganjil: ";
    for (int i = 0; i < jumlahGanjil; i++) {
        cout << arrayGanjil[i] << " ";
    }

    cout << "\nArray Genap: ";
    for (int i = 0; i < jumlahGenap; i++) {
        cout << arrayGenap[i] << " ";
    }

    cout << "\nJumlah Angka Ganjil: " << jumlahGanjil << endl;
    cout << "Jumlah Angka Genap: " << jumlahGenap << endl;


    return 0;
}
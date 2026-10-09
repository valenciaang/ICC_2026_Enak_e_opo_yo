#include <iostream>
using namespace std;

int main()  {
    int array[100], jumlahElemen, jumlahRotasi;

    cout << "Jumlah elemen: ";
    cin >> jumlahElemen;
    
    cout << "Elemen array: " << endl;
    for (int i = 0; i < jumlahElemen; i++) {
        cin >> array[i];
    }

    cout << "Masukkan jumlah rotasi (K): ";
    cin >> jumlahRotasi;

    cout << "Array sebelum rotasi: ";
    for (int i = 0; i < jumlahElemen; i++) {
        cout << array[i] << " ";
    }

    for (int i = 0; i < jumlahRotasi; i++) {
        int temp = array[jumlahElemen - 1];
        for (int j = jumlahElemen - 1; j > 0; j--) {
            array[j] = array[j - 1];
        }
        array[0] = temp;
    }

    cout << "\nArray setelah rotasi " << jumlahRotasi << " posisi ke kanan: ";
    for (int i = 0; i < jumlahElemen; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
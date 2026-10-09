#include <iostream>
using namespace std;

int main()
{
    int nilai;
    int elemen;

    cout << "Masukkan jumlah elemen: ";
    cin >> elemen;

    int arr[elemen];

    for (int i = 0; i < elemen; i++)
    {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    
    cout << "Nilai yang dicari: ";
    cin >> nilai;

    int jumlah = 0;

    for (int i = 0; i < elemen; i++)
    {
        if (arr[i] == nilai)
        {
            cout << "Muncul di indeks ke-" << i << endl;
            jumlah++;
        }
    }
    cout << "===========================" << endl;
    cout << "Jumlah yang dimunculkan: " << jumlah;
    cout << endl;

    if (jumlah == 0)
    {
        cout << "Tidak ditemukan" << endl;
    }


    return 0;
}

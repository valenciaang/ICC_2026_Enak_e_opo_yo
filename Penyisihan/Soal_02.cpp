#include <iostream>
using namespace std;

int main()
{
    int a,b,temp;

    cout << "Masukan nilai pertama: " ;
    cin >> a;

    cout << "Masukan nilai kedua: " ;
    cin >> b;

    cout << endl;

    cout << "=== SEBELUM DITUKAR ===" << endl;
    cout << "Nilai A: " << a << endl;
    cout << "Nilai B: " << b << endl;
    cout << endl;

    temp =a;
    a = b;
    b = temp;

    cout << "=== SETELAH DITUKAR ===" << endl;
    cout << "Nilai A: " << a << endl;
    cout << "Nilai B: " << b << endl;
    return 0;
}

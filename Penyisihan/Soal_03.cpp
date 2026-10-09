#include <iostream>
using namespace std;

int main()
{
    int n;

    cout  << "jumlah elemen: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "elemen ke - " << i+1 << ":" ;
        cin >> arr[i];
    }
    
    int nMax = arr[0];
    int nMin = arr[0];
    int indexMax = 0;
    int indexMin = 0;
    
    for (int i = 0; i < n; i++)
    {
     if (arr[i] > nMax)
     {
        nMax = arr[i];
        indexMax = i;
     }if (arr[i] < nMin)
     {
        nMin = arr[i];
        indexMin = i;
     }  
    }
    
    int selisih = nMax - nMin;

    cout << "Nilai minimum: " << nMin << " index " << indexMin + 1 << endl;
    cout << "Nilai maximal: " << nMax << " index " << indexMax + 1 << endl;
    cout << "Selilih:" << selisih << endl;

    return 0;
}

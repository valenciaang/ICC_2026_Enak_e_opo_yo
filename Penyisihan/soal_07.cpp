#include <iostream>
using namespace std;

const int MAXN = 1000;
const int MAXPAIR = 1000 * 999 / 2;
int arr[MAXN];
int resA[MAXPAIR];
int resB[MAXPAIR];

int findAllPairsValue(const int arr[], int n, int target, int resA[], int resB[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                if (count < MAXPAIR) {
                    resA[count] = arr[i];
                    resB[count] = arr[j];
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int n;

    cout << "Masukkan jumlah elemen (maks " << MAXN << "): ";
    cin >> n;

    if (n > MAXN) {
        cout << "Error: Jumlah elemen melebihi batas maksimal " << MAXN << ".\n";
        return 1;
    }
    if (n < 2) {
        cout << "Error: Butuh minimal 2 elemen untuk membuat pasangan.\n";
        return 1;
    }

    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Masukkan target penjumlahan: ";
    cin >> target;

    int pairCount = findAllPairsValue(arr, n, target, resA, resB);

    if (pairCount == 0) {
        cout << "Tidak ada pasangan yang jumlahnya " << target << ".\n";
    } else {
        cout << "Ditemukan " << pairCount << " pasangan:\n";
        for (int i = 0; i < pairCount; i++) {
            cout << "Pasangan ke " << (i + 1) << ": " << resA[i] << " + " << resB[i] << " = " << target << "\n";
        }
    }

    return 0;
}
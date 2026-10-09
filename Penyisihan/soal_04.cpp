#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double calculateAverage(const int a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return static_cast<double>(sum) / n;
}

double calculateMedian(int a[], int n) {
    if (n % 2 == 1) {
        return a[n / 2];
    }
    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}

const int MAXN = 1000;

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    if (n > MAXN || n <= 0) {
        cout << "Jumlah element harus antara 1 sampai " << MAXN << ".\n";
        return 1;
    }

    int a[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    double avg = calculateAverage(a, n);

    int sorted[n];
    for (int i = 0; i < n; i++) sorted[i] = a[i];
    sort(sorted, sorted + n);

    double med = calculateMedian(sorted, n);

    cout << fixed << setprecision(2);
    cout << "Rata-rata: " << avg << "\n";
    cout << "Median: " << med << "\n";

    cout << "Array terurut: ";
    for (int i = 0; i < n; i++) {
        cout << sorted[i] << " ";
    }
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string normalize(const string& s) {
    string out;
    out.reserve(s.size());
    for (unsigned char ch : s) {
        if (!isspace(ch)) {
            out.push_back(tolower(ch));
        }
    }
    return out;
}

bool isAnagram(string a, string b) {
    a = normalize(a);
    b = normalize(b);

    if (a.size() != b.size()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    string s1, s2;
    cout << "Masukkan string 1: ";
    getline(cin, s1);
    cout << "Masukkan string 2: ";
    getline(cin, s2);

    cout << (isAnagram(s1, s2) ? "Anagram\n" : "Bukan anagram\n");
    return 0;
}


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text, ori, revText;

    cout << "Masukkan Kata/Kalimat: ";
    getline(cin, text);

    ori = text;

    for (int i = text.length() - 1; i >= 0; i--) {
        text[i] = tolower(text[i]);

        if (text[i] == ' ') {
            text.erase(i, 1);
        } 
    }

    for (int i = text.length() - 1; i >= 0; i--) {
        revText += text[i];
    }

    if (text == revText) {
        cout << "\"" << ori << "\"" << " adalah palindrome" << endl;
    } else {
        cout <<  "\"" << ori <<  "\"" << " bukan palindrome" << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

char *ostaviSlova (string ulaz) {
    int cnt = 0;
    for (char &c: ulaz) {
        if (isalpha(c)) cnt++;
    }
    char *arr = new char[cnt + 1];
    int i = 0;
    for (char &c: ulaz) {
        if (isalpha(c)) {
            arr[i++] = c;
        }
    }
    arr[i] = '\0';

    return arr;
}

int main() {

    string ulaz = "asp12_i_ASP13";

    char *izlaz = ostaviSlova(ulaz);

    for (int i = 0; izlaz[i] != '\0'; ++i) {
        cout << izlaz[i];
    }
}
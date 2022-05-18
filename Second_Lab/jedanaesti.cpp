#include <iostream>

using namespace std;

struct zapis {
    int sifra;
    string naziv;
};

void obicanBubbleSort (zapis A[], int n, char smjer) {
    if (smjer == '0') {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                if (A[j+1].sifra < A[j].sifra) {
                    zapis temp = A[j+1];
                    A[j+1] = A[j];
                    A[j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                if (A[j+1].sifra > A[j].sifra) {
                    zapis temp = A[j+1];
                    A[j+1] = A[j];
                    A[j] = temp;
                }
            }
        }
    }
    
}

int main() {
    int n;
    char smjer;
    cout << "Molimo unesite n: ";
    cin >> n;
    cin.ignore(1,'\n');
    zapis A[n];
    for (int i = 0; i < n; ++i) {
        cout << "Molimo upisite " << i + 1 << ". zapis (format naziv/sifra): ";
        zapis zap;
        cin >> zap.naziv >> zap.sifra;
        A[i] = zap;
    }
    cout << "Molimo upisite smjer sortiranja: ";
    cin >> smjer;

    obicanBubbleSort(A, n, smjer);

    for (int i = 0; i < n; ++i) {
        cout << A[i].sifra << ", " << A[i].naziv << endl;
    }
}
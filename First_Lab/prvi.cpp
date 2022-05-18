#include <iostream>

using namespace std;

void ispis (float polje[], int n) {
    static bool first = true;
    if (n > 0) {
        ispis (polje, n - 1);
        if (polje[n - 1] < 0 && first) {
            cout << polje[n-1];
            first = false;
        } else if (polje[n - 1] < 0) {
            cout << ", " << polje[n-1];
        }
    }
}

int main() {

    int n;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n < 0);

    float *A = new float[n];

    cout << "Molimo upisite " << n << " clanova polja:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    ispis(A, n);

    return 0;
}
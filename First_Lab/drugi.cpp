#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int zbrojiKvadrate(int polje[], int n) {
    if (n == 0) {
        return 0;
    }
    int s = sqrt(polje[n - 1]);
    if ((s * s) == polje[n - 1]) {
        return zbrojiKvadrate(polje, n - 1) + polje[n - 1];
    } else {
        return zbrojiKvadrate(polje, n - 1);
    }
}

int main() {

    srand(time(NULL));
    int n;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n < 0);

    int *A = new int[n];

    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 100 + 1;
    }

    cout << "Polje: ";

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }

    cout << endl;
    cout << "Zbroj: " << zbrojiKvadrate(A, n) << endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void f (int polje[], int n, int m) {
    if (n > 0) {
        f(polje, n - 1, m);
        polje[n-1] = pow(m, n-1);
    }
}

int main() {

    int n, m;
    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n < 0);
    do {
        cout << "Molimo upisite zeljeni broj m" << endl;
        cin >> m;
    } while (m < 0);

    int *polje = (int*) malloc(n * sizeof(int));

    f(polje, n, m);

    for (int i = 0; i < n; ++i) {
        cout << polje[i] << endl;
    }
}
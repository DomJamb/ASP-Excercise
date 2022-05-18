#include <iostream>
#include <cmath>

using namespace std;

double pi (int n) {
    if (n == 1) {
        return 4;
    }
    return (4. * pow(-1, n + 1) / (2 * n - 1)) + pi(n - 1);
}

int main() {

    int n;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n < 0);
    
    double *A = new double[n];
    for (int i = 0; i < n; ++i) {
        A[i] = pi(i+1);
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }

    return 0;
}
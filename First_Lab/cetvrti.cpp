#include <iostream>

using namespace std;

double exp (double x, int n, int *fakt, double *xpot) {
    if (n == 0) {
        return 1;
    }
    double rez = exp(x, n - 1, fakt, xpot);
    *fakt = *fakt * n;
    *xpot = *xpot * x;
    return (rez + ((*xpot) / (*fakt)));
}

int main() {

    int n;
    double x;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n <= 0);

    cout << "Molimo upisite x" << endl;
    cin >> x;

    double *A = new double[n];  

    
    for (int i = 0; i < n; ++i) {   
        int fakt = 1;
        double xpot = 1;
        A[i] = exp (x, i, &fakt, &xpot);
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }

    return 0;
}
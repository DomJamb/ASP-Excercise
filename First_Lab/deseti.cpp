#include <iostream>
#include <cmath>

using namespace std;

double f (double z, int k) {

    if (k == 0) {
        return z;
    }
    return (-1 * pow(z, 2)) / ((2 * k + 1) * (2 * k)) * f(z, k - 1);
}

int main() {

    double z = 0.5;

    cout << f(z, 2) << endl;

}
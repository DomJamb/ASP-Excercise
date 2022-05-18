#include <iostream>

using namespace std;

template <typename T> int binarnoTrazi (T polje[], int n, T x) {
    
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (polje[mid] == x) {
            return mid;
        }

        if (polje[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {

    int n, index;
    float x;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n <= 0);

    cout << "Molimo upisite x" << endl;
    cin >> x;

    float *A = new float[n];

    for (int i = 0; i < n; ++i) {
        A[i] = i * 1.1;
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    index = binarnoTrazi(A, n, x);
    if (index == -1) {
        cout << "Broj se ne nalazi u polju." << endl;
    } else {
        cout << "Indeks clana polja: " << index << endl;
    }
}
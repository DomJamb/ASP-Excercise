#include <iostream>

using namespace std;

void selection2Sort (int A[], int n, char smjer) {
    if (smjer == '0') {
        for (int i = 0; i < n / 2; ++i) {
            int min = i;
            int max = n - i - 1;
            int tmin, tmax;
            for (int j = i; j < n - i; ++j) {
                if (A[min] > A[j]) {
                    min = j;
                }
                if (A[max] < A[j]) {
                    max = j;
                }
            }
            int indmin = i;
            int indmax = n - i - 1;
            tmin = A[min];
            tmax = A[max];
            A[min] = A[indmin];
            A[max] = A[indmax];
            A[indmin] = tmin;
            A[indmax] = tmax;
        }   
    } else {
        for (int i = 0; i < n / 2; ++i) {
            int min = n - i - 1;
            int max = i;
            int tmin, tmax;
            for (int j = i; j < n - i; ++j) {
                if (A[min] > A[j]) {
                    min = j;
                }
                if (A[max] < A[j]) {
                    max = j;
                }
            }
            int indmin = n - i - 1;
            int indmax = i;
            tmin = A[min];
            tmax = A[max];
            A[min] = A[indmin];
            A[max] = A[indmax];
            A[indmin] = tmin;
            A[indmax] = tmax;
        }
    }
}

int main() {
    int n;
    char smjer;
    cout << "Molimo upisite n: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "Molimo upisite " << i + 1 << ". broj: ";
        cin >> arr[i];
    }
    cout << "Molimo upisite smjer sortiranja: ";
    cin >> smjer;
    selection2Sort(arr, n, smjer);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#include <iostream>

using namespace std;

struct Zapis {
    int postBr;
    string mjesto;
};

void insertionSort (Zapis A[], int n, char smjer) {
    Zapis temp;
    if (smjer == '0') {
        for (int i = 1; i < n; ++i) {
            int j;
            temp = A[i];
            for (j = i; j >= 1 && A[j-1].postBr > temp.postBr; j--) {
                A[j] = A[j-1];
            }
            A[j] = temp;
        }
    } else {
        for (int i = 1; i < n; ++i) {
            int j;
            temp = A[i];
            for (j = i; j >= 1 && A[j-1].postBr < temp.postBr; j--) {
                A[j] = A[j-1];
            }
            A[j] = temp;
        }
    }
}

int main() {
    int n;
    char smjer;
    cout << "Molimo unesite broj zapisa: ";
    cin >> n;
    Zapis A[n];
    cin.ignore(1,'\n');
    for (int i = 0; i < n; ++i) {
        cout << "Molimo unesite " << i + 1 << ". zapis: ";
        string str;
        int num;
        cin >> str >> num;
        Zapis zap;
        zap.postBr = num;
        zap.mjesto = str;
        A[i] = zap;
    }
    cout << "Molimo unesite smjer: ";
    cin >> smjer;

    insertionSort(A, n, smjer);

    for (int i = 0; i < n; ++i) {
        cout << A[i].mjesto << ", " << A[i].postBr << endl;
    }
}
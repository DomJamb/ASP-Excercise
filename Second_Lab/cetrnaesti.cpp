#include <iostream>

using namespace std;

void Zamijeni(string *prvi, string *drugi) {
    string pom = *prvi;
    *prvi = *drugi;
    *drugi = pom;
}

void BubbleSortPoboljsani(string A[], int N, int smjer) {
    bool swapHappened = true;
    for (int i = 0; swapHappened; ++i) {
        swapHappened = false;
        for (int j = 0; j < N - 1 - i; ++j) {
            if (smjer == '0' ? A[j+1] < A[j]: A[j+1] > A[j]) {
                Zamijeni(&A[j], &A[j+1]);
                swapHappened = true;
            }
        }
    }
}

int main() {
    string arr[10];
    for (int i = 0; i < 5; ++i) {
        cout << "Molimo upisite " << i + 1 << ". string: ";
        cin >> arr[i];
    }
    char smjer;
    cout << "Molimo upisite smjer sortiranja: ";
    cin >> smjer;
    BubbleSortPoboljsani(arr, 5, smjer);
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << endl;
    }
}
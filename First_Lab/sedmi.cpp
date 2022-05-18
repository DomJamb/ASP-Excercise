#include <iostream>
#include <ctime>

using namespace std;

int *kvadrati(int polje[], int n) { 

    srand(time(NULL));
    int *arr = new int[n];
    bool usedInd[n] = {};

    for (int i = 0; i < n; ++i) {
        int kvad = polje[i] * polje[i];
        int index;
        do {
            index = rand() % n;
        } while (usedInd[index]);

        arr[index] = kvad;
        usedInd[index] = true;
    }

    return arr;
}

int main() {

    int n;

    do {
        cout << "Molimo upisite zeljeni broj elemenata polja" << endl;
        cin >> n;
    } while (n <= 0);

    int *polje = new int[n];
    int *izlaz;

    for (int i = 0; i < n; ++i) {
        cout << "Molimo upisite zeljeni clan polja: " << endl;
        cin >> polje[i];
    }

    izlaz = kvadrati(polje, n);
    for (int i = 0; i < n; ++i) {
        cout << izlaz[i] << " ";
    }
}
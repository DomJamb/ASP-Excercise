#include <iostream>

using namespace std;

class Osoba {
    private:
        string ime;
        unsigned short int godine;
    public:
        Osoba(): ime(" "), godine(0) {};
        Osoba(string ime, unsigned short int godine) {
            this->ime = ime;
            this->godine = godine;
        }
        string getIme() {
            return this->ime;
        }
        unsigned short int getGodine() {
            return this->godine;
        }
        void setIme(string ime) {
            this->ime = ime;
        }
        void setGodine(unsigned short int godine) {
            this->godine = godine;
        }
        bool operator<(const Osoba &druga) {
            if (this->godine < druga.godine) {
                return true;
            } else if (this->godine == druga.godine) {
                if (this->ime.at(0) < druga.ime.at(0)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
};

template <typename T>
void insertionSort (T A[], int n) {
    T temp;
    for (int i = 1; i < n; ++i) {
        int j;
        temp = A[i];
        for (j = i; j >= 1 && temp < A[j-1]; j--) {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

int main() {
    int n;
    cout << "Molimo unesite broj osoba: ";
    cin >> n;
    Osoba A[n];
    cin.ignore(1,'\n');
    for (int i = 0; i < n; ++i) {
        cout << "Molimo unesite " << i + 1 << ". zapis: ";
        string str;
        int num;
        cin >> str >> num;
        Osoba os;
        os.setGodine(num);
        os.setIme(str);
        A[i] = os;
    }

    insertionSort(A, n);

    for (int i = 0; i < n; ++i) {
        cout << A[i].getGodine() << ", " << A[i].getIme() << endl;
    }
}
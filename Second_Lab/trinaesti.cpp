#include <iostream>

using namespace std;

class Vozilo {
    private:
        string model;
        int godinaProizvodnje;
    public:
        Vozilo(): model(" "), godinaProizvodnje(0) {};
        Vozilo(string model, int godinaProizvodnje) {
            this->model = model;
            this->godinaProizvodnje = godinaProizvodnje;
        }
        string getModel() {
            return this->model;
        }
        int getGodinaProizvodnje() {
            return this->godinaProizvodnje;
        }
        void setModel(string model) {
            this->model = model;
        }
        void setGodinaProizvodnje(int godinaProizvodnje) {
            this->godinaProizvodnje = godinaProizvodnje;
        }
        bool operator<(const Vozilo &drugo) {
            if (this->model < drugo.model) {
                return true;
            } else if (this->model == drugo.model) {
                if (this->godinaProizvodnje > drugo.godinaProizvodnje) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi) {
    Vozilo temp = prvi;
    prvi = drugi;
    drugi = temp;
}

template <typename T>
void SelectionSort(T A[], int N) {
    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i + 1; j < N; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        Zamijeni(A[i], A[min]);
    }
}

int main() {
    int n;
    cout << "Molimo upisite broj vozila: ";
    cin >> n;
    cin.ignore(1, '\n');
    Vozilo A[n];
    for (int i = 0; i < n; ++i) {
        cout << "Molimo upisite podatke za " << i + 1 << ". vozilo: ";
        Vozilo voz;
        string str;
        int num;
        cin >> str >> num;
        voz.setGodinaProizvodnje(num);
        voz.setModel(str);
        A[i] = voz;
    }
    SelectionSort(A, n);
    for (int i = 0; i < n; ++i) {
        cout << A[i].getModel() << ", " << A[i].getGodinaProizvodnje() << endl;
    }
}
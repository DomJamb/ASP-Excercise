#include <iostream>

using namespace std;

template <class T>
class Red {
    template <class X>
    struct Cvor {
        X data;
        Cvor<X> *next;
    };
    Cvor<T> *izlaz = nullptr;
    Cvor<T> *ulaz = nullptr;

    public:
        bool dodaj (double broj) {
            Cvor<T> *noviEl = new (nothrow) Cvor<T>();
            if (!noviEl) {
                return false;
            }
            noviEl->data = broj;
            noviEl->next = nullptr;
            if (!ulaz) {
                izlaz = noviEl;
            } else {
                ulaz->next = noviEl;
            }
            ulaz = noviEl;
            return true;
        }
        bool skini (double *broj) {
            if (!izlaz) {
                return false;
            }
            (*broj) = izlaz->data;
            Cvor<T> *tmp = izlaz;
            izlaz = izlaz->next;
            if (izlaz == nullptr) {
                ulaz == nullptr;
            }
            delete tmp;
            return true;
        }
};

int main() {

    int n;
    cout << "Molimo unesite n: ";
    cin >> n;

    Red<double> *red = new Red<double>();
    for (int i = 0; i < n; ++i) {
        cout << "Molimo unesite " << i + 1 << ". broj: ";
        double el;
        cin >> el;
        red->dodaj(el);
    }

    double num;
    while(red->skini(&num)) {
        cout << num << " ";
    }
    cout << endl;
}
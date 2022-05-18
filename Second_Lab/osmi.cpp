#include <iostream>
#include <ctime>

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

        bool poljeURed (int polje[], int n) {
            if (n < 1) {
                return true;
            }
            bool test = dodaj(polje[n-1]);
            cout << polje[n-1] << " ";
            if (!test) {
                return false;
            }
            return poljeURed(polje, n-1);
        }
};

int main() {

    srand(time(NULL));
    Red<double> *red = new Red<double>();
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 10 + 1;
    }

    cout << red->poljeURed(arr, 10);
}
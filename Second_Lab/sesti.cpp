#include <iostream>

using namespace std;

template <class T>
class Red {
    private:
        static const int MAX = 10;
        T queue[MAX];
        int ulaz = 0;
        int izlaz = 0;
    public:
        bool dodaj (double broj);
        bool skini (double *broj) {
            if (ulaz == izlaz) {
                return false;
            }
            (*broj) = queue[izlaz];
            izlaz = (izlaz + 1) % MAX;
            return true;
        }
};

template <typename T>
bool Red<T>::dodaj(double broj) {
    if ((ulaz + 1) % MAX == izlaz) {
        return false;
    }
    queue[ulaz] = broj;
    ulaz = (ulaz + 1) % MAX;
    return true;
}

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
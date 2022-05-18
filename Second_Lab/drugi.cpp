#include <iostream>

using namespace std;

template <class T>
class Lista {
    template <class X>
    struct cvor {
        X data;
        cvor<X> *next;
        cvor<X> *prev;
    };
    cvor<T> *head = nullptr;
    cvor<T> *tail = nullptr;

    public:
        bool upis (T element) {
            cvor<T> *noviEl = new (nothrow) cvor<T>;
            if (!noviEl) {
                return false;
            }
            noviEl->data = element;
            noviEl->next = nullptr;
            noviEl->prev = nullptr;
            if (!tail) {
                head = noviEl;
            } else {
                tail->next = noviEl;
                noviEl->prev = tail;
            }
            tail = noviEl;
            return true;
        }

        void ispis() {
            cvor<T> *p = head;
            while (p) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
};

int main() {
    int n;
    Lista<string> *list = new Lista<string>();
    cout << "Molim upisite n: ";
    cin >> n;
    cin.ignore(1,'\n');
    for (int i = 0; i < n; ++i) {
        cout << "Molim upisite " << i+1 << ". string: ";
        string el;
        getline(cin, el);
        list->upis(el);
    }
    list->ispis();
}
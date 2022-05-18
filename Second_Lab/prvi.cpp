#include <iostream>

using namespace std;

template <class T>
class Lista {
    template <class X>
    struct cvor {
        X data;
        cvor<X> *next;
    };
    cvor<T> *head = nullptr;

    public:
        bool upis (T element) {
            cvor<T> *noviEl = new (nothrow) cvor<T>;
            if (!noviEl) {
                return false;
            }
            noviEl->data = element;
            cvor<T> **p;
            for (p = &head; *p && element > (*p)->data; p = &((*p)->next))
            ;
            noviEl->next = *p;
            *p = noviEl;
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
    Lista<int> *list = new Lista<int>();
    cout << "Molim upisite n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Molim upisite " << i+1 << ". broj: ";
        int el;
        cin >> el;
        list->upis(el);
    }
    list->ispis();
}
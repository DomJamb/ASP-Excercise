#include <iostream>
#include <ctime>

using namespace std;

template <class T> 
class Stog {

    template <class X>
    struct elStoga {
        X item;
        elStoga<X> *next;
    };

    elStoga<T> *top = nullptr;

    public:
        bool push(T item);
        bool pop(T &item) {
            if (top == nullptr)
                return false;
            item = top->item;
            elStoga<T> *tmp = top;
            top = top->next;
            delete tmp;
            return true;
        }
        void print() {
            T item;
            Stog<T> *pom = new Stog<T>();
            while (pop(item)) {
                pom->push(item);
                cout << item << " ";
            }
            cout << endl;
            while (pom->pop(item)) {
                push(item);
            }
        }
};

template <typename T>
bool Stog<T>::push(T item) {
    elStoga<T> *el = new (nothrow) elStoga<T>();
    if (!el) {
        return false;
    }
    el->item = item;
    el->next = top;
    top = el;
    return true;
}

int main() {

    srand(time(NULL));
    Stog<int> *stog = new Stog<int>();
    for (int i = 0; i < 101; ++i) {
        stog->push(rand() % 10 + 1);
    }

    stog->print();
}
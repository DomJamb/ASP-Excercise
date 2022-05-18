#include <iostream>
#include <ctime>

using namespace std;

template <class T>
class Stog {
    private:
        static const int MAX = 10;
        T stack[MAX];
        int top = -1;
    public:
        bool push(T item) {
            if (top >= MAX)
                return false;
            stack[++top] = item;
            return true;
        }
        bool pop(T &item) {
            if (top < 0) {
                return false;
            }
            item = stack[top--];
            return true;
        }
        void print();
};

template <typename T>
void Stog<T>::print() {
    T item;
    Stog<T> *pom = new Stog<T>();
    while (pop(item)) {
        pom->push(item);
    }
    while (pom->pop(item)) {
        cout << item << " ";
        push(item);
    }
    cout << endl;
}

int main() {

    Stog<int> *stog = new Stog<int>();
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        stog->push(rand() % 10 + 1);
    }
    stog->print();
}
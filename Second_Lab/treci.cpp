#include <iostream>
#include <ctime>

using namespace std;

template <class T>
class Stog {
    private:
        static const int MAX = 100;
        T *stack = new T[MAX];
        int top = -1;
    public:
        ~Stog() {
            delete[] stack;
        }
        bool push(T item) {
        if (top >= MAX)
            return false;
        stack[++top] = item;
        return true;
   }
};

int main() {

    Stog<int> *stog = new Stog<int>();
    srand(time(NULL));
    for (int i = 0; i < 101; ++i) {
        stog->push(rand());
    }
}
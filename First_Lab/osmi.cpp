#include <iostream>

using namespace std;

class SanitizedString {
    private:
    string str;
    public:
    SanitizedString(string str): str(str) {
        removeNonAlphaChars();
        removeDuplicateWhitespace();
    }
    void removeDuplicateWhitespace() {
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == ' ' && str[i - 1] == ' ') {
                //str.erase(str.begin() + i);
                string newstr = str.substr(0, i) + str.substr(i+1);
                str = newstr;
                i--;
            }
        }
    }
    void removeNonAlphaChars() {
        for (int i = 0; i < str.size(); ++i) {
            if (!(isalpha(str[i]) || str[i] == ' ')) {
                //str.erase(str.begin() + i);
                string newstr = str.substr(0, i) + str.substr(i + 1);
                str = newstr;
                i--;

            }
        }
    }
    friend ostream& operator<<(ostream &s, const SanitizedString &str);
};

ostream& operator<<(ostream &os, const SanitizedString &str)
{
    os << str.str;
    return os;
}

int main() {

    string str;
    cout << "Molimo upisite string: " <<endl;
    getline(cin, str);

    SanitizedString new_str(str);
    cout << new_str << endl;
}
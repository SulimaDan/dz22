#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;                   
    size_t size;                 
    static int objectCount;     

public:
   
    String() : String(80) {}

   
    String(size_t size) : size(size) {
        str = new char[size + 1];
        str[0] = '\0'; 
        objectCount++;
    }

    String(const char* input) : size(strlen(input)) {
        str = new char[size + 1];
        strcpy(str, input);
        objectCount++;
    }

    ~String() {
        delete[] str;
        objectCount--;
    }

    void input() {
        cout << "Введіть рядок: ";
        cin.ignore();
        cin.getline(str, size);
    }

    void print() const {
        cout << "Рядок: " << str << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {

    String defaultString;
    defaultString.print();
    String customString(50);
    customString.input();
    customString.print();

    String initializedString("Привіт, світ!");
    initializedString.print();

    cout << "Кількість об'єктів: " << String::getObjectCount() << endl;
    return 0;
}

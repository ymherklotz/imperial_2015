#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "Hello";
    string str2 = "Hella";
    if(str1 == str2) {
        cout << str1 << " equals " << str2 << endl;
    } else if(str1 < str2) {
        cout << str1 << " is smaller than " << str2 << endl;
    } else if(str1 > str2){
        cout << str1 << " is greater than " << str2 << endl;
    }
}

#include<iostream>

using namespace std;

int main() {
    char str[1000];
    char cpy[1000];
    cin >> str;
    char* ptr1 = str;
    char* ptr2 = cpy;
    while(*ptr1 != '\0') {
        if(*ptr1 >= 'w') {
            *ptr2 = *ptr1 - 'w' + 'a';
        } else {
            *ptr2 = *ptr1 + 4;
        }
        ptr1++;
        ptr2++;
    }
    *ptr2 = '\0';
    cout << cpy;
}

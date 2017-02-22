#include<iostream>

using namespace std;

int rev(char* ptr) {
    if(*ptr == '\0') return 0;
    else rev(ptr + 1);
    cout << *ptr;
    return 0;
}

int main() {
    char str[1000];
    cin >> str;
    char *ptr = str;
    rev(ptr);
}

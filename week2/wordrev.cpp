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
    char cpy[1000];
    char *ptr_cpy = cpy;
    while(*ptr != '\0') {
        *ptr_cpy = *ptr;
        if(*ptr == '_') {
            *ptr_cpy = '\0';
            rev(cpy);
            ptr_cpy = cpy;
            ptr_cpy--;
            cout << '_';
        }
        ptr_cpy++;
        ptr++;
    }
    *ptr_cpy = '\0';
    rev(cpy);

}

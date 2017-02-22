#include<iostream>

using namespace std;

int rev(char* ptr, char* start, char* first) {
    if(*ptr == '\0') return 0;
    if(*ptr == '_') {
        start = ptr+1;
    }
    if(*ptr != '\0') rev(ptr + 1, start, first);
    if(*ptr == '_' || ptr == first) {
        while(*start != '\0' && *start != '_') {
            cout << *start;
            start++;
        }
        if(ptr != first) cout << '_';
    }
    return 0;
}

int main() {
    char str[1000];
    cin >> str;
    char *ptr = str;
    char *start = str;
    rev(ptr, start, str);
}

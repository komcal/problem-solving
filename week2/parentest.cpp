#include<iostream>

using namespace std;

int main() {
    char str[1000];
    int n;

    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> str;
        char *ptr = str;
        char stack[1000];
        char *t = stack;
        int check = 0;
        while(*ptr != '\0') {
            if(*ptr == '(' || *ptr == '{' || *ptr == '[') {
                *t = *ptr;
                t++;
            }
            else {
                if(t == stack) break;
                char data = *(--t);
                if(*ptr == ')' && data != '(') break;
                else if(*ptr == '}' && data != '{') break;
                else if(*ptr == ']' && data != '[') break;
            }
            ptr++;
        }
        if(*ptr == '\0' && t == stack) check = 1;
        if(check) cout <<"yes" << endl;
        else cout << "no" << endl;
    }
}

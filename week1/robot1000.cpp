#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {
    char str [1000];
    int x = 0, y = 0;

    cin >> str;

    int len = strlen(str);

    for(int i = 0 ; i < len ; i++) {
        char direction = str[i];
        switch(direction) {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            case 'Z':
                x = 0;
                y = 0;
                break;
        }

    }
    cout << x << " " << y;

}

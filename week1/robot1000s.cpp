#include<iostream>
#include<cmath>


using namespace std;
int main() {
    char command[1000];
    int n, current_x = 0, current_y = 0;
    cin >> command;
    cin >> n;
    char *ptr = command;

    while(*ptr != '\0') {
        char current_command = *ptr;
        int move_x = 0, move_y = 0;
        switch(current_command) {
            case 'N':
                move_y = 1;
                break;
            case 'S':
                move_y = -1;
                break;
            case 'E':
                move_x = 1;
                break;
            case 'W':
                move_x = -1;
                break;
        }
        if (move_x != 0 && n > 0 && abs(current_x + move_x) >= abs(current_x)) {
            current_x += move_x;
        }
        else if (move_y != 0 && n > 0 && abs(current_y + move_y) >= abs(current_y)) {
            current_y += move_y;
        }
        else if (n > 0) {
            n--;
        }
        else if (n <= 0) {
            current_x += move_x;
            current_y += move_y;
        }
        ptr++;

    }
    current_x = abs(current_x);
    current_y = abs(current_y);
    while(n > 0) {
        if(current_x > 0) {
            if(current_x > 0) current_x--;
        }
        else if(current_y > 0) {
            if(current_y > 0) current_y--;
        }
        n--;
    }
    cout << (current_x + current_y) *2;
}

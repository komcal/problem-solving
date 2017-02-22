#include<iostream>

using namespace std;

char compass[5]  = "NESW";

int turn (char command, char dir) {
    int round = 0;
    int index_command = 0, index_dir = 0;

    for(int i = 0 ; i < 4 ; i++) {
        if(compass[i] == command) index_command = i;
        if(compass[i] == dir) index_dir = i;
    }

    while(index_command != index_dir) {
        if(index_dir == 3) index_dir = 0;
        else index_dir++;

        round++;
    }

    return round;
}

int main() {
    char command[1000], current_dir = 'N';
    char output[10000];

    cin >> command;
    char *current_command = command;
    char *current_output = output;

    while(*current_command != '\0') {
        if(*current_command == current_dir) {
            *current_output = 'F';
            current_output++;
        }
        else if(*current_command == 'Z') {
            *current_output = 'Z';
            current_dir = 'N';
            current_output++;
        }
        else {
            int round = turn(*current_command, current_dir);
            current_dir = *current_command;
            for(int i = 0 ; i < round ; i++) {
                *current_output = 'R';
                current_output++;
            }
            *current_output = 'F';
            current_output++;
        }
        current_command++;
    }
    cout << output;
}

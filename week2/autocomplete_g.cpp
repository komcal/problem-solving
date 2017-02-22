#include<iostream>
#include<cstring>

using namespace std;

char auto_string[20];
char message[100000][100];

void find_word(char type[20], int n){
    for(int i = 0 ; i < n ; i++) {
        char* ptr_type = type;
        char* ptr_message = message[i];
        while(*ptr_type != '\0') {
            if(*ptr_type == *ptr_message) {
                ptr_type++;
                ptr_message++;
            }
            else {
                break;
            }
        }
        if(*ptr_type == '\0') {
            strcpy(auto_string, message[i]);
            break;
        }

    }
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> message[i];
    }
    for(int i = 0 ; i < n ; i++) {
        char* ptr = message[i];
        char type[20];
        int current_type = 0;
        while(*ptr != '\0') {
            type[current_type] = *ptr;
            current_type++;
            type[current_type] = '\0';
            count++;
            find_word(type, n);
            if(strcmp(message[i], auto_string) == 0) {
                break;
            }
            ptr++;
        }
    }
    cout << count;

}

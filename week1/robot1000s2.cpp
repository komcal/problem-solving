#include<iostream>
#include<cmath>

using namespace std;

int main() {
    char command [1000];
    int n;
    int N = 0, E = 0, S = 0, W = 0;
    cin >> command;
    cin >> n;
    char *ptr = command;
    while(*ptr != '\0') {
        switch(*ptr) {
            case 'N':
                N++;
                break;
            case 'E':
                E++;
                break;
            case 'S':
                S--;
                break;
            case 'W':
                W--;
                break;
        }
        ptr++;
    }
    while(n > 0) {
        if(N > 0 &&abs(N - 1 + S) > abs(N + S)) {
            N--;
        }
        else if(S < 0 && abs(N + S + 1) > abs(N + S)) {
            S++;
        }
        else if(E > 0 &&abs(E - 1 + W) > abs(E + W)) {
            E--;
        }
        else if(W < 0 && abs(E + W + 1) > abs(E + W)) {
            W++;
        }
        else {
            if (N > 0) N--;
            else if (S < 0) S++;
            else if (E > 0) E--;
            else if (W < 0) W++;
        }
        n--;
    }
    cout << (abs(N+S)+abs(E+W)) * 2 ;
}

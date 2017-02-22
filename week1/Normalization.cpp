#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    for (int i = 2 ; i <= x ; i++) {
        if(x % i == 0 && y % i == 0) {
            x /= i;
            y /= i;
            i = 1;
        }
    }
    cout << x << "/" << y;
}

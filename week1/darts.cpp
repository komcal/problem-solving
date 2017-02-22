#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n, x, y, score = 0;
    double range = 0;

    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cin >> x >> y;
        range = sqrt(x*x+y*y);
        if(range <= 2) {
            score += 5;
        }
        else if(range <= 4) {
            score += 4;
        }
        else if(range <= 6) {
            score += 3;
        }
        else if(range <= 8) {
            score += 2;
        }
        else if(range <= 10) {
            score += 1;
        }
    }
    cout  << score;
}

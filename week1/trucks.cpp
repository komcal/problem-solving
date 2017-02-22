#include<iostream>

using namespace std;

int main() {
    int n, weight, max = 1000, count = 1, current_weight = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> weight;
        if(weight + current_weight <= max) {
            current_weight += weight;
        } else {
            count++;
            current_weight = weight;
        }
    }
    cout << count;
}

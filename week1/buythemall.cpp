#include<iostream>

using namespace std;

int main() {
    int types[4], n, type;
    int price[4], min = 1000000000;
    cin >> types[1];
    cin >> types[2];
    cin >> types[3];
    cin >> n;

    for(int i = 0 ; i < 4 ; i++) {
        price[i] = 0;
    }

    for(int i = 0 ; i < n ; i++) {
        cin >> type;
        price[type] += types[type];
    }
    for(int i = 1 ; i < 4 ; i++) {
        min = (min > price[i])? price[i] : min;
    }

    cout << min;
}

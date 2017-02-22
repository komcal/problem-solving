#include<iostream>

using namespace std;
int main() {
    int n, data, sum = 0, i = 0;
    cin >> n;
    for(i = 0 ; i < n ; i++){
        cin >> data;
        if(data > 0) {
            sum += data;
        }
    }
    cout << sum;
}

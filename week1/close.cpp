#include<iostream>
#include<cmath>
#include <cstdlib>

using namespace std;

int main() {
    int n, target, count = 0;
    int ranges[10000];
    cin >> n >> target;
    for(int i = 0 ; i < n ; i++) {
        cin >> ranges[i];
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            int between = abs(ranges[i] - ranges[j]);
            if(between <= target) {
                count++;
            }
        }
    }
    cout << count;

}

#include<iostream>

using namespace std;
bool check_prime(int p)
{
      if (p <= 1) {
              return false;
       }
      int count = 0;
      for(int i=2 ; i<p ; i++){
          if(p%i == 0){
              count++;
              break;
          }
      }
      if(count == 0)
          return true;
      return false;

}
int main() {
    int n;
    cin >> n;
    n++;
    while(!check_prime(n)) n++;
    cout << n;

}

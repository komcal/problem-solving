#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n, i = 0, sum = 0;
    char str[10000];
    char number[10], sign = 'x';
    scanf("%d ", &n);
    cin.getline(str,sizeof(str));
    char *ptr = str;
    while(*ptr != '\0') {
        if(*ptr == ' ') {
            number[i] = '\0';
            i = 0;
            if(number[0] != '\0') {
                if(sign == 'x') sum = atoi(number);
                else if(sign == '+') sum += atoi(number);
                else if(sign == '-') sum -= atoi(number);
            }
        }
        else if(*ptr == '+' || *ptr == '-') {
            sign = *ptr;
        }
        else {
            number[i] = *ptr;
            i++;
        }
        ptr++;
    }
    number[i] = '\0';
    if(sign == '+') sum += atoi(number);
    else if(sign == '-') sum -= atoi(number);
    cout << sum << endl;
}

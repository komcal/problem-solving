#include<iostream>
#include<cstring>

using namespace std;

char num_set1[1000];
char num_set2[1000];
void add_zero(char* big_num, char* num, int dif){
    char* ptr = num_set2;
    int count = 0;
    while(*big_num != '\0') {
        if(count < dif) {
            count++;
            *ptr = '0';
        }
        else {
            *ptr = *num;
            num++;
        }
        big_num++;
        ptr++;
    }
}
void add_zero_big(char* num){
    char* ptr = num_set1;
    *ptr = '0';
    ptr++;
    while(*num != '\0'){
        *ptr = *num;
        ptr++;
        num++;
    }

}

int main() {
    char num1[1000], num2[1000];
    char small_num[1000], big_num[1000];
    char  ans[1000];

    cin >> num1;
    cin >> num2;
    if(strlen(num1) > strlen(num2)) {
        add_zero_big(num1);
        strcpy(big_num, num1);
        int dif = strlen(big_num) - strlen(num2);
        add_zero(big_num, num2, dif);
        strcpy(small_num, num_set2);
    }
    else {
        add_zero_big(num2);
        strcpy(big_num, num_set1);
        int dif = strlen(big_num) - strlen(num1);
        add_zero(big_num, num1, dif);
        strcpy(small_num, num_set2);
    }
    int len = strlen(big_num);
    int r = '0';
    for(int i = strlen(big_num)-1 ; i >= 0 ; i--) {
        ans[i] = (big_num[i] - '0' + small_num[i] - '0' + r - '0') % 10 + '0';
        r = (big_num[i] - '0' + small_num[i] - '0' + r - '0') / 10 + '0';
    }
    char* ptr = ans;
    int start = 0;
    while(*ptr != '\0') {
        if(*ptr != '0') start = 1;
        if(start) cout << *ptr;
        ptr++;
    }
}

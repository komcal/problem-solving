#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
      
    char *ptr1 = src;
    char *ptr2 = dest;

    while(*ptr1 != '\0'){
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }
    *ptr2 = '\0';

}

int main()
{
      char st1[1000];
        char st2[1000];

          cin.getline(st1,1000);
            copy_string(st1,st2);

              cout << st2 << endl;
}

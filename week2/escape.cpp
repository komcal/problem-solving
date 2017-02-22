#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st)
{
     while(*st != '\0')  {
         *dest = *st;
         dest++;
         st++;
     }
      return dest;
}

void escape(char* src, char *dest)
{
    char* ptr1 = src;
    char* ptr2 = dest;
    while(*ptr1 != '\0') {
        if(*ptr1 == '<') {
            char st[1000] = "&lt;";
            ptr2 = write_chars(ptr2, st);
        }
        else if(*ptr1 == '>') {
            char st[1000] = "&gt;";
            ptr2 = write_chars(ptr2, st);
        }
        else if(*ptr1 == '\"') {
            char st[1000] = "&quot;";
            ptr2 = write_chars(ptr2, st);
        }
        else {
            *ptr2 = *ptr1;
            ptr2++;
        }
        ptr1++;
    }
    *ptr2 = '\0';

}

int main()
{
      char st[1000];
      char out[1000];
      int l;

      cin.getline(st,1000);
      escape(st,out);
      cout << out << endl;
}

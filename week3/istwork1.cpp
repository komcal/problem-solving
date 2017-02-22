#include<iostream>

using namespace std;
typedef struct _NODE
{
    int value;
    struct _NODE *next;
    struct _NODE *prev;
} NODE;

NODE *head = NULL;

void create_list(){
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->value = 0;
    ptr->next = NULL;
    ptr->prev = NULL;
    head = ptr;
}
void insert(int data) {
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->value = data;

    ptr->next = head->next;
    ptr->prev = head;
    if(head->next != NULL)
        head->next->prev = ptr;
    head->next = ptr;
}
void print_node(){
    NODE *ptr = head->next;
    while(ptr != NULL) {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}
void delete_index(int data) {
    NODE *ptr = head->next;
    int i = 1;
    while(ptr != NULL && i != data) {
        ptr = ptr->next;
        i++;
    }
    if(ptr != NULL) {
        if(ptr->next != NULL)
            ptr->next->prev = ptr->prev;
        if(ptr->prev != NULL)
            ptr->prev->next = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
        delete ptr;
    }
}

int main() {
    int n, data;
    char command[2];
    cin >> n;

    create_list();
    for(int i = 0 ; i < n ; i++) {
        cin >> command >> data;
        if(command[0] == 'I') {
            insert(data);
        }
        else if (command[0] == 'D') {
            delete_index(data);
        }
    }
    print_node();
}


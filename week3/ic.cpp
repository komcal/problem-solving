#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;
typedef struct _NODE
{
    int value;
    struct _NODE *next;
    struct _NODE *prev;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;

void insert_right(int data) {
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->value = data;
    ptr->next = NULL;
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
}
void create_list(){
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->value = 0;
    ptr->next = NULL;
    ptr->prev = NULL;
    head = ptr;
    tail = head;
}
void insert_left(int data) {
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->value = data;

    ptr->next = head->next;
    ptr->prev = head;
    if(head->next != NULL)
        head->next->prev = ptr;
    else {
        tail = ptr;
    }
    head->next = ptr;
}
void print_node(){
    NODE *ptr = head->next;
    while(ptr != NULL) {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}
void rotate_left() {
    NODE *ptr = head->next;
    if(ptr != NULL) {
        if(ptr->next != NULL)
            ptr->next->prev = ptr->prev;
        else
            tail = ptr->prev;
        if(ptr->prev != NULL)
            ptr->prev->next = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
        insert_right(ptr->value);
        delete ptr;
    }
}
void rotate_right() {
    NODE *ptr = tail;
    if(ptr != NULL) {
        if(ptr->next != NULL)
            ptr->next->prev = ptr->prev;
        else
            tail = ptr->prev;
        if(ptr->prev != NULL)
            ptr->prev->next = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
        insert_left(ptr->value);
        delete ptr;
    }
}

int main() {
    int n, data;
    char command[3];
    cin >> n;

    create_list();
    for(int i = 0 ; i < n ; i++) {
        cin >> command;
        if(strcmp(command, "li") == 0) {
            cin >> data;
            insert_left(data);
        }
        else if (strcmp(command, "ri") == 0) {
            cin >> data;
            insert_right(data);
        }
        else if (strcmp(command, "lr") == 0) {
            rotate_left();
        }
        else if (strcmp(command, "rr") == 0) {
            rotate_right();
        }
    }
    print_node();
}


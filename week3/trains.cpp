#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

typedef struct _NODE
{
    int tain;
    int station;
    struct _NODE *next;
    struct _NODE *order_next;
    struct _NODE *prev;
    struct _NODE *order_prev;
} NODE;

NODE *head = NULL;

void create_list() {
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->tain = 0;
    ptr->station = 0;
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->order_next = NULL;
    ptr->order_prev = NULL;
    head = ptr;
}
void insert_station(int tain, int station) {
    NODE *ptr = head;
    while(ptr->order_next != NULL && ptr->station < station) {
        ptr = ptr->order_next;
    }
    NODE *new_station = (NODE*)malloc(sizeof(NODE));
    new_station->tain = tain;
    new_station->station = station;
    if(ptr->order_next == NULL && ptr->station < station){
        new_station->next = NULL;
        new_station->prev = NULL;
        ptr->order_next = new_station;
        new_station->order_prev = ptr;
        new_station->order_next = NULL;
    }
    else if(ptr->station > station) {
        new_station->next = NULL;
        new_station->prev = NULL;
        ptr->order_prev->order_next = new_station;
        new_station->order_prev = ptr->order_prev;
        new_station->order_next = ptr;
        ptr->order_prev = new_station;
    }
    else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        new_station->prev = ptr;
        ptr->next = new_station;
        new_station->next = NULL;
    }
}
void move_station(int i, int j) {
    NODE *move_station = head;
    NODE *station = head;
    NODE *runner = head;
    while(runner != NULL) {
        if(runner->station == i) {
            move_station = runner;
        }
        if(runner->station == j) {
            station = runner;
        }
        runner = runner->order_next;
    }
    if(move_station != head && station != head) {
        NODE *ptr = station;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        if(move_station->order_next == NULL) {
            ptr->next = move_station;
            move_station->order_prev->order_next = NULL;
            move_station->prev = ptr;
        }
        else {
            move_station->order_next->order_prev = move_station->order_prev;
            move_station->order_prev->order_next = move_station->order_next;
            ptr->next = move_station;
            move_station->prev = ptr;
        }
    }
}
void print_all() {
    head = head->order_next;
    while(head != NULL) {
        NODE *ptr = head;
        while(ptr != NULL) {
            cout << ptr->tain << endl;
            ptr = ptr->next;
        }
        head = head->order_next;
    }
}

int main() {
    int n, x, j;
    char c[10];
    cin >> n;
    create_list();
    for(int i = 0 ; i < n ; i++) {
        cin >> c >> x >> j;
       if(strcmp(c, "N") == 0) {
            insert_station(x, j);
       }
       else if(strcmp(c, "M") == 0) {
            move_station(x, j);
       }
    }
    print_all();

}

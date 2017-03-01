#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef struct _NODE
{
    int tain;
    int station;
    struct _NODE *next;
    struct _NODE *prev;
} NODE;

NODE *head[100001];
NODE *tail[100001];

void insert_station(int tain, int station) {
    if(head[station] == head[100000]) {
        int i = station;
        NODE *ptr = (NODE*)malloc(sizeof(NODE));
        ptr->next = NULL;
        head[i] = ptr;
        tail[i] = ptr;
    }
    NODE *ptr = tail[station];
    NODE *new_station = (NODE*)malloc(sizeof(NODE));
    new_station->tain = tain;
    new_station->station = station;
    ptr->next = new_station;
    new_station->prev = ptr;
    new_station->next = NULL;
    tail[station] = new_station;
}
void move_station(int i, int j) {
    if(head[j] == head[100000]) {
        NODE *ptr = (NODE*)malloc(sizeof(NODE));
        ptr->next = NULL;
        head[j] = ptr;
        tail[j] = ptr;
    }
    if(head[i] == head[100000]) {
        NODE *ptr = (NODE*)malloc(sizeof(NODE));
        ptr->next = NULL;
        head[i] = ptr;
        tail[i] = ptr;
    }
    NODE *move_station = head[i];
    NODE *station = tail[j];
    if(move_station->next != NULL) {
        station->next = move_station->next;
        move_station->next->prev = station;
        move_station->next = NULL;
        tail[j] = tail[i];
        tail[i] = head[i];
    }
}
void print_all() {
    for(int i = 0 ; i < 100000 ; i++) {
        if(head[i] != head[100000]) {
            NODE *ptr = head[i]->next;
            while(ptr != NULL) {
                printf("%d\n", ptr->tain);
                ptr = ptr->next;
            }
        }
    }
}

int main() {
    int n, x, j;
    char c[10];
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> c >> x >> j;
        j-=1;
       if(c[0] == 'N') {
            insert_station(x, j);
       }
       else {
            x -=1;
            move_station(x, j);
       }
    }
    print_all();

}

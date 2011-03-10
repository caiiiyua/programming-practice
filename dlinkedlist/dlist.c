/*
* File: dlist.c
* Author: Cai Yuanqing <Yuanqing.Cai@tieto.com>
* Brief: This file generated from a template of simple C source code
*
* Copyright (c) 2009 - 2011
*
* Licensed under the Academic Free License version 2.1
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
* History:
* ================================================================
* date | who | what
*
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct _Node Node;
struct _Node {
    int value;
    Node *next;
    Node *prev;
};

typedef struct _DList DList;
struct _DList {
    Node *head;
    Node *tail;
    int length;
};

DList * dlist_init();
void dlist_deinit(DList *dl);
void dlist_append_head(DList *dl, int value);
void dlist_append_tail(DList *dl, int value);
void dlist_remove_head(DList *dl);
void dlist_remove_tail(DList *dl);
void dlist_print_head(DList *dl);
void dlist_print_tail(DList *dl);
void dlist_insert_before(DList *dl, int value, Node *B);
void dlist_insert_after(DList *dl, int value, Node *A);
void dlist_remove_before(DList *dl, Node *B);
void dlist_remove_after(DList *dl, Node *A);
void dlist_remove_node(DList *dl, Node *theNode);

DList *dlist_init() {
    DList *dl = (DList *)malloc(sizeof(DList));
    dl->length = 0;
    dl->head = NULL;
    dl->tail = NULL;
    return dl;
}

void dlist_deinit(DList *dl) {
    if(dl == NULL) {
        printf("List is NULL\n");
        return;
    }

    while(dl->tail != NULL) {
        dlist_remove_tail(dl);
    }
    free(dl);
    dl = NULL;
    printf("List deinited!\n");
}

void dlist_remove_head(DList *dl) {
    Node * tNode = NULL;
    if(dl == NULL) {
        printf("List is NULL\n");
        return;
    }

    if(dl->head != NULL) {
        tNode = dl->head->next;
        printf("free node: value is %d\n",dl->head->value);
        free(dl->head);
        if(tNode != NULL) {
            tNode->next = NULL;
        }
        dl->head = tNode;
    }
}

void dlist_remove_tail(DList *dl) {
    Node * tNode = NULL;
    if(dl == NULL) {
        printf("List is NULL\n");
        return;
    }

    if(dl->tail != NULL) {
        tNode = dl->tail->prev;
        printf("free node: value is %d\n",dl->tail->value);
        free(dl->tail);
        if(tNode != NULL) {
            tNode->next = NULL;
        }
        dl->tail = tNode;
    }
}

void dlist_append_head(DList *dl, int value) {

    Node *newNode = NULL;

    if(dl == NULL) {
        return;
    }

    newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;

    if(dl->head != NULL) {
        newNode->next = dl->head;
        newNode->prev = NULL;
        dl->head->prev = newNode;
        dl->head = newNode;
    }
    else {
        newNode->next = newNode->prev = NULL;
        dl->head = newNode;
        dl->tail = newNode;
    }

    dl->length++;
}

void dlist_append_tail(DList *dl, int value) {

    Node *newNode = NULL;

    if(dl == NULL) {
        return;
    }

    newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;

    if(dl->head != NULL) {
        newNode->next = NULL;
        newNode->prev = dl->tail;
        dl->tail->next = newNode;
        dl->tail = newNode;
    }
    else {
        newNode->next = newNode->prev = NULL;
        dl->head = newNode;
        dl->tail = newNode;
    }

    dl->length++;
}

void dlist_print_head(DList *dl) {
    Node * tNode = NULL;

    if(dl == NULL) {
        return;
    }

    if(dl->head == NULL) {
        printf("Double Linked List is empty!\n");
        return;
    }

    tNode = dl->head;
    while(tNode != NULL) {
        printf(" %d \n",tNode->value);
        if(tNode->next == NULL) {
            return;
        } else {
            tNode = tNode->next;
        }
    }

}

void dlist_print_tail(DList *dl) {
    Node * tNode = NULL;

    if(dl == NULL) {
        return;
    }

    if(dl->tail == NULL) {
        printf("Double Linked List is empty!\n");
        return;
    }

    tNode = dl->tail;
    while(tNode != NULL) {
        printf(" %d \n",tNode->value);
        if(tNode->prev == NULL) {
            return;
        } else {
            tNode = tNode->prev;
        }
    }

}

int main(int argc, char *argv[])
{
    printf("Hello Double linked list!\n");
    DList *dl = dlist_init();
    dlist_append_tail(dl, 1);
    dlist_append_tail(dl, 2);
    dlist_append_head(dl, 3);
    dlist_append_tail(dl, 4);
    dlist_append_head(dl, 5);
    dlist_print_tail(dl);
    dlist_print_head(dl);
    dlist_deinit(dl);

    return 0;
}

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
typedef struct _Node node;
struct _Node {
    int value;
    node *next;
    node *prev;
};

typedef struct _Dlist dlist;
struct _Dlist {
    node *head;
    node *tail;
    int length;
};

dlist * initList();
void deinitList(dlist *dl);
void appendHead(dlist *dl, int value);
void appendTail(dlist *dl, int value);
void removeHead(dlist *dl);
void removeTail(dlist *dl);
void insertBefore(dlist *dl, int value, node *B);
void insertAfter(dlist *dl, int value, node *A);
void removeBefore(dlist *dl, node *B);
void removeAfter(dlist *dl, node *A);
void removeNode(dlist *dl, node *theNode);
void printHead(dlist *dl);
void printTail(dlist *dl);

dlist *initList() {
    dlist *dl = (dlist *)malloc(sizeof(dlist));
    dl->length = 0;
    dl->head = NULL;
    dl->tail = NULL;
    return dl;
}

void deinitList(dlist *dl) {
    if(dl == NULL) {
        printf("List is NULL\n");
        return;
    }

    while(dl->tail != NULL) {
        removeTail(dl);
    }
    free(dl);
    dl = NULL;
    printf("List deinited!\n");
}

void removeTail(dlist *dl) {
    node * tNode = NULL;
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

void appendTail(dlist *dl, int value) {

    node *newNode = NULL;

    if(dl == NULL) {
        return;
    }

    newNode = (node *)malloc(sizeof(node));
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

void printHead(dlist *dl) {
    node * tNode = NULL;

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

void printTail(dlist *dl) {
    node * tNode = NULL;

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
    dlist *dl = initList();
    appendTail(dl, 1);
    appendTail(dl, 2);
    appendTail(dl, 3);
    appendTail(dl, 4);
    appendTail(dl, 5);
    printTail(dl);
    printHead(dl);
    deinitList(dl);
    return 0;
}

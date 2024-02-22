
#include "StrList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
    char* _data;
    struct _node * _next;
}Node;
struct _StrList
{
    Node* head;
    size_t _size;
};

char* readWords(){
    char* str = NULL;
    size_t size = 0;

    getline(&str, &size, stdin);

    if(strlen(str) > 0 && str[strlen(str)-1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }

    return str;

}

int countSpaces(const char* str) {
    int count = 0;

    while (*str != '\0') {
        if (*str == ' ') {
            count++;
        }
        str++;
    }

    return count;
}

Node* Node_alloc(char* word, Node* next){
    Node* p = (Node*)malloc(sizeof(Node));
    p->_data=word;
    p->_next=next;

    return p;
}

StrList* StrList_alloc(){
    StrList* list = (StrList*) malloc(sizeof(StrList));
    list->head=NULL;
    list->_size = 0;

    return list;
}

void Node_free(Node* node) {
    if (node != NULL) {
        free(node->_data);  // Free the memory for the data
        free(node);         // Free the memory for the Node
    }
}

void StrList_free(StrList* StrList){
    if(StrList == NULL) return;
    Node* p1 = StrList->head;
    Node* p2;
    while(p1 != NULL){
        p2=p1;
        p1=p1->_next;
        Node_free(p2);
    }
    
    StrList->head = NULL;
    
}

size_t StrList_size(const StrList* StrList){
    if(StrList != NULL){
        return StrList->_size;
    }   
        printf("SIZE IS NULL");
        return 0;
}


void StrList_insertLast(StrList* StrList, const char* data){
    Node* newNode = Node_alloc(strdup(data), NULL);
    if(newNode == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    // if the linked list is empty, then the new node should be the head.
    if(StrList->head == NULL){
        StrList->head = newNode;
    } else { //otherwise, we will travel all the way to the last node to insert last
        Node* current = StrList->head;
        while(current->_next != NULL){
            current = current->_next;
        }
        current->_next = newNode;
    }

    ++(StrList->_size); // at the end of the insertion, 1 node had been added to the list aka size++;

}

void StrList_insertAt(StrList* StrList, const char* data, int index) {
    Node* newNode = Node_alloc(strdup(data), NULL);
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    if (index >= 0 && index <= StrList->_size) {
        if (index == 0) {
            newNode->_next = StrList->head;
            StrList->head = newNode;
        } else {
            int currentIndex = 1;
            Node* current = StrList->head;
            while (currentIndex < index) {
                currentIndex++;
                current = current->_next;
            }
            newNode->_next = current->_next;
            current->_next = newNode;
        }

        ++(StrList->_size);
    } else {
        printf("Invalid index.");
    }
}


char* StrList_firstData(const StrList* StrList){
    return StrList->head->_data;
}

void StrList_print(const StrList* StrList){
    if(StrList != NULL && StrList->head != NULL){
        Node* current = StrList->head;
        while(current != NULL){
            if(current->_next == NULL){
                printf("%s", current->_data);
            } else {
                printf("%s ", current->_data);
            }
            
            current = current->_next;
        }
    } else {
        return;
    }

}

void StrList_printAt(const StrList* StrList, int index) {
    if (StrList != NULL) {
        if (index >= 0 && index < StrList->_size) {
            int currentIndex = 0;
            Node* current = StrList->head;

            while (currentIndex < index) {
                currentIndex++;
                current = current->_next;
            }

            printf("%s", current->_data);
        } else {
            printf("Invalid index.");
        }
    }
}


int StrList_printLen(const StrList* Strlist){
    if(Strlist != NULL){
        int sum = 0;
        Node* current = Strlist->head;
        while(current != NULL){
            sum = sum + (int) strlen(current->_data);
            current = current->_next;
        }
        return sum;
    }
    return 0;

}

int StrList_count(StrList* StrList, const char* data){
    if(StrList != NULL){
        int counter = 0;
        Node* current = StrList->head;
        while(current != NULL){
            if(strcmp(current->_data, data) == 0){
                counter++;
            }
            current = current->_next;
        }
        return counter;
    }
    return 0;

}

void StrList_remove(StrList* StrList, const char* data) {
    if (StrList != NULL && StrList->head != NULL) {
        Node* current = StrList->head;
        Node* prev = NULL;

        // Traverse the list to find and remove nodes with the specified data
        while (current != NULL) {
            if (strcmp(current->_data, data) == 0) {
                // Node with matching data found, remove it
                if (prev == NULL) {
                    // Removing the head
                    StrList->head = current->_next;
                    Node_free(current);
                    current = StrList->head;  // Move to the next node
                } else {
                    // Removing a node that is not the head
                    prev->_next = current->_next;
                    Node_free(current);
                    current = prev->_next;  // Move to the next node
                }
            } else {
                // No match, move to the next node
                prev = current;
                current = current->_next;
            }
        }
    }
}



void StrList_removeAt(StrList* StrList, int index){
    if(StrList != NULL && index >= 0 && index < StrList->_size){
        int currentIndex = 0;
        Node* current = StrList->head;
        Node* prev = NULL;
        if(index == 0){
            StrList->head = current->_next;
            Node_free(current);
            current = StrList->head; 
        } else {

        while(currentIndex < index){
            currentIndex++;
            prev = current;
            current = current->_next;
            }
            prev->_next = current->_next;
            Node_free(current);
        }

    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    if (StrList1 != NULL && StrList2 != NULL) {
        if (StrList1->_size == StrList2->_size) {
            Node* cur1 = StrList1->head;
            Node* cur2 = StrList2->head;

            while (cur1 != NULL) {
                if (strcmp(cur1->_data, cur2->_data) != 0) {
                    return 0;  // Lists are not equal
                }

                cur1 = cur1->_next;
                cur2 = cur2->_next;
            }

            return 1;  // Lists are equal
        }
    }

    return 0;  // Lists are not equal
}


StrList* StrList_clone(const StrList* Strlist) {
    if (Strlist != NULL) {
        StrList* clonedList = StrList_alloc();

        if (clonedList != NULL) {
            Node* originalCurrent = Strlist->head;

            while (originalCurrent != NULL) {
                StrList_insertLast(clonedList, originalCurrent->_data);
                originalCurrent = originalCurrent->_next;
            }

            return clonedList;
        } else {
            printf("Memory allocation failed for cloned list.\n");
        }
    }

    return NULL;
}



void StrList_reverse(StrList* StrList){
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = NULL;

    while(current != NULL){
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    StrList->head = prev;
}

void StrList_sort(StrList* StrList){
    Node* p = mergeSort(StrList->head);
    StrList->head = p; 
}

Node* mergeSort(Node* head){
    if(head == NULL || head->_next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->_next;

    while(fast != NULL && fast->_next != NULL){
        slow = slow->_next;
        fast = fast->_next->_next;
    }

    Node* right = slow->_next;
    slow->_next = NULL;

    head = mergeSort(head);
    right = mergeSort(right);

    return merge(head, right);
}

Node* merge(Node* left, Node* right){
    Node* result = NULL;

    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    if(strcmp(left->_data, right->_data) <= 0){
        result = left;
        result->_next = merge(left->_next, right);
    } else {
        result = right;
        result->_next = merge(left, right->_next);
    }

    return result;
}

int StrList_isSorted(StrList* StrList){
   if (StrList == NULL || StrList->head == NULL) {
        return 1; // An empty list or a single-node list is considered sorted
    }

    const Node* current = StrList->head;
    while (current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            return 0; // Not sorted
        }
        current = current->_next;
    }

    return 1; // Sorted
}


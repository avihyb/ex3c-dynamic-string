#include "StrList.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * StrList Program:
 *  
 * Dynamically allocates a string list to manage individual words from user-provided text.
 * Offers a variety of actions for manipulating the list, including:
 *
 * - Creating a new list from a string
 * - Adding, removing, and printing strings
 * - Counting characters and occurrences
 * - Reversing and sorting the list
 *
 * Program has been thoroughly checked with Valgrind to guarantee memory leak prevention.
 */

/**
 * PROGRAMS MENU:

 * (Upon entering the following number:)
 * 1. Creates a new StringList, user enters the desired number of words they want to add, and then the string.
 * 2. Add a string in a specific index. (Enter index then string)
 * 3. Print the StringList.
 * 4. Print the StringList length. (amount of nodes)
 * 5. Print string in a specific index.
 * 6. Print the number of characters in the list.
 * 7. Enter a string and returns the number of times it's in the list.
 * 8. Enter a string to delete it from the list (deletes all the nodes with that string).
 * 9. Enter an index and deletes the node in that index.
 * 10. Reverse the list. (Nodes reverse, not chars).
 * 11. Deletes the list.
 * 12. Checks if the list is lexicographically sorted.
 * 13. Sorts the list lexicographically.
 * 0. Exit.
 *
 */

int main() {
    int option;
    int words;
    int index;
    char* currentWords;
    StrList* list = StrList_alloc();
    

    while (true) {
        scanf("%d", &option); // recieving the option from the user

        switch (option) {
        case 1:
                scanf("%d", &words);
                getchar(); // avoiding the newline char
                currentWords = readWords();
                // user inputs the desired amount of words he would like to insert
                if(countSpaces(currentWords) == words - 1){ 
                    // using strtok(string, desired char to split by) to split the entered string into words,
                    // in order to insert each word as a node to the list.
                    char *word = strtok(currentWords, " "); 
                    while(word != NULL){
                        StrList_insertLast(list, word);
                        word = strtok(NULL, " ");
                    }
                } else {
                    printf("Error: words amount not equal");
                    break;
                }
               free(currentWords);
            
            break;

        case 2:
            scanf("%d", &index);
            getchar();
            currentWords = readWords();
             char *word = strtok(currentWords, " ");
                    while(word != NULL){
                        StrList_insertAt(list, currentWords, index);
                        word = strtok(NULL, " ");
                    }
                    free(currentWords);
            break;

        case 3:
            StrList_print(list);
            printf("\n");
            break;

        case 4:
            int size = StrList_size(list);
            printf("%d", size);
            printf("\n");
            break;

        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            printf("\n");
            break;

        case 6:
            int ans = StrList_printLen(list);
            printf("%d", ans);
            printf("\n");
            break;

        case 7: {
            getchar();
            currentWords = readWords();
            char *word = strtok(currentWords, " ");
                    while(word != NULL){
                        word = strtok(NULL, " ");
                    }
            int ans = StrList_count(list, currentWords);
            printf("%d", ans);
            printf("\n");
            free(currentWords);
            break;
        }

        case 8:
            currentWords = readWords();
            StrList_remove(list, currentWords);
            free(currentWords);
            break;

        case 9:
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;

        case 10:
            StrList_reverse(list);
            break;

        case 11:
            StrList_free(list);
            break;

        case 12:
            StrList_sort(list);
            break;

        case 13: {
            int sorted = StrList_isSorted(list);
            printf("%s\n", sorted ? "true" : "false");
            break;
        }

        case 0:
            free(list);
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}


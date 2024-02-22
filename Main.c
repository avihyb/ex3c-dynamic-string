#include "StrList.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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


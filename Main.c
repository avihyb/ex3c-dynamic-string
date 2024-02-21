#include "StrList.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
    int option;
    int words;
    int index;
    char* currentWord;
    StrList* list = StrList_alloc();

    while (true) {
        scanf("%d", &option);

        switch (option) {
        case 1:
            scanf("%d", &words);
            for (int i = 0; i < words; i++) {
                currentWord = readWord();
                StrList_insertLast(list, currentWord);
            }
            break;

        case 2:
            scanf("%d", &index);
            currentWord = readWord();
            StrList_insertAt(list, currentWord, index);
            break;

        case 3:
            StrList_print(list);
            break;

        case 4:
            int size = StrList_size(list);
            printf("%d", size);
            break;

        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;

        case 6:
            int ans = StrList_printLen(list);
            printf("%d", ans);
            break;

        case 7: {
            currentWord = readWord();
            int ans = StrList_count(list, currentWord);
            printf("%d", ans);
            break;
        }

        case 8:
            currentWord = readWord();
            StrList_remove(list, currentWord);
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
            printf("%s\n", sorted ? "Sorted" : "Not Sorted");
            break;
        }

        case 0:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}


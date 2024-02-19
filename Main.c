#include "StrLIst.h"
#include <stdbool.h>

int main(){
    char option;
    int words;
    

    while (true){
        scanf(" %c", &option);

        switch (option)
        {
        case 'A':
            scanf("%d", &words);
            break;


        case '0':
            return 0;
            break;
        
        default:
            break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "stackFunc.h"

// int push(int , int*, int **);

int main()
{
    int sel = 0;
    int top = -1;

    int stackSize = 0;
    int *stackSpace;

    while(1){
        system("cls");

        printf("(1)加入資料\n");
        printf("(2)彈出資料\n");
        printf("(3)顯示堆疊\n");
        printf("(4)退出\n");
        printf("輸入選項: "); scanf("%d", &sel); fflush(stdin);

        system("cls");

        if(sel == 1){
            if(stackSize == 0){
                printf("尚未建立堆疊空間 請輸入堆疊的空間大小: ");
                scanf("%d", &stackSize); fflush(stdin);

                stackSpace = (int *)malloc(sizeof(int) * stackSize);
                system("cls");
            }

            if(!intisFull(top, stackSize)){
                int value = 0;
                printf("當前top值為:%d\t剩餘空間:%d\n", top + 1, stackSize - (top + 1));
                printf("請輸入需要堆疊的值: ");
                scanf("%d", &value); fflush(stdin);

                push(stackSpace, &top, value);  // push(陣列, 頂端標籤, 疊入的值)
            }
        }
        else if(sel == 2){
            if(!isEmpty(top)){
                printf("彈出了: %d\n", pop(stackSpace, &top));
            }
        }
        else if(sel == 3){
            for(int i = 0; i <= top; i++){
                printf("%d ", stackSpace[i]);
            }

            printf("\n");
        }
        else if(sel == 4){
            break;
        }

        system("pause");
    }

    return 0;
}
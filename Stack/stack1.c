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

        printf("(1)�[�J���\n");
        printf("(2)�u�X���\n");
        printf("(3)��ܰ��|\n");
        printf("(4)�h�X\n");
        printf("��J�ﶵ: "); scanf("%d", &sel); fflush(stdin);

        system("cls");

        if(sel == 1){
            if(stackSize == 0){
                printf("�|���إ߰��|�Ŷ� �п�J���|���Ŷ��j�p: ");
                scanf("%d", &stackSize); fflush(stdin);

                stackSpace = (int *)malloc(sizeof(int) * stackSize);
                system("cls");
            }

            if(!intisFull(top, stackSize)){
                int value = 0;
                printf("��etop�Ȭ�:%d\t�Ѿl�Ŷ�:%d\n", top + 1, stackSize - (top + 1));
                printf("�п�J�ݭn���|����: ");
                scanf("%d", &value); fflush(stdin);

                push(stackSpace, &top, value);  // push(�}�C, ���ݼ���, �|�J����)
            }
        }
        else if(sel == 2){
            if(!isEmpty(top)){
                printf("�u�X�F: %d\n", pop(stackSpace, &top));
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
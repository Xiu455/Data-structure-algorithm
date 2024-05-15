#include <stdio.h>
#include <stdlib.h>
#include "LinkFunc.h"

void optionList();

int selector();     // 選擇器
int create();       // 建立
int insert();       // 插入
int delete();       // 刪除

int main()
{
    Node *first = NULL;

    int quitFlag = 0,
        options = 0;

    while(quitFlag == 0){
        system("cls");

        optionList();

        printf("請輸入要進行的操作選項: "); 
        if(scanf("%d", &options) == 1){
            fflush(stdin);
            selector(options, &quitFlag, &first);
        }
        else{
            fflush(stdin);
            printf("輸入格式錯誤 請重新輸入\n");
            system("pause");
        }
    }

    return 0;
}

void optionList()   //選項清單
{
    printf("1. 建立鏈表\n");
    printf("2. 顯示鏈表\n");
    printf("3. 插入節點\n");
    printf("4. 刪除節點\n");
    printf("5. 改變某節點的資料\n");
    printf("6. 刪除列表\n");
    printf("7. 退出\n\n");
}

int selector(int options, int *quitFlag, Node **first)    //選項選擇器
{

    Node *firstTmp = *first;

    if(options == 7){
        *quitFlag = 1;
        return 0;
    }

    system("cls");

    switch(options){
        case 1:{    //建立鏈表
            create(&firstTmp);
            *first = firstTmp;
            break;
        }

        case 2:{    //顯示鏈表
            printLinkdeList(firstTmp);
            system("pause");
            break;
        }

        case 3:{    //插入節點
            insert(firstTmp);
            system("pause");
            break;
        }

        case 4:{    //刪除節點
            delete(&firstTmp);
            *first = firstTmp;
            system("pause");
            break;
        }

        case 5:{
            printf("(尚未建構)\n");
            system("pause");
            break;
        }

        default:{
            printf("無此選項請重新輸入\n");
            system("pause");
            break;
        }
    }

}

int create(Node **first)    //建立
{
    Node *previous;
    Node *firstTmp = *first;
    int nodeNum = 0 ,inNum;

    if(firstTmp != NULL){      //以建立列表
        printf("已建立鏈表無法再次建立\n");
        system("pause");
        return 0;
    }

    printf("請輸入鏈表節點數: ");
    scanf("%d", &nodeNum);

    system("cls");

    for(int i = 0; i < nodeNum; i++){
        printf("%d號節點的資料為: ", i + 1);
        scanf("%d", &inNum);
        createLinkdeList(&firstTmp, &previous, &previous->next, inNum);
    }

    *first = firstTmp;

    system("pause");
}

int insert(Node *first) //插入
{
    int num = 0 ,insNum = 0;
    Node *current, *previous;

    system("cls");

    if(first == NULL){
        printf("尚未建立節點無法插入\n");
        return 0;
    }

    printf("要將節點插入哪個數值後面: ");
    scanf("%d", &num);
    if(searchNode(num, first, &current, &previous) == 1){
        printf("請輸入要插入的值: ");
        scanf("%d", &insNum);
        insertNode(insNum, current);
        printf("已插入節點");
    }

}

int delete(Node **first)    //刪除
{
    int deNum = 0;
    Node *firstTpm = *first;
    Node *current, *previous;

    system("cls");

    if(firstTpm == NULL)
    {
        printf("尚未建立節點無法刪除\n");
        return 0;
    }

    printf("請輸入要刪除的數值: ");
    scanf("%d", &deNum);
    if(searchNode(deNum, firstTpm, &current, &previous) == 1){
        deleteNode(&firstTpm, current, previous);
    }

    *first = firstTpm;
}
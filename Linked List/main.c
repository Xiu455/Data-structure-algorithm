#include <stdio.h>
#include <stdlib.h>
#include "LinkFunc.h"

void optionList();

int selector();     // ��ܾ�
int create();       // �إ�
int insert();       // ���J
int delete();       // �R��

int main()
{
    Node *first = NULL;

    int quitFlag = 0,
        options = 0;

    while(quitFlag == 0){
        system("cls");

        optionList();

        printf("�п�J�n�i�檺�ާ@�ﶵ: "); 
        if(scanf("%d", &options) == 1){
            fflush(stdin);
            selector(options, &quitFlag, &first);
        }
        else{
            fflush(stdin);
            printf("��J�榡���~ �Э��s��J\n");
            system("pause");
        }
    }

    return 0;
}

void optionList()   //�ﶵ�M��
{
    printf("1. �إ����\n");
    printf("2. ������\n");
    printf("3. ���J�`�I\n");
    printf("4. �R���`�I\n");
    printf("5. ���ܬY�`�I�����\n");
    printf("6. �R���C��\n");
    printf("7. �h�X\n\n");
}

int selector(int options, int *quitFlag, Node **first)    //�ﶵ��ܾ�
{

    Node *firstTmp = *first;

    if(options == 7){
        *quitFlag = 1;
        return 0;
    }

    system("cls");

    switch(options){
        case 1:{    //�إ����
            create(&firstTmp);
            *first = firstTmp;
            break;
        }

        case 2:{    //������
            printLinkdeList(firstTmp);
            system("pause");
            break;
        }

        case 3:{    //���J�`�I
            insert(firstTmp);
            system("pause");
            break;
        }

        case 4:{    //�R���`�I
            delete(&firstTmp);
            *first = firstTmp;
            system("pause");
            break;
        }

        case 5:{
            printf("(�|���غc)\n");
            system("pause");
            break;
        }

        default:{
            printf("�L���ﶵ�Э��s��J\n");
            system("pause");
            break;
        }
    }

}

int create(Node **first)    //�إ�
{
    Node *previous;
    Node *firstTmp = *first;
    int nodeNum = 0 ,inNum;

    if(firstTmp != NULL){      //�H�إߦC��
        printf("�w�إ����L�k�A���إ�\n");
        system("pause");
        return 0;
    }

    printf("�п�J���`�I��: ");
    scanf("%d", &nodeNum);

    system("cls");

    for(int i = 0; i < nodeNum; i++){
        printf("%d���`�I����Ƭ�: ", i + 1);
        scanf("%d", &inNum);
        createLinkdeList(&firstTmp, &previous, &previous->next, inNum);
    }

    *first = firstTmp;

    system("pause");
}

int insert(Node *first) //���J
{
    int num = 0 ,insNum = 0;
    Node *current, *previous;

    system("cls");

    if(first == NULL){
        printf("�|���إ߸`�I�L�k���J\n");
        return 0;
    }

    printf("�n�N�`�I���J���Ӽƭȫ᭱: ");
    scanf("%d", &num);
    if(searchNode(num, first, &current, &previous) == 1){
        printf("�п�J�n���J����: ");
        scanf("%d", &insNum);
        insertNode(insNum, current);
        printf("�w���J�`�I");
    }

}

int delete(Node **first)    //�R��
{
    int deNum = 0;
    Node *firstTpm = *first;
    Node *current, *previous;

    system("cls");

    if(firstTpm == NULL)
    {
        printf("�|���إ߸`�I�L�k�R��\n");
        return 0;
    }

    printf("�п�J�n�R�����ƭ�: ");
    scanf("%d", &deNum);
    if(searchNode(deNum, firstTpm, &current, &previous) == 1){
        deleteNode(&firstTpm, current, previous);
    }

    *first = firstTpm;
}
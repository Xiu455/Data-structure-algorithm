typedef struct node{
    int data;
    struct node *next;
} Node;

// 建立鏈表
void createLinkdeList(Node **first, Node **previous, Node **previousNext, int inNum)
{
    Node *firstTmp = *first;
    Node *current = (Node *)malloc(sizeof(Node));

    current->data = inNum;

    if(firstTmp == NULL){
        *first = current;
    }
    else{
        *previousNext = current;
    }

    current->next = NULL;
    *previous = current;
}

// 列印鏈表
void printLinkdeList(Node *first)
{
    Node *node = first;

    if(node == NULL){
        printf("無鏈表 無法顯示\n");
    }

    while (node != NULL){
        printf("當前節點的地址: %p\t", node);
        printf("當前節點的資料: %d\t", node->data);
        printf("指向的地址: %p\n", node->next);
        node = node->next;
    }
}

// 搜尋節點
int searchNode(int num, Node *first, Node **current, Node **previous)
{
    Node *node = first;
    Node *init;

    init->data = 0;
    init->next = NULL;
    *previous = init;

    while(node != NULL){
        if(node->data == num){
            *current = node;
            return 1;
        }
        else{
            *previous = node;
            node = node->next;
        }
    }

    printf("未搜尋到此數值 無法執行\n");
    return 0;
}

// 插入節點
void insertNode(int insNum, Node *current)
{
    Node *newnode;

    newnode = (Node *)malloc(sizeof(Node));

    newnode->data = insNum;
    newnode->next = current->next;
    current->next = newnode;
}

// 刪除節點
void deleteNode(Node **first, Node *current, Node *previous)
{
    Node *firstTpm = *first;

    if(current == firstTpm){
        firstTpm = firstTpm->next;
    }
    else{
        previous->next = current->next;
    }

    free(current);
    *first = firstTpm;
}
typedef struct node{
    int data;
    struct node *next;
} Node;

// �إ����
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

// �C�L���
void printLinkdeList(Node *first)
{
    Node *node = first;

    if(node == NULL){
        printf("�L��� �L�k���\n");
    }

    while (node != NULL){
        printf("��e�`�I���a�}: %p\t", node);
        printf("��e�`�I�����: %d\t", node->data);
        printf("���V���a�}: %p\n", node->next);
        node = node->next;
    }
}

// �j�M�`�I
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

    printf("���j�M�즹�ƭ� �L�k����\n");
    return 0;
}

// ���J�`�I
void insertNode(int insNum, Node *current)
{
    Node *newnode;

    newnode = (Node *)malloc(sizeof(Node));

    newnode->data = insNum;
    newnode->next = current->next;
    current->next = newnode;
}

// �R���`�I
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
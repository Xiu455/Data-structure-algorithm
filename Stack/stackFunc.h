// �d�ݪŶ��O�_����
int intisFull(int top, int stackSize){
    (top + 1 == stackSize)? printf("�Ŷ��w�� �L�k���|\n") : 0;
    return (top + 1 == stackSize);
}

// �d�ݪŶ��O�_����
int isEmpty(int top){
    (top == -1)? printf("���|�Ŷ����L���\n") : 0;
    return (top == -1);
}

// �|�J
void push(int *stackSpace, int *top, int value){
    *top += 1;
    stackSpace[*top] = value;
}

// �u�X
int pop(int *stackSpace, int *top){
    *top -= 1;
    return stackSpace[*top + 1];
}
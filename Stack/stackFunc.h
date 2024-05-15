// 查看空間是否為滿
int intisFull(int top, int stackSize){
    (top + 1 == stackSize)? printf("空間已滿 無法堆疊\n") : 0;
    return (top + 1 == stackSize);
}

// 查看空間是否為空
int isEmpty(int top){
    (top == -1)? printf("堆疊空間中無資料\n") : 0;
    return (top == -1);
}

// 疊入
void push(int *stackSpace, int *top, int value){
    *top += 1;
    stackSpace[*top] = value;
}

// 彈出
int pop(int *stackSpace, int *top){
    *top -= 1;
    return stackSpace[*top + 1];
}
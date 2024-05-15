#ifndef FUNC_H
#define FUNC_H

#include <stdlib.h>

// ���j�k
int FibRec(int n){
    return (n <= 1)? n : FibRec(n - 1) + FibRec(n - 2);
}

// �}�C�k
int FibArr(int n){
    if(n <= 2){
        return 1;
    }
    
    // ��J�ѼƦh�j �N�ӽ� "�Ѽ� + 1" ���}�C�Ŷ�
    int *tmpArr = (int *)malloc(sizeof(int) * (n + 1));

    tmpArr[0] = 0; tmpArr[1] = 1;

    for(int i = 2; i <= n; i++){
        tmpArr[i] = tmpArr[i - 1] + tmpArr[i - 2];
    }

    int sum = tmpArr[n];
    free(tmpArr);

    return sum;
}

#endif
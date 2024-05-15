#ifndef FUNC_H
#define FUNC_H

#include <stdlib.h>

// 患癹猭
int FibRec(int n){
    return (n <= 1)? n : FibRec(n - 1) + FibRec(n - 2);
}

// 皚猭
int FibArr(int n){
    if(n <= 2){
        return 1;
    }
    
    // 块把计 碞ビ叫 "把计 + 1" 皚丁
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
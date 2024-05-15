#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *dynArr;                                // 用來管理動態記憶體的指標

    int arrLen = 10;                            // 指定空間大小

    
    dynArr = malloc( arrLen * sizeof(int) );    // 取得記憶體空間

    if( dynArr == NULL ) {                      // 無法取得記憶體空間
        fprintf(stderr, "Error: unable to allocate required memory\n");
        return 1;
    }

    // 使用動態取得的記憶體空間
    int i;
    for (i = 0; i < arrLen; ++i) {
        dynArr[i] = i;
        printf("%d ", dynArr[i]);
    }
    
    free(dynArr);                               // 釋放記憶體空間

    return 0;
}
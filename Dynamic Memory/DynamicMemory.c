#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *dynArr;                                // �ΨӺ޲z�ʺA�O���骺����

    int arrLen = 10;                            // ���w�Ŷ��j�p

    
    dynArr = malloc( arrLen * sizeof(int) );    // ���o�O����Ŷ�

    if( dynArr == NULL ) {                      // �L�k���o�O����Ŷ�
        fprintf(stderr, "Error: unable to allocate required memory\n");
        return 1;
    }

    // �ϥΰʺA���o���O����Ŷ�
    int i;
    for (i = 0; i < arrLen; ++i) {
        dynArr[i] = i;
        printf("%d ", dynArr[i]);
    }
    
    free(dynArr);                               // ����O����Ŷ�

    return 0;
}
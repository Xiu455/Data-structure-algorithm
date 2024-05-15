#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;

    while(scanf("%d", &n) == 1){
        int *arr = (int *)malloc(sizeof(int) * n);

        for(int i = 0; i < n; i++){
            arr[i] = i + 10;
        }

        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }

        printf("\n");

        free(arr);
    }

    return 0;
}
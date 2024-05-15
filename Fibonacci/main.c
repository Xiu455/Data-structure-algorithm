#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

int main()
{
    int n1 = 3, n2 = 3;

    printf("%d\n", FibRec(n1));
    printf("%d\n", FibArr(n2));

    return 0;
}
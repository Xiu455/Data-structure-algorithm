#include <stdio.h>
#include <stdlib.h>

#define N 3

//void Preorder();  //«e§Ç
void Inorder();     //¤¤§Ç
//void Postorder(); //«á§Ç

int main()
{
    int arrNum[N] = {1,2,3};

    Inorder(arrNum, N/2);

    // system("pause");
    return 0;
}

void Inorder(int arrNum[], int n)
{
    if(n >= 0 && n < N){
        Inorder(arrNum, n + 1);
        printf("\n(%d)", arrNum[n]);
        Inorder(arrNum, n - 1);
    }
}
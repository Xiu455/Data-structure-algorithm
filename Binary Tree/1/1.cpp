#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *right;
	struct node *left;
} node;

/*void print(node *root);
void find(node *root,int value);*/

node *new1(node *root, int value)
{
	node *newa, *root1 = root;
	newa = (node *)malloc(sizeof(node));
	newa->data = value;
	newa->left = NULL;
	newa->right = NULL;

	while (1)
	{
		if (root->data > value)
		{
			if (root->left == NULL)
			{
				root->left = newa;
				return root1;
			}
			root = root->left;
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = newa;
				return root1;
			}
			root = root->right;
		}
	}
}
void print(node *root)
{
	if(root)
	{
		print(root->left);
		printf("(%d)  ", root->data);
		print(root->right);
	}
}

int find(node *root, int value)
{
	node *root1 = root;

	while(root1 != NULL && root1->data <= value){
		if(root1->data == value){
			printf("數值存在\n");
			return 0;
		}
		root1 = root1->right;
	}

	while(root1 != NULL && root1->data >= value){
		if(root1->data == value){
			printf("數值存在\n");
			return 0;
		}
		root1 = root1->left;
	}

	printf("數值不存在\n");
	return 0;
}

int main()
{
	int input, value;
	node *root = NULL, *root1;
	printf("EXIT=0, NEW=1, SEARCH=2, PRINTF=3, ENTER : ");
	scanf("%d", &input);

	do
	{
		if (input == 0)
			break;

		if (input == 1)
		{
			system("cls");
			printf("輸入要新增的元素: \n");
			scanf("%d", &value);
			if (root == NULL)
			{
				root = (node *)malloc(sizeof(node));
				root->data = value;
				root->left = NULL;
				root->right = NULL;
			}
			else
			{
				root1 = new1(root, value);
				root = root1;
			}
		}
		else if (input == 2)
		{
			if (root == NULL)
				printf("\nNO ELEMENT");
			else
			{
				system("cls");
				root1 = root;
				print(root);
				printf("\n");
				root = root1;
				system("pause");
			}
		}
		else if (input == 3)
		{
			system("cls");
			printf("輸入要尋找的元素: \n");
			scanf("%d", &value);
			root1 = root;
			find(root, value);
			printf("\n");
			root = root1;
			system("pause");
		}
		else
			printf("請再輸入一次\n");

		system("cls");
		printf("EXIT=0, NEW=1, SEARCH=2, PRINTF=3, ENTER : ");
		scanf("%d", &input);
	} while (1);
	return 0;
}
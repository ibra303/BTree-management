#include "TreeHeader.h";
//Main
int main()
{
	BTT OurTree = NULL;
	BTT node = NULL;
	int Func, key;
	printf("Please enter : 1-Insert Key / 2-Print Tree / 3-Chek Tree High / 4-Print Max Key / 5 -Serach For a Key / 6-Print The Smallest K Keys :\n");
	scanf("%d", &Func);
	while (Func != 0)
	{
		if (Func >=0 && Func <=6) 
		{
			if (Func == 1)
			{
				printf("What key you want to insert :");
				scanf("%d", &key);
				OurTree = MakeTreeInt(key, OurTree);
			}
			if (Func == 2)
			{
				printf("Our Tree elements :\n");
				printInorder(OurTree);
				printf("\n");
			}
			if (Func == 3)
			{
				printf("The height of your tree is %d\n", TreeHight(OurTree));
			}
			if (Func == 4)
			{
				node = MaxNum(OurTree);
				if (node)
				{
					printf("The max number in your tree is %d\n", node->key);
				}
				node = NULL;
			}
			if (Func == 5)
			{
				printf("Please enter the key you want to search:");
				scanf("%d", &key);
				if (findElement(OurTree, key) == 1)
					printf("Yes, thekey is in the tree\n");
				if (findElement(OurTree, key) == 0)
					printf("No, there is no key like that\n");
			}
			if (Func == 6)
			{
				printf("Please enter k: ");
				scanf("%d", &key);
				if (key <= countNode(OurTree))
				{
					PrintksmallestElement(OurTree, key);
					printf("\n\n");
				}
				else printf("there is no %d nodes in the tree\n\n", key);
			}
		}
		else
		{
			printf("you entered unvalid number, try again\n\n");
		}
		printf("Please enter : 0-Exit Program / 1-Insert Key / 2-Print Tree / 3-Chek Tree High / 4-Print Max Key / 5 -Serach For a Key / 6-Print The Smallest K Keys :\n");
		scanf("%d", &Func);
	}
	free(OurTree);
	free(node);
	return 0;
}
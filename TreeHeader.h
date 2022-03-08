#ifndef _TreeHeader
#define _TreeHeader
#include<stdio.h>
#include<stdlib.h>
#include <conio.h> 
#define _CRT_SECURE_NO_WARNINGS
#define Max(a,b) ((a) > (b)? (a): (b))
//our tree struct 
struct BinTree
{
	int key;
	struct BinTree* left;
	struct BinTree* right;
}typedef BT, *BTT;
//
int TreeHight(BTT tree);
BTT MakeTreeInt(int data, BTT p);
void printInorder(BTT tree);
BTT MaxNum(BTT tree);
int findElement(BTT root, int value);
int countNode(BTT root);
void PrintksmallestElement(BTT root, int k);
void ksmallestElement(BTT root, int k, int* count);
#endif

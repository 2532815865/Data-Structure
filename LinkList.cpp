//不带头结点的单链表
#include <cstddef>               
typedef struct LNode{            //定义单链表结点类型
	int* data;                   //每个节点存放一个数据元素
	struct LNode *next;          //指针指向下一个节点
}LNode,*LinkList;
//初始化一个空的单链表
bool InitList(LinkList &L) {
	L = NULL;                    //空表，暂时还没有任何结点、
	return true;
}
//判断单链表是否为空
bool Empty(LinkList L) {
	if (L == NULL)               //判断头指针是否为空
		return true;
	else
		return false;
}
void test() {
	LinkList L;                          //声明一个指向单链表的指针
	InitList(L);                         //初始化一个空表
	//其他操作...
}
//带头结点的单链表
#include <cstddef>   
#include<stdlib.h>
typedef struct LNode {            //定义单链表结点类型
	int* data;                    //每个节点存放一个数据元素
	struct LNode* next;           //指针指向下一个节点
}LNode, * LinkList;
//初始化一个单链表(带头结点)
bool InitList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));   //分配一个头结点(头结点不存储数据)
	if (L == NULL)
		return false;                    //内存不足分配失败
	L->next = NULL;                      //头结点之后暂时还没有节点
	return true;
}
//判断单链表是否为空(带头结点)
bool Empty(LinkList L) {
	if (L->next== NULL)                  //判断头结点是否为空  
		return true;
	else
		return false;
}
void test() {
	LinkList L;                          //声明一个指向单链表的指针
	InitList(L);                         //初始化一个空表
	//其他操作...
}

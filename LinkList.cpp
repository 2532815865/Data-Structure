//����ͷ���ĵ�����
#include <cstddef>               
typedef struct LNode{            //���嵥����������
	int* data;                   //ÿ���ڵ���һ������Ԫ��
	struct LNode *next;          //ָ��ָ����һ���ڵ�
}LNode,*LinkList;
//��ʼ��һ���յĵ�����
bool InitList(LinkList &L) {
	L = NULL;                    //�ձ���ʱ��û���κν�㡢
	return true;
}
//�жϵ������Ƿ�Ϊ��
bool Empty(LinkList L) {
	if (L == NULL)               //�ж�ͷָ���Ƿ�Ϊ��
		return true;
	else
		return false;
}
void test() {
	LinkList L;                          //����һ��ָ�������ָ��
	InitList(L);                         //��ʼ��һ���ձ�
	//��������...
}
//��ͷ���ĵ�����
#include <cstddef>   
#include<stdlib.h>
typedef struct LNode {            //���嵥����������
	int* data;                    //ÿ���ڵ���һ������Ԫ��
	struct LNode* next;           //ָ��ָ����һ���ڵ�
}LNode, * LinkList;
//��ʼ��һ��������(��ͷ���)
bool InitList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));   //����һ��ͷ���(ͷ��㲻�洢����)
	if (L == NULL)
		return false;                    //�ڴ治�����ʧ��
	L->next = NULL;                      //ͷ���֮����ʱ��û�нڵ�
	return true;
}
//�жϵ������Ƿ�Ϊ��(��ͷ���)
bool Empty(LinkList L) {
	if (L->next== NULL)                  //�ж�ͷ����Ƿ�Ϊ��  
		return true;
	else
		return false;
}
void test() {
	LinkList L;                          //����һ��ָ�������ָ��
	InitList(L);                         //��ʼ��һ���ձ�
	//��������...
}

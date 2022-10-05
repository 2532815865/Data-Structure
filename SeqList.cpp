//˳����ʵ�֡�����̬����
/*
#include <stdio.h>
#define MaxSize 10   //������󳤶�
typedef struct {
	int data[MaxSize];   //�þ�̬�ġ����顱�������Ԫ��
	int length;          //˳���ĵ�ǰ����
}SeqList;                 //˳�������Ͷ���
//��������������ʼ��һ��˳���
void InitList(SeqList &L) {
	for (int i = 0; i < L.MaxSize; i++)
		L.data[i] = 0;   //�����е�����Ԫ������ΪĬ�ϳ�ʼֵ
	L.length = 0;          //˳����ʼ����Ϊ0
}
 int main() {
	SeqList L;              //����һ��˳���
	InitList(L);           //��ʼ��˳���
	//...
	return 0;
}*/
 //˳����ʵ�֡�����̬����
 #include<stdio.h>
 #include <stdlib.h>
 #define InitSize 10   //Ĭ�ϵ���󳤶�
 typedef struct {
	 int* data;        //ָʾ��̬���������ָ��
	 int MaxSize;      //˳�����������
	 int length;       //˳���ĵ�ǰ����
 }SeqList;
 //��ʼ����̬����
 void InitList(SeqList& L) {
	 //��malloc��������һƬ�����Ĵ洢�ռ�
	 L.data = (int*)malloc(sizeof(int) * InitSize);
	 L.length = 0;
	 L.MaxSize = InitSize;
 }
 //���Ӷ�̬����ĳ���
 void IncreaseSize(SeqList& L, int len) {
	 int* p = L.data;
	 L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));
	 for (int i = 0; i < L.length; i++) {
		 L.data[i] = p[i];     //�����ݸ��Ƶ�������
	 }
	 L.MaxSize += len;         //˳�����󳤶����� len
	 free(p);                  //�ͷ�ԭ�����ڴ�ռ�
 }
//�õ��㷨��Ӧ�þ��С���׳�ԡ����ܹ������쳣��������ҷ�����ʹ����
//����˳���Ĳ������
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length+1)            //�ж�i�ķ�Χ�Ƿ���Ч
		return false;                      
	if (L.length >= L.MaxSize)              //��ǰ�洢�ռ����������ܲ���
		return false;                      
	for (int j = L.length; j >= i; j--)   //����i��Ԫ�ؼ��Ժ��Ԫ�غ���  
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;                    //��λ��i������Ԫ��e
	L.length++;                           //����1
	return true;
}
//����˳����ɾ������
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)               //�ж�i�ķ�Χ���Ƿ���Ч
		return false;                    
	e = L.data[i-1];                     //��ɾ����Ԫ�ظ���e
	for (int j = i; j < L.length; j++)   //��i��λ���Ժ��Ԫ��ǰ��
		L.data[j-1] = L.data[j];
	L.length--;                          //���Ա��ȼ�1
	return true;
}
//����˳���İ�λ����
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return false;
	return (L.data[i-1]);
}
//����˳���İ�ֵ����
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;           //����Ԫ�ص�λ��
		return 0;
}
//����һ��������
 int main() {
	 SeqList L;     //����һ��˳���
	 InitList(L);   //��ʼ��˳���
	 //��������...
	 return 0;
 }


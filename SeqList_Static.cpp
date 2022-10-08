//˳����ʵ�֡�����̬����
#include <stdio.h>
#define MaxSize 10        //������󳤶�
typedef struct {
	int data[MaxSize];    //�þ�̬�ġ����顱�������Ԫ��
	int length;           //˳���ĵ�ǰ����
}SeqList;                 //˳�������Ͷ���
//��������������ʼ��һ��˳���
void InitList(SeqList &L) {
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;     //�����е�����Ԫ������ΪĬ�ϳ�ʼֵ
	L.length = 0;          //˳����ʼ����Ϊ0
}
//����˳���Ĳ������
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)            //�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	if (L.length >= MaxSize)              //��ǰ�洢�ռ����������ܲ���
		return false;
	for (int j = L.length; j >= i; j--)   //����i��Ԫ�ؼ��Ժ��Ԫ�غ���  
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;                    //��λ��i������Ԫ��e
	L.length++;                           //����1
	return true;
}
//����˳����ɾ������
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)                 //�ж�i�ķ�Χ���Ƿ���Ч
		return false;
	e = L.data[i - 1];                     //��ɾ����Ԫ�ظ���e
	for (int j = i; j < L.length; j++)     //��i��λ���Ժ��Ԫ��ǰ��
		L.data[j - 1] = L.data[j];
	L.length--;                            //���Ա��ȼ�1
	return true;
}
//����˳���İ�λ����
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return false;
	return (L.data[i - 1]);
}
//����˳���İ�ֵ����
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;           //����Ԫ�ص�λ��
	return 11;                      //����һ���쳣ֵ�����ֲ���ʧ��(δ��ѯ����ֵͬ)
}
//�Զ������
void test() {
	SeqList L;              //����һ��˳���
	InitList(L);            //��ʼ��˳���
	int i, e, m, n;
	for (i = 1; i <= MaxSize; i++)                               //���θ�������µ�ֵ
		if (ListInsert(L, i, i))
			printf("data[%d] = %d\n", i - 1, L.data[i - 1]);     //��ӡ����Ԫ�أ�ע��λ��������±������
	ListDelete(L, 5, e);                                         //ɾ������λ��Ϊ5��Ԫ��
	m = GetElem(L, 5);                                           //����λ��Ϊ5��Ԫ�ص�ֵ
	n = LocateElem(L, 6);                                        //����Ԫ�ص�ֵΪ6��λ��
	printf("ɾ���󷵻�e��ֵΪ��e = %d\n", e);
	printf("λ��Ϊ5��Ԫ�ص�ֵΪ��m = %d\n", m);
	printf("Ԫ��ֵΪ6��λ��Ϊ��n = %d\n", n);
}
 int main() {
	 test();
	return 0;
}

//˳�����ʵ�֡�����̬����
 #include<stdio.h>
 #include <stdlib.h>
 #define InitSize 10   //Ĭ�ϵ���󳤶�
 typedef struct {
	 int* data;        //ָʾ��̬���������ָ��
	 int MaxSize;      //˳������������
	 int length;       //˳����ĵ�ǰ����
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
//����˳����Ĳ������
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length+1)                //�ж�i�ķ�Χ�Ƿ���Ч
		return false;                      
	if (L.length >= L.MaxSize)              //��ǰ�洢�ռ����������ܲ���
		return false;                      
	for (int j = L.length; j >= i; j--)     //����i��Ԫ�ؼ��Ժ��Ԫ�غ���  
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;                        //��λ��i������Ԫ��e
	L.length++;                             //������1
	return true;
}
//����˳�����ɾ������
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)                  //�ж�i�ķ�Χ���Ƿ���Ч
		return false;                    
	e = L.data[i-1];                        //��ɾ����Ԫ�ظ���e
	for (int j = i; j < L.length; j++)      //��i��λ���Ժ��Ԫ��ǰ��
		L.data[j-1] = L.data[j];
	L.length--;                             //���Ա����ȼ�1
	return true;
}
//����˳����İ�λ����
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return 0;
	return (L.data[i-1]);
}
//����˳����İ�ֵ����
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;                   //����Ԫ�ص�λ��
		return 0;
}
//����һ��������
 int main() {
	 SeqList L;     //����һ��˳���
	 InitList(L);   //��ʼ��˳���
	 //�Զ������
	 int i,m,n,e;
	 for (i = 1; i <= L.MaxSize; i++)                        
		 if (ListInsert(L, i, i))                            //���θ��������µ�ֵ
		printf("data[%d] = %d\n", i - 1, L.data[i - 1]);     //��ӡ����Ԫ�أ�ע��λ��������±������
	 IncreaseSize(L,5);                                      //��˳�����̬����5������
	 for (i = 0; i < L.MaxSize; i++)
		 printf("data[%d] = %d\n",i,L.data[i]);              //��ӡ�������Ӻ����Ԫ�ص�ֵ
	 for (i = 11; i <=L.MaxSize; i++)
	 if(ListInsert(L,i,0))                                   //�����ӵı������µ�ֵ
		 printf("data[%d] = %d\n", i - 1, L.data[i - 1]);    //��ӡ�������ݺ����Ԫ��
	 ListDelete(L, 5, e);                                    //ɾ������λ��Ϊ5��Ԫ��
	 m = GetElem(L, 5);                                      //����λ��Ϊ5��Ԫ�ص�ֵ
	 n = LocateElem(L, 6);                                   //����Ԫ�ص�ֵΪ6��λ��
	 printf("ɾ���󷵻�e��ֵΪ��e = %d\n", e);
	 printf("λ��Ϊ5��Ԫ�ص�ֵΪ��m = %d\n", m);
	 printf("Ԫ��ֵΪ6��λ��Ϊ��n = %d\n", n);
	 return 0;
 }
 
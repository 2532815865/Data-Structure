//顺序表的实现——动态分配
//警告	C6386	 写入 "L.data" 时缓冲区溢出。		27
 #include <stdio.h>
 #include <stdlib.h>
 #define InitSize 10   //默认的最大长度
 typedef int ElemType;
 typedef struct {
	 ElemType* data;        //指示动态分配数组的指针
	 int length;       //顺序表的当前长度
	 int MaxSize;      //顺序表的最大容量
 }SeqList;
 //初始化动态数组
 void InitList(SeqList &L) {
	 //用malloc函数申请一片连续的存储空间
	 L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	 if (L.data == nullptr)
		 printf("内存分配失败！\n");
	 L.length = 0;
	 L.MaxSize = InitSize;
 }
 //增加动态数组的长度
 void IncreaseSize(SeqList &L, int len) {
	 ElemType* p = L.data;
	 L.data = (ElemType*)malloc(sizeof(ElemType)*(L.MaxSize + len));
	 if (L.data != nullptr){
	 for (int i = 0; i < L.length; i++)
		 L.data[i] = p[i];        //将数据复制到新区域    
	 }
	 L.MaxSize += len;            //顺序表最大长度增加 len
	 free(p);                     //释放原来的内存空间
 }
//好的算法，应该具有“健壮性”，能够处理异常情况，并且反馈给使用者
//定义顺序表的插入操作
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length+1)                //判断i的范围是否有效
		return false;                      
	if (L.length >= L.MaxSize)              //当前存储空间已满，不能插入
		return false;                      
	for (int j = L.length; j >= i; j--)     //将第i个元素及以后的元素后移  
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;                        //在位置i处放入元素e
	L.length++;                             //表长加1
	return true;
}
//定义顺序表的删除操作
bool ListDelete(SeqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length)                  //判断i的范围的是否有效
		return false;                    
	e = L.data[i-1];                        //将删除的元素赋给e
	for (int j = i; j < L.length; j++)      //将i个位置以后的元素前移
		L.data[j-1] = L.data[j];
	L.length--;                             //线性表长度减1
	return true;
}
//定义顺序表的按位查找
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return 0;
	return (L.data[i-1]);
}
//定义顺序表的按值查找
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;                   //返回元素的位序
		return 0;
}
//自定义操作
void test() {
	SeqList L;     //声明一个顺序表
	InitList(L);   //初始化顺序表
	int i, n;
	ElemType m, e;
	for (i = 1; i <= L.MaxSize; i++)
		if (ListInsert(L, i, i))                            //依次给表插入新的值
			printf("data[%d] = %d\n", i - 1, L.data[i - 1]);     //打印表中元素，注意位序和数组下标的区别
	IncreaseSize(L, 5);                                      //给顺序表动态增加5个长度
	for (i = 0; i < L.MaxSize; i++)
		printf("data[%d] = %d\n", i, L.data[i]);              //打印长度增加后表中元素的值
	for (i = 11; i <= L.MaxSize; i++)
		if (ListInsert(L, i, 0))                                   //给增加的表插入新的值
			printf("data[%d] = %d\n", i - 1, L.data[i - 1]);    //打印插入数据后表中元素
	ListDelete(L, 5, e);                                    //删除表中位序为5的元素
	m = GetElem(L, 5);                                      //查找位序为5的元素的值
	n = LocateElem(L, 6);                                   //查找元素的值为6的位序
	printf("删除后返回e的值为：e = %d\n", e);
	printf("位序为5的元素的值为：m = %d\n", m);
	printf("元素值为6的位序为：n = %d\n", n);
}
//定义一个主函数
 int main() {
	 test();
	 return 0;
 }

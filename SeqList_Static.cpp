//顺序表的实现——静态分配
#include <stdio.h>
#define MaxSize 10        //定义最大长度
typedef struct {
	int data[MaxSize];    //用静态的“数组”存放数据元素
	int length;           //顺序表的当前长度
}SeqList;                 //顺序表的类型定义
//基本操作——初始化一个顺序表
void InitList(SeqList &L) {
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;     //将所有的数据元素设置为默认初始值
	L.length = 0;          //顺序表初始长度为0
}
//定义顺序表的插入操作
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)            //判断i的范围是否有效
		return false;
	if (L.length >= MaxSize)              //当前存储空间已满，不能插入
		return false;
	for (int j = L.length; j >= i; j--)   //将第i个元素及以后的元素后移  
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;                    //在位置i处放入元素e
	L.length++;                           //表长加1
	return true;
}
//定义顺序表的删除操作
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)                 //判断i的范围的是否有效
		return false;
	e = L.data[i - 1];                     //将删除的元素赋给e
	for (int j = i; j < L.length; j++)     //将i个位置以后的元素前移
		L.data[j - 1] = L.data[j];
	L.length--;                            //线性表长度减1
	return true;
}
//定义顺序表的按位查找
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return false;
	return (L.data[i - 1]);
}
//定义顺序表的按值查找
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;           //返回元素的位序
	return 11;                      //返回一个异常值，区分查找失败(未查询到相同值)
}
//自定义操作
void test() {
	SeqList L;              //声明一个顺序表
	InitList(L);            //初始化顺序表
	int i, e, m, n;
	for (i = 1; i <= MaxSize; i++)                               //依次给表插入新的值
		if (ListInsert(L, i, i))
			printf("data[%d] = %d\n", i - 1, L.data[i - 1]);     //打印表中元素，注意位序和数组下标的区别
	ListDelete(L, 5, e);                                         //删除表中位序为5的元素
	m = GetElem(L, 5);                                           //查找位序为5的元素的值
	n = LocateElem(L, 6);                                        //查找元素的值为6的位序
	printf("删除后返回e的值为：e = %d\n", e);
	printf("位序为5的元素的值为：m = %d\n", m);
	printf("元素值为6的位序为：n = %d\n", n);
}
 int main() {
	 test();
	return 0;
}

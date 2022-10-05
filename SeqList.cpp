//顺序表的实现——静态分配
/*
#include <stdio.h>
#define MaxSize 10   //定义最大长度
typedef struct {
	int data[MaxSize];   //用静态的“数组”存放数据元素
	int length;          //顺序表的当前长度
}SeqList;                 //顺序表的类型定义
//基本操作——初始化一个顺序表
void InitList(SeqList &L) {
	for (int i = 0; i < L.MaxSize; i++)
		L.data[i] = 0;   //将所有的数据元素设置为默认初始值
	L.length = 0;          //顺序表初始长度为0
}
 int main() {
	SeqList L;              //声明一个顺序表
	InitList(L);           //初始化顺序表
	//...
	return 0;
}*/
 //顺序表的实现——动态分配
 #include<stdio.h>
 #include <stdlib.h>
 #define InitSize 10   //默认的最大长度
 typedef struct {
	 int* data;        //指示动态分配数组的指针
	 int MaxSize;      //顺序表的最大容量
	 int length;       //顺序表的当前长度
 }SeqList;
 //初始化动态数组
 void InitList(SeqList& L) {
	 //用malloc函数申请一片连续的存储空间
	 L.data = (int*)malloc(sizeof(int) * InitSize);
	 L.length = 0;
	 L.MaxSize = InitSize;
 }
 //增加动态数组的长度
 void IncreaseSize(SeqList& L, int len) {
	 int* p = L.data;
	 L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));
	 for (int i = 0; i < L.length; i++) {
		 L.data[i] = p[i];     //将数据复制到新区域
	 }
	 L.MaxSize += len;         //顺序表最大长度增加 len
	 free(p);                  //释放原来的内存空间
 }
//好的算法，应该具有“健壮性”，能够处理异常情况，并且反馈给使用者
//定义顺序表的插入操作
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length+1)            //判断i的范围是否有效
		return false;                      
	if (L.length >= L.MaxSize)              //当前存储空间已满，不能插入
		return false;                      
	for (int j = L.length; j >= i; j--)   //将第i个元素及以后的元素后移  
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;                    //在位置i处放入元素e
	L.length++;                           //表长加1
	return true;
}
//定义顺序表的删除操作
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)               //判断i的范围的是否有效
		return false;                    
	e = L.data[i-1];                     //将删除的元素赋给e
	for (int j = i; j < L.length; j++)   //将i个位置以后的元素前移
		L.data[j-1] = L.data[j];
	L.length--;                          //线性表长度减1
	return true;
}
//定义顺序表的按位查找
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return false;
	return (L.data[i-1]);
}
//定义顺序表的按值查找
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;           //返回元素的位序
		return 0;
}
//定义一个主函数
 int main() {
	 SeqList L;     //声明一个顺序表
	 InitList(L);   //初始化顺序表
	 //其他操作...
	 return 0;
 }


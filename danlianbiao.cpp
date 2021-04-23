//创建单链表
#include <stdio.h>
#include <iostream>
typedef int ElemType;	//自定义int类型element

//定义一个结构体 
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//声明函数 
int InitList(LinkList &L);
void CreateList_H(LinkList &L,int n );
void Traverse(LinkList L1);

int main()
{
	LinkList T;
	CreateList_H(T,3);
	Traverse(T);
	
	return 0;
}

//初始化单链表
int InitList(LinkList &L)
{
	L = new LNode;	//头指针指向新生成的头结点 
	L->next = NULL;	//头结点的指针域为空 
	return 0;
 } 
 
// 前插法创建单链表
void CreateList_H(LinkList &L,int n )
{
	L = new LNode;	//头指针指向新生成的头结点 
	L->next = NULL;	//头结点的指针域为空 
	for(int i = 0;i<n;++i)
	{
		LNode *p=new LNode;	//生成新结点*p 
		scanf("%d",p->data);
		p->next = L->next;
		L->next = p;
	}
}

//后插法创建单链表
void CreateList_R(LinkList &L,int n)
{
	L = new LNode;	//头指针指向新生成的头结点 
	L->next = NULL;	//头结点的指针域为空
	LinkList r = L;	//尾指针r指向头结点
	for(int i =0;i<n;++i)
	{
		LinkList p = new LNode;	//生成新结点 
		scanf("%d",p->data);
		p->next = NULL;	//将新结点*p插入尾结点*r之后 
		r->next = p;
		r=p; 	//r指向新的尾结点 
	 } 
	
	
 } 

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L,int i ,ElemType e)
{
	if(i<1)
		return false;
	LNode *p;	//创建一个新指针，指向当前扫描的结点 
	int j = 0;	//当前p指向的是第j个结点 
	p = L;	//L指向头结点，为第0个结点（不存数据） 
	while(p!= NULL && j<i-1)	//循环到第i-1个结点 
	{
		p = p->next;
		j++;
	}
	if(p==NULL)	//i值不合法
		return false;
	LNode *s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
 } 
 
//后插操作：在p结点之后插入元素e
bool InsertNextNode(LinkList *p,ElemType e)
{
	if(p==NULL)
		return false;
	LNode *s = new LNode;
	if(s==NULL)		//内存分配失败 
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
	
 } 
//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LinkList *p,ElemType e)
{
	if(p==NULL)
		return false;
	LNode *s = new LNode;
	if(s==NULL)
		return false;
	s->next = p->next;	//新结点s连接到p之后 
	p->next = s;
	s->data = p->data;	//将p中元素复制到s中 
	p->data = e;		//p中元素覆盖为 e 
	return true;
}
 
//打印链表
void Traverse(LinkList L1)
{
	while(L1){
		L1 = L1->next;
		printf("%d",L1->data);
	}
 } 

//按位序删除
bool ListDelete(LinkList &L,int i ,ElemType e)
{
	if(i<1)
		return false;
	LNode *p;	//创建一个新指针，指向当前扫描的结点 
	int j = 0;	//当前p指向的是第j个结点 
	p = L;	//L指向头结点，为第0个结点（不存数据） 
	while(p! = NULL && j<i-1)	//循环到第i-1个结点 
	{
		p = p->next;
		j++;
	}
	if(p==NULL)	//i值不合法
		return false;
	if(p->next==NULL);	//第i-1个结点之后已无其他结点 
		return false;
	LNode *q = p->next;		//令q指向被删除的结点
	e = q->data;
	p->next = q->next;	//将*q结点从链表中断去 
	free(q);	//释放结点的空间 
	return true;
	
 } 

//按位查找，返回第i个元素
LNode *GetElem(LinkList L, int i)
{
	if(i<0)
		return NULL;
	LNode *p;	//指针p指向当前扫描到的结点 
	int j = 0;	//当前p指向的是第几个结点 
	p = L;		//L指向头结点，头结点是第0个结点，不存数据
	while(p!=NULL && j<i)
	{
		p=p->next;
		j++;
	 } 
	 return p;
 } 
 
 //按值查找，找到数据域==e的结点 ！！！如果ElemType的struct类型时，判断数据域==e时要逐一判断 
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p = L->next;
	//从第1个结点开始查找数据域为e的结点
	while(p!=NULL && p->data!=e)
		p = p->next;
	return p;	//找到后返回该结点指针，否则返回NULL 
		
 } 

//求表长
int Length(LinkList L)
{
	int len = 0;	//统计表长
	LNode *p = L;
	while(p->next !=NULL)
	{
		p = p->next;
		len++;
	 } 
	return len;
 } 






 

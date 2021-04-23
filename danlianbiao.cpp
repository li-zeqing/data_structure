//����������
#include <stdio.h>
#include <iostream>
typedef int ElemType;	//�Զ���int����element

//����һ���ṹ�� 
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//�������� 
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

//��ʼ��������
int InitList(LinkList &L)
{
	L = new LNode;	//ͷָ��ָ�������ɵ�ͷ��� 
	L->next = NULL;	//ͷ����ָ����Ϊ�� 
	return 0;
 } 
 
// ǰ�巨����������
void CreateList_H(LinkList &L,int n )
{
	L = new LNode;	//ͷָ��ָ�������ɵ�ͷ��� 
	L->next = NULL;	//ͷ����ָ����Ϊ�� 
	for(int i = 0;i<n;++i)
	{
		LNode *p=new LNode;	//�����½��*p 
		scanf("%d",p->data);
		p->next = L->next;
		L->next = p;
	}
}

//��巨����������
void CreateList_R(LinkList &L,int n)
{
	L = new LNode;	//ͷָ��ָ�������ɵ�ͷ��� 
	L->next = NULL;	//ͷ����ָ����Ϊ��
	LinkList r = L;	//βָ��rָ��ͷ���
	for(int i =0;i<n;++i)
	{
		LinkList p = new LNode;	//�����½�� 
		scanf("%d",p->data);
		p->next = NULL;	//���½��*p����β���*r֮�� 
		r->next = p;
		r=p; 	//rָ���µ�β��� 
	 } 
	
	
 } 

//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool ListInsert(LinkList &L,int i ,ElemType e)
{
	if(i<1)
		return false;
	LNode *p;	//����һ����ָ�룬ָ��ǰɨ��Ľ�� 
	int j = 0;	//��ǰpָ����ǵ�j����� 
	p = L;	//Lָ��ͷ��㣬Ϊ��0����㣨�������ݣ� 
	while(p!= NULL && j<i-1)	//ѭ������i-1����� 
	{
		p = p->next;
		j++;
	}
	if(p==NULL)	//iֵ���Ϸ�
		return false;
	LNode *s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
 } 
 
//����������p���֮�����Ԫ��e
bool InsertNextNode(LinkList *p,ElemType e)
{
	if(p==NULL)
		return false;
	LNode *s = new LNode;
	if(s==NULL)		//�ڴ����ʧ�� 
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
	
 } 
//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LinkList *p,ElemType e)
{
	if(p==NULL)
		return false;
	LNode *s = new LNode;
	if(s==NULL)
		return false;
	s->next = p->next;	//�½��s���ӵ�p֮�� 
	p->next = s;
	s->data = p->data;	//��p��Ԫ�ظ��Ƶ�s�� 
	p->data = e;		//p��Ԫ�ظ���Ϊ e 
	return true;
}
 
//��ӡ����
void Traverse(LinkList L1)
{
	while(L1){
		L1 = L1->next;
		printf("%d",L1->data);
	}
 } 

//��λ��ɾ��
bool ListDelete(LinkList &L,int i ,ElemType e)
{
	if(i<1)
		return false;
	LNode *p;	//����һ����ָ�룬ָ��ǰɨ��Ľ�� 
	int j = 0;	//��ǰpָ����ǵ�j����� 
	p = L;	//Lָ��ͷ��㣬Ϊ��0����㣨�������ݣ� 
	while(p! = NULL && j<i-1)	//ѭ������i-1����� 
	{
		p = p->next;
		j++;
	}
	if(p==NULL)	//iֵ���Ϸ�
		return false;
	if(p->next==NULL);	//��i-1�����֮������������� 
		return false;
	LNode *q = p->next;		//��qָ��ɾ���Ľ��
	e = q->data;
	p->next = q->next;	//��*q���������ж�ȥ 
	free(q);	//�ͷŽ��Ŀռ� 
	return true;
	
 } 

//��λ���ң����ص�i��Ԫ��
LNode *GetElem(LinkList L, int i)
{
	if(i<0)
		return NULL;
	LNode *p;	//ָ��pָ��ǰɨ�赽�Ľ�� 
	int j = 0;	//��ǰpָ����ǵڼ������ 
	p = L;		//Lָ��ͷ��㣬ͷ����ǵ�0����㣬��������
	while(p!=NULL && j<i)
	{
		p=p->next;
		j++;
	 } 
	 return p;
 } 
 
 //��ֵ���ң��ҵ�������==e�Ľ�� ���������ElemType��struct����ʱ���ж�������==eʱҪ��һ�ж� 
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p = L->next;
	//�ӵ�1����㿪ʼ����������Ϊe�Ľ��
	while(p!=NULL && p->data!=e)
		p = p->next;
	return p;	//�ҵ��󷵻ظý��ָ�룬���򷵻�NULL 
		
 } 

//���
int Length(LinkList L)
{
	int len = 0;	//ͳ�Ʊ�
	LNode *p = L;
	while(p->next !=NULL)
	{
		p = p->next;
		len++;
	 } 
	return len;
 } 






 

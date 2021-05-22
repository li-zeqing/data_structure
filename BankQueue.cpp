/*
�����Ŷ�ϵͳ
�����¼�
    ÿ���¼�����occurTime��Type������occurTime����ͻ���������뿪���е�ʱ��
    Type��ʾ�ͻ���ĳһ���ڰ���ҵ����뿪����[1,2,3,...,n]
	��Type=0ʱ��ʾ�ͻ���������
������ʱ��˳����¼����ӡ�
*/

//ѭ������
#include <stdio.h>
#include <iostream>
using namespace std;
#define QElemType int

//���е���ʽ�洢�ṹ
typedef struct QNode{
	QElemType occurTime;
	QElemType Type;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//���ӵĳ�ʼ��
bool InitLinkQueue(LinkQueue &Q){
	Q.front = Q.rear = new QNode; //�����½����Ϊͷ��㣬ͷָ���βָ�붼ָ��ͷ���
	Q.front->next = NULL;
	return true;
}

//���ӵ����
bool EnLinkQueue(LinkQueue &Q,QElemType occurTime,QElemType Type){
	QueuePtr p = new QNode;		//Ϊ���Ԫ�ط����½�㣬����pָ��ý��
	p->occurTime = occurTime;
	p->Type = Type;
	
	QueuePtr TPtr,T;
	TPtr = Q.front;
	T = TPtr->next;
	while(T &&T->occurTime<occurTime){
		TPtr = TPtr->next;
		T = T->next;
	};
	
	p->next = T;
	TPtr->next = p;
	if(!T)
		Q.rear = TPtr->next;
	return true;
}

//���ӵĳ���
bool DeLinkQueue(LinkQueue &Q,QElemType &occurTime,QElemType &Type){
	//�����п�
	if(Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	occurTime = p->occurTime;
	Type = p->Type;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear=Q.front;		//���һ��Ԫ�ر�ɾ����βָ��ָ���ͷ���
	delete p;
	return true;
}
//ȡ��ͷԪ��
bool GetHead(LinkQueue Q){
	if(Q.front!=Q.rear){
		cout<<"occurTime:"<<Q.front->next->occurTime<<endl;
		cout<<"Type:"<<Q.front->next->Type<<endl;
		return true;
	}
	else return false;
}

//������ӡѭ������
bool QueueTraverse(LinkQueue Q){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear == Q.front) return false;
	QueuePtr p = Q.front->next;
	while(p){
		cout<<"occurTime:"<<p->occurTime<<"   ";
		cout<<"Type:"<<p->Type<<endl;
		p=p->next;
	};
	return 1;
}

int main(){
	//�������Ӳ���ʼ��
	LinkQueue Q;
	InitLinkQueue(Q);
	EnLinkQueue(Q,2,1);
	EnLinkQueue(Q,1,10);
	EnLinkQueue(Q,6,20);
	EnLinkQueue(Q,5,30);
	EnLinkQueue(Q,22,90);
	EnLinkQueue(Q,18,20);
	EnLinkQueue(Q,3,33);
	QElemType occurTime;
	QElemType Type;
	DeLinkQueue(Q,occurTime,Type);
	cout<<"ɾ����occurTime:"<<occurTime<<"  "<<"ɾ����Type:"<<Type<<endl;
	QueueTraverse(Q);
}

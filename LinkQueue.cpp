//ѭ������
#include <stdio.h>
#include <iostream>
using namespace std;
#define QElemType int

//���е���ʽ�洢�ṹ
typedef struct QNode{
	QElemType data;
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
bool EnLinkQueue(LinkQueue &Q,QElemType e){
	QueuePtr p = new QNode;		//Ϊ���Ԫ�ط����½�㣬����pָ��ý�� 
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true; 
}

//���ӵĳ���
bool DeLinkQueue(LinkQueue &Q,QElemType &e){
	//�����п�
	if(Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear=Q.front;		//���һ��Ԫ�ر�ɾ����βָ��ָ���ͷ���
	delete p;
	return true;  
} 
//ȡ��ͷԪ�� 
QElemType GetHead(LinkQueue Q){
	if(Q.front!=Q.rear)
		return Q.front->next->data;
}

int main(){
	//�������Ӳ���ʼ�� 
	LinkQueue Q;
	InitLinkQueue(Q);
	
}

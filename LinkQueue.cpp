//循环链队
#include <stdio.h>
#include <iostream>
using namespace std;
#define QElemType int

//队列的链式存储结构
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue; 

//链队的初始化
bool InitLinkQueue(LinkQueue &Q){
	Q.front = Q.rear = new QNode; //生成新结点作为头结点，头指针和尾指针都指向头结点 
	Q.front->next = NULL;
	return true;
} 

//链队的入队
bool EnLinkQueue(LinkQueue &Q,QElemType e){
	QueuePtr p = new QNode;		//为入队元素分配新结点，并用p指向该结点 
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true; 
}

//链队的出队
bool DeLinkQueue(LinkQueue &Q,QElemType &e){
	//链队判空
	if(Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear=Q.front;		//最后一个元素被删，队尾指针指向队头结点
	delete p;
	return true;  
} 
//取队头元素 
QElemType GetHead(LinkQueue Q){
	if(Q.front!=Q.rear)
		return Q.front->next->data;
}

int main(){
	//创建链队并初始化 
	LinkQueue Q;
	InitLinkQueue(Q);
	
}

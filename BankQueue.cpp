/*
银行排队系统
建立事件
    每个事件包括occurTime和Type，其中occurTime代表客户到达或者离开银行的时间
    Type表示客户从某一窗口办理业务后离开银行[1,2,3,...,n]
	当Type=0时表示客户到达银行
建立以时间顺序的事件链队。
*/

//循环链队
#include <stdio.h>
#include <iostream>
using namespace std;
#define QElemType int

//队列的链式存储结构
typedef struct QNode{
	QElemType occurTime;
	QElemType Type;
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
bool EnLinkQueue(LinkQueue &Q,QElemType occurTime,QElemType Type){
	QueuePtr p = new QNode;		//为入队元素分配新结点，并用p指向该结点
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

//链队的出队
bool DeLinkQueue(LinkQueue &Q,QElemType &occurTime,QElemType &Type){
	//链队判空
	if(Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	occurTime = p->occurTime;
	Type = p->Type;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear=Q.front;		//最后一个元素被删，队尾指针指向队头结点
	delete p;
	return true;
}
//取队头元素
bool GetHead(LinkQueue Q){
	if(Q.front!=Q.rear){
		cout<<"occurTime:"<<Q.front->next->occurTime<<endl;
		cout<<"Type:"<<Q.front->next->Type<<endl;
		return true;
	}
	else return false;
}

//遍历打印循环队列
bool QueueTraverse(LinkQueue Q){
	//判断队列是否为空
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
	//创建链队并初始化
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
	cout<<"删除的occurTime:"<<occurTime<<"  "<<"删除的Type:"<<Type<<endl;
	QueueTraverse(Q);
}

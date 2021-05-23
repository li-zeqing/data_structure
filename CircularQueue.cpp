//循环队列
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXQSIZE 100 
#define QElemType int
//循环队列结构
typedef  struct{
	QElemType *base;	//存储空间基地址
	int front;	//头指针 
	int rear; 	//尾指针 
}SqQueue;

//初始化循环队列
bool InitQueue(SqQueue &Q){
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
	
} 

//销毁循环队列
bool DestroyQueue(SqQueue &Q) {
	while(Q.rear != Q.front){
		Q.front = (Q.front+1)%MAXQSIZE;
	}
	delete Q.base;
}

//清空循环队列
bool ClearQueue(SqQueue &Q) {
	while(Q.rear != Q.front){
		Q.front = (Q.front+1)%MAXQSIZE;
	}
	
}

//判空循环队列
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//循环队列的长度
int QueueLength(SqQueue Q){
	
	return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
} 

//返回队头元素
QElemType GetHead(SqQueue Q){
	//判断队列是否为空
	if (Q.rear != Q.front) 
		return Q.base[Q.front];

}
//插入队尾元素
bool EnQueue(SqQueue &Q,QElemType e){
	//判断队列是否为满
	if((Q.rear+1)%MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return true;
}

//删除队头元素
bool DeQueue(SqQueue &Q,QElemType &e){
	//判断队列是否为空
	if (Q.rear == Q.front) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return true;
}
//遍历打印循环队列
bool QueueTraverse(SqQueue Q){
	//判断队列是否为空
	if (Q.rear == Q.front) return false;
	for(QElemType i =Q.front;i !=(Q.rear)%MAXQSIZE;i=(i+1)%MAXQSIZE){
		printf("%d\n",Q.base[i]);
	}

}

int main(){
	//创建并初始化循环队列
	SqQueue Q;
	InitQueue(Q); 
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	EnQueue(Q,4);
	QElemType val;
	DeQueue(Q,val);
	printf("删除的元素:%d\n",val);
	QueueTraverse(Q);
}










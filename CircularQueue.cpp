//ѭ������
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXQSIZE 100 
#define QElemType int
//ѭ�����нṹ
typedef  struct{
	QElemType *base;	//�洢�ռ����ַ
	int front;	//ͷָ�� 
	int rear; 	//βָ�� 
}SqQueue;

//��ʼ��ѭ������
bool InitQueue(SqQueue &Q){
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
	
} 

//����ѭ������
bool DestroyQueue(SqQueue &Q) {
	while(Q.rear != Q.front){
		Q.front = (Q.front+1)%MAXQSIZE;
	}
	delete Q.base;
}

//���ѭ������
bool ClearQueue(SqQueue &Q) {
	while(Q.rear != Q.front){
		Q.front = (Q.front+1)%MAXQSIZE;
	}
	
}

//�п�ѭ������
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//ѭ�����еĳ���
int QueueLength(SqQueue Q){
	
	return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
} 

//���ض�ͷԪ��
QElemType GetHead(SqQueue Q){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear != Q.front) 
		return Q.base[Q.front];

}
//�����βԪ��
bool EnQueue(SqQueue &Q,QElemType e){
	//�ж϶����Ƿ�Ϊ��
	if((Q.rear+1)%MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return true;
}

//ɾ����ͷԪ��
bool DeQueue(SqQueue &Q,QElemType &e){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear == Q.front) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return true;
}
//������ӡѭ������
bool QueueTraverse(SqQueue Q){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear == Q.front) return false;
	for(QElemType i =Q.front;i !=(Q.rear)%MAXQSIZE;i=(i+1)%MAXQSIZE){
		printf("%d\n",Q.base[i]);
	}

}

int main(){
	//��������ʼ��ѭ������
	SqQueue Q;
	InitQueue(Q); 
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	EnQueue(Q,4);
	QElemType val;
	DeQueue(Q,val);
	printf("ɾ����Ԫ��:%d\n",val);
	QueueTraverse(Q);
}










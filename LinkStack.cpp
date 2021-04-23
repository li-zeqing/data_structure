#include <stdio.h>
#include <iostream>
using namespace std;
typedef int SElemType;
typedef int ElemType;
/*
	������ջ�Ļ���������
	 ������ջ����ʼ������ջ����ջ��
	��ȡջ��Ԫ�أ�������ջ�ĳ��ȣ���ա�����ջ �������� 
*/ 

//��ջ 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

//��ջ�ĳ�ʼ��
bool InitStack(LinkStack &S){
	S = NULL;
	return true;
} 

//��ջ����ջ
bool Push(LinkStack &S, SElemType e){
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

//��ջ�ĳ�ջ
bool Pop(LinkStack &S,SElemType &e){
	if(S==NULL) return false;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return true;
	
}

//ȡջ��Ԫ�� 
int GetTop(LinkStack S){
	if(S!=NULL)
		return S->data;
}
//ջ�ĳ���
int StackLength(LinkStack S){
	if(S==NULL) return 0;
	else{
		int len =0;
		while(S!=NULL){
			S=S->next;
			len++;
		}
		return len;
	}
}



 
//��ջ����� 
bool ClearStack(LinkStack &S){
	while(S!=NULL){
		SElemType e;
		Pop(S,e);
	}
	return true;
	
} 
//ջ������ 
bool DestroyStack(LinkStack &S){
	while(S!=NULL){
		SElemType e;
		Pop(S,e);
	}
	delete S;
	return true;
}


int main(){
	//��������ʼ��һ��ջ 
	LinkStack S;
	InitStack(S);
//	�ֱ���ջ��Push1,2,3,4 
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	
//	ClearStack(S);	//���ջ 
//	DestroyStack(S);  //����ջ 
	printf("%d",GetTop(S));  //��ӡջ��Ԫ�� 
//	printf("%d",StackLength(S));

}


#include <stdio.h>
#include <iostream>
using namespace std;
typedef int SElemType;
typedef int ElemType;
//���Ƶ�ת����ʮ������������d��������ת��
/*
	N = (N div d )*d + N mod d    (���У�divΪ�������㣬modΪ��������)
*/ 

//��ջ�Ľṹ 
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

//ʮ����������ת��Ϊd������ 
bool numConversion(int numTen, int d ){
	//������ջ�������洢���� 
	LinkStack S; 
	InitStack(S);
	while(numTen!=0){
		Push(S,numTen%d);
		numTen = numTen/d;
	}
	//���ζ�ȡ����ӡ����
	while(S!=NULL){
		cout<<GetTop(S);
		S = S->next;
	} 
	return true;
	
} 
int main(){
	int numTen,d;
	cout<<"������ת��ǰ��ʮ��������";
	cin>>numTen;
	cout<<"��������Ҫ��d���ƣ�d = " ;
	cin>>d;
	cout<<"��������";
	numConversion(numTen,d);
	return 1;
}


#include <stdio.h>
#include <iostream>
using namespace std;

//˳��ջ
#define MAXSIZE 100
#define SElemType int
typedef struct{
	SElemType *top; 
	SElemType *base;
	int stacksize;
}SqStack; 
//��ʼ��ջ
bool InitSqStack(SqStack &S){
	S.base =new SElemType[MAXSIZE];		//����һ��MAXSIZE���ȵĴ洢�ռ䣬������ַ����base 
	if(!S.base) return false;
	S.top = S.base;		//top��base��ָ��ջͷ����ʾջ�� 
	S.stacksize = MAXSIZE;
	return true;
	
}
 
//��ջ����
bool Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize) return false;
	*S.top=e;
	S.top++;
	return true;	
}

//��ջ����
bool Pop(SqStack &S,SElemType &e){
	if(S.top ==S.base) return false;
	S.top--;
	e =*S.top;
	return true;
}

//��ջ���� 
bool GetTop(SqStack S,SElemType &x){
	if(S.top ==S.base) return false;
	S.top--;
	x =*S.top;
	return true;
}
int main(){
	SqStack S;
	InitSqStack(S);
	
	SElemType e = 1;
	Push(S,e);
	SElemType x;
	GetTop(S,x);
	printf("%d",x);
	
	return 0;
}


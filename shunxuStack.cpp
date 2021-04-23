#include <stdio.h>
#include <iostream>
using namespace std;

//顺序栈
#define MAXSIZE 100
#define SElemType int
typedef struct{
	SElemType *top; 
	SElemType *base;
	int stacksize;
}SqStack; 
//初始化栈
bool InitSqStack(SqStack &S){
	S.base =new SElemType[MAXSIZE];		//创建一个MAXSIZE长度的存储空间，将基地址赋给base 
	if(!S.base) return false;
	S.top = S.base;		//top与base均指向栈头，表示栈空 
	S.stacksize = MAXSIZE;
	return true;
	
}
 
//入栈操作
bool Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize) return false;
	*S.top=e;
	S.top++;
	return true;	
}

//出栈操作
bool Pop(SqStack &S,SElemType &e){
	if(S.top ==S.base) return false;
	S.top--;
	e =*S.top;
	return true;
}

//读栈操作 
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


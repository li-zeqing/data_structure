#include <stdio.h>
#include <iostream>
using namespace std;
typedef int SElemType;
typedef int ElemType;
//数制的转换：十进制数与其他d进制数的转换
/*
	N = (N div d )*d + N mod d    (其中，div为整除运算，mod为余数运算)
*/ 

//链栈的结构 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

//链栈的初始化
bool InitStack(LinkStack &S){
	S = NULL;
	return true;
} 

//链栈的入栈
bool Push(LinkStack &S, SElemType e){
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

//链栈的出栈
bool Pop(LinkStack &S,SElemType &e){
	if(S==NULL) return false;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return true;	
}

//取栈顶元素 
int GetTop(LinkStack S){
	if(S!=NULL)
		return S->data;
}
//栈的长度
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

//链栈的清空 
bool ClearStack(LinkStack &S){
	while(S!=NULL){
		SElemType e;
		Pop(S,e);
	}
	return true;	
}
 
//栈的销毁 
bool DestroyStack(LinkStack &S){
	while(S!=NULL){
		SElemType e;
		Pop(S,e);
	}
	delete S;
	return true;
}

//十进制正整数转化为d进制数 
bool numConversion(int numTen, int d ){
	//创建链栈，用来存储余数 
	LinkStack S; 
	InitStack(S);
	while(numTen!=0){
		Push(S,numTen%d);
		numTen = numTen/d;
	}
	//依次读取并打印余数
	while(S!=NULL){
		cout<<GetTop(S);
		S = S->next;
	} 
	return true;
	
} 
int main(){
	int numTen,d;
	cout<<"请输入转换前的十进制数：";
	cin>>numTen;
	cout<<"请输入需要成d进制：d = " ;
	cin>>d;
	cout<<"计算结果：";
	numConversion(numTen,d);
	return 1;
}


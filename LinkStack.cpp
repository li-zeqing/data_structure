#include <stdio.h>
#include <iostream>
using namespace std;
typedef int SElemType;
typedef int ElemType;
/*
	关于链栈的基本操作：
	 创建链栈，初始化，入栈，出栈，
	读取栈顶元素，返回链栈的长度，清空、销毁栈 。。。。 
*/ 

//链栈 
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


int main(){
	//创建并初始化一个栈 
	LinkStack S;
	InitStack(S);
//	分别向栈中Push1,2,3,4 
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	
//	ClearStack(S);	//清空栈 
//	DestroyStack(S);  //销毁栈 
	printf("%d",GetTop(S));  //打印栈顶元素 
//	printf("%d",StackLength(S));

}


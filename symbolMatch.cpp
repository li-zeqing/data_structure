//符号的匹配：左括号与右括号的匹配 
/*
	左括号：'(''{' '['
	右括号：')''}' ']'  
*/ 
#include <stdio.h>
#include <iostream>
using namespace std;
typedef char SElemType;
typedef char ElemType;


//链栈 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;		//指向下一个栈 
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
//栈的判空
bool stackEmpty( LinkStack S ) {
	return S ==NULL;
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
//匹配函数 
bool isMatch(char left, char right){
	if((left=='('&&right==')')||(left=='['&&right==']')||(left=='{'&&right=='}'))
		return true;
	else
		return false;
}
//括号匹配函数
bool symMatch(char *str) {
	//创建并初始化链栈，用于存储左括号
	LinkStack S; 
	InitStack(S);
	
	int i=0;
	while(str[i]!='\0'){ 
		
		if(str[i]=='('||str[i]=='['||str[i]=='{'){	//左括号 
			Push(S,str[i]);	//为左括号时存入链栈
		}
		if (str[i]==')'||str[i]==']'||str[i]=='}'){	//右括号 
			if(stackEmpty(S)) {
				return false;
			}
			else{
				SElemType left; 
				Pop(S,left);	//为右括号时，弹出栈顶元素 
				if(!isMatch(left,str[i])){
					return false;
				}
			
			}
			
		}

		i++;
	}
	if(stackEmpty(S)) 
		return true;
	else
		return false;
	
}
int main(){
	//定义一个char数组存储输入的字符串
	char str[100];
	cout<<"请输入：";
	cin>>str;
//	bool a = symMatch(str);
	if(symMatch(str)) 
		cout<<"匹配成功";
	else 
		cout<<"匹配失败" ;
}

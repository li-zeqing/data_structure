//表达式求值，加减乘除运算。
//输入一个带运算符和操作数的表达式，构建两个链栈分别为用于存操作数 栈OPND，存运算符栈OPTR 
//其中'('和')'也存在栈OPTR中。 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char SElemType;
typedef char ElemType;


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
//判断str[i]是否为操作数，为操作数返回true
bool Isnumber(char a){
//	if(a!='+' && a!='-'&& a!='*' && a!='/' && a!='('&&a!=')')
	if(a>='0'&& a<='9')
		return true;
	else
		return false;
}
int Priority[7][7] ={
	//  建立以 + - * / ( ) @为行、列的二维数组，规定行所在的运算符优先级大于对应列所在的赋值为1
	{1,1,0,0,0,1,1},{1,1,0,0,0,1,1},{1,1,1,1,0,1,1},{1,1,1,1,0,1,1},{0,0,0,0,0,2,1},{1,1,1,1,3,1,1},{0,0,0,0,0,1,2}
};
//定位运算符所在的数组下标 
int Location(char a){
	switch(a){
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '(':
			return 4;
		case ')':
			return 5;
		case '@':
			return 6;
	}
}

//Precede为判断OPTR栈顶元素与str[i]优先级函数
char Precede(char a ,char b){
	if(a=='('&& b==')')
		return '=';
	else if(Priority[Location(a)][Location(b)]==1)
		return '>';
	else if(Priority[Location(a)][Location(b)]==0)
		return '<';
}

//算数运算函数 
char Operate(char left_num,char temp,char right_num){
	left_num = left_num-48;
	right_num = right_num-48;
	switch(temp){
		case '+':
			return left_num + right_num+48;
		case '-':
			return left_num - right_num+48;
		case '*':
			return left_num * right_num+48;
		case '/':
			return left_num / right_num+48;
	}
	
}

int main(){
	//创建并初始化两个链栈
	LinkStack OPTR,OPND;
	InitStack(OPTR);
	InitStack(OPND);
	//创建一个字符型数组，用于存输入的表达式 
	char str[100];
	cout<<"请输入表达式：";
	cin>>str;
	//规定'@'为存运算符栈OPTR的栈低元素，所以先将其入栈
	Push(OPTR,'@'); 
	int i=0;
//	cout<<str<<endl; 
//	printf("%d",Isnumber('0'));
//	printf("%c",GetTop(OPTR));
//	printf("%d",Operate(49,'+',50));
//	int temp_opnd=0; 
	char left,right,result;
//	int left_num,right_num;
	while(str[i] !='\0'){
		//判断OPTR栈顶的运算符与当前读到的运算符str[i]比较，
		//如果<,将str[i]入栈，
		//如果>，则弹出栈顶运算符并且同时弹出两个操作数,再做运算，最后将结果入栈OPND,继续与栈顶比较 
		//如果=，OPTR栈顶为'('，str[i]为')',则弹出OPTR栈顶元素，此时'('与')'相互匹配。 
		if(Isnumber(str[i])){	//Isnumber为判断str[i]是否为操作数，为操作数返回true
//			int num = str[i]-48;//用int型变量存储转化后的str[i],atoi()函数将字符串转为int型并返回一个int 
//			num += temp_opnd; 
//			temp_opnd=str[i]-48;
//			Push(OPND,num);
			Push(OPND,str[i]);
		}
		else if(str[i]=='('){
			Push(OPTR,str[i]);
		}
		else{
			switch(Precede(GetTop(OPTR),str[i])) //Precede为判断str[i]与OPTR栈顶元素优先级函数 
			{
				case '<': 	//str[i]优先级大 
					Push(OPTR,str[i]);
					break;
				case '>':	//str[i]优先级小
					char temp; 
					Pop(OPTR,temp);
					Pop(OPND,right);
					Pop(OPND,left);					
					Push(OPND,Operate(left,temp,right));
					continue;
				case '=':
					char x;
					Pop(OPTR,x);
					break;
			}
		}
		i++;
	}
	while(GetTop(OPTR)!='@'){
		char temp;
		Pop(OPTR,temp);
		Pop(OPND,right);
		Pop(OPND,left);					
		Push(OPND,Operate(left,temp,right));
	}
	Pop(OPND,result);
	printf("%d",result-48);
	return 1;


}


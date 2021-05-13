//���ʽ��ֵ���Ӽ��˳����㡣
//����һ����������Ͳ������ı��ʽ������������ջ�ֱ�Ϊ���ڴ������ ջOPND���������ջOPTR 
//����'('��')'Ҳ����ջOPTR�С� 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char SElemType;
typedef char ElemType;


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
//ջ���п�
bool stackEmpty( LinkStack S ) {
	return S ==NULL;
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
//�ж�str[i]�Ƿ�Ϊ��������Ϊ����������true
bool Isnumber(char a){
//	if(a!='+' && a!='-'&& a!='*' && a!='/' && a!='('&&a!=')')
	if(a>='0'&& a<='9')
		return true;
	else
		return false;
}
int Priority[7][7] ={
	//  ������ + - * / ( ) @Ϊ�С��еĶ�ά���飬�涨�����ڵ���������ȼ����ڶ�Ӧ�����ڵĸ�ֵΪ1
	{1,1,0,0,0,1,1},{1,1,0,0,0,1,1},{1,1,1,1,0,1,1},{1,1,1,1,0,1,1},{0,0,0,0,0,2,1},{1,1,1,1,3,1,1},{0,0,0,0,0,1,2}
};
//��λ��������ڵ������±� 
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

//PrecedeΪ�ж�OPTRջ��Ԫ����str[i]���ȼ�����
char Precede(char a ,char b){
	if(a=='('&& b==')')
		return '=';
	else if(Priority[Location(a)][Location(b)]==1)
		return '>';
	else if(Priority[Location(a)][Location(b)]==0)
		return '<';
}

//�������㺯�� 
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
	//��������ʼ��������ջ
	LinkStack OPTR,OPND;
	InitStack(OPTR);
	InitStack(OPND);
	//����һ���ַ������飬���ڴ�����ı��ʽ 
	char str[100];
	cout<<"��������ʽ��";
	cin>>str;
	//�涨'@'Ϊ�������ջOPTR��ջ��Ԫ�أ������Ƚ�����ջ
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
		//�ж�OPTRջ����������뵱ǰ�����������str[i]�Ƚϣ�
		//���<,��str[i]��ջ��
		//���>���򵯳�ջ�����������ͬʱ��������������,�������㣬��󽫽����ջOPND,������ջ���Ƚ� 
		//���=��OPTRջ��Ϊ'('��str[i]Ϊ')',�򵯳�OPTRջ��Ԫ�أ���ʱ'('��')'�໥ƥ�䡣 
		if(Isnumber(str[i])){	//IsnumberΪ�ж�str[i]�Ƿ�Ϊ��������Ϊ����������true
//			int num = str[i]-48;//��int�ͱ����洢ת�����str[i],atoi()�������ַ���תΪint�Ͳ�����һ��int 
//			num += temp_opnd; 
//			temp_opnd=str[i]-48;
//			Push(OPND,num);
			Push(OPND,str[i]);
		}
		else if(str[i]=='('){
			Push(OPTR,str[i]);
		}
		else{
			switch(Precede(GetTop(OPTR),str[i])) //PrecedeΪ�ж�str[i]��OPTRջ��Ԫ�����ȼ����� 
			{
				case '<': 	//str[i]���ȼ��� 
					Push(OPTR,str[i]);
					break;
				case '>':	//str[i]���ȼ�С
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


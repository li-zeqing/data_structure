//���ŵ�ƥ�䣺�������������ŵ�ƥ�� 
/*
	�����ţ�'(''{' '['
	�����ţ�')''}' ']'  
*/ 
#include <stdio.h>
#include <iostream>
using namespace std;
typedef char SElemType;
typedef char ElemType;


//��ջ 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;		//ָ����һ��ջ 
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
//ƥ�亯�� 
bool isMatch(char left, char right){
	if((left=='('&&right==')')||(left=='['&&right==']')||(left=='{'&&right=='}'))
		return true;
	else
		return false;
}
//����ƥ�亯��
bool symMatch(char *str) {
	//��������ʼ����ջ�����ڴ洢������
	LinkStack S; 
	InitStack(S);
	
	int i=0;
	while(str[i]!='\0'){ 
		
		if(str[i]=='('||str[i]=='['||str[i]=='{'){	//������ 
			Push(S,str[i]);	//Ϊ������ʱ������ջ
		}
		if (str[i]==')'||str[i]==']'||str[i]=='}'){	//������ 
			if(stackEmpty(S)) {
				return false;
			}
			else{
				SElemType left; 
				Pop(S,left);	//Ϊ������ʱ������ջ��Ԫ�� 
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
	//����һ��char����洢������ַ���
	char str[100];
	cout<<"�����룺";
	cin>>str;
//	bool a = symMatch(str);
	if(symMatch(str)) 
		cout<<"ƥ��ɹ�";
	else 
		cout<<"ƥ��ʧ��" ;
}

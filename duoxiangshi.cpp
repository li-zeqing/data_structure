#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct PNode
{
	float coef;	//系数 
	int expn;	//指数
	struct PNode *next;	//指针域 
 }PNode,*Polynomial;

//输入n项系数和指数，建立表示多项式的有序链表P 
void CreatePloyn(Polynomial &P,int n )
{
	P = new PNode;
	P->next = NULL;	//先建立一个带头结点的单链表
	for(int i = 1;i<=n;++i)
	{
		PNode *s = new PNode;	//生成新结点 
		cout<<"请输入第"<<i<<"项系数"; 
		cin>>s->coef;	//输入系数
		cout<<"请输入第"<<i<<"项指数";
		cin>>s->expn;	//输入指数
		PNode *pre = P;	//pre用于保存q的前驱，初值为头结点P 
		PNode *q = P->next;	//q初始化，指向首元结点 
		//存储方式：([大][...][小])  
		while(q && q->expn>s->expn)	//通过比较指数找到第一个大于输入项指数的项*q 
		{
			pre = q;
			q = q->next;
		}
		s->next = q;	//将输入项s插入到q和其前驱结点pre之间 
		pre->next = s; 
	 } 
}
//打印单链表
void ShowPoly(Polynomial P)
{	
	P = P->next;
	while(P!=NULL)
	{
		if(P->expn>0)
		{
			cout<<P->coef<<"x^"<<P->expn;
			if(P->next)
			{
				if(P->next->coef>0)
				cout<<"+";
			}
		}		
		else
			cout<<P->coef;		
		P = P->next;
	}
		
 } 	

//多项式的相加
void AddPolyn(Polynomial &Pa,Polynomial Pb)
{
	//多项式加法：Pa=Pa+Pb，利用两个多项式的结点构成"和多项式"
	PNode *p1 = Pa->next;	//p1指向Pa的首元结点 
	PNode *p2 = Pb->next; 	//p2指向Pb的首元结点
	PNode *p3 = Pa;	//p3指向“和多项式”结点，初值为Pa
	while(p1&&p2)
	{
		if(p1->expn==p2->expn)	//指数相等时 
		{
			float sum = p1->coef+p2->coef;	//sum保存相同指数项的系数和 
			if(sum!=0)	//系数不为零 
			{
				p1->coef = sum;	//修改Pa当前结点的系数 
				p3 = p3->next;	//p3指向后一项 
				p1 = p1->next;	//p1指向后一项 
				PNode *r =p2; p2=p2->next; delete r;	//删除当前结点，p2指向后一项 
			}
			else
			{
				p3->next = p3->next->next;
				delete p1;
				p1 = p3->next;
				p2 = p2->next; 
			}
		}
		
		else if(p1->expn<p2->expn)	//Pa当前结点的指数较小时 
		{
			p2->next = p1;
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
			
		}
		else	//Pa当前结点的指数较大时 
		{
			p1 = p1->next;
			p3 = p3->next;
		}
	}	
//	p3->next = p1?p1:p2;	//正则表达式，当p1或者p2中为空时，插入非空多项式的剩余段
	if(p1=NULL) p3->next = p2;
	delete Pb;	//释放Pb的头结点 

 } 

int main(){
	Polynomial Pa;
	Polynomial Pb;
	int N1,N2; 
	cout<<"请输入第一个多项式共有几项：N1=";
	cin>>N1;
	cout<<"请输入第一个多项式"<<'\n';
	CreatePloyn(Pa,N1);
	ShowPoly(Pa);
	cout<<'\n';
	cout<<"请输入第二个多项式共有几项：N2=";
	cin>>N2;
	cout<<"请输入第二个多项式"<<'\n';
	CreatePloyn(Pb,N2);
	ShowPoly(Pb);
	AddPolyn(Pa,Pb);
	cout<<'\n';
	cout<<"两多项式相加结果为：";
	ShowPoly(Pa);
	return 0;
}

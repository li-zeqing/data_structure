//创建男、女两条顺序队，先入队的男士、女士先出队配成舞伴
//顺序队列
#include <stdio.h>
#include <iostream>
using namespace std;

//定义跳舞者个人信息
typedef struct{
	char name[20];
	char sex;
}Person;

//循环顺序队列
#define MAXQSIZE 100
typedef struct{
	Person *base;   //存储空间基地址
	int front;
	int rear;
}SqQueue;

//初始化循环队列
bool InitQueue(SqQueue &Q){
	Q.base = new Person[MAXQSIZE];
	if(!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
}

//判空循环队列
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//返回队头元素
Person GetHead(SqQueue Q){
	//判断队列是否为空
	if (Q.rear != Q.front)
		return Q.base[Q.front];

}
//插入队尾元素
bool EnQueue(SqQueue &Q,Person e){
	//判断队列是否为满
	if((Q.rear+1)%MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return true;
}

//删除队头元素
bool DeQueue(SqQueue &Q,Person &e){
	//判断队列是否为空
	if (Q.rear == Q.front) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return true;
}
//舞伴配对
void DancePartner(SqQueue &Mdancers,SqQueue &Fdancers,Person dancer[],int num){
	//结构数组dance中存放跳舞的男女，num为跳舞的人数
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	//依次将跳舞者根据性别插入循环顺序队
	for(int i = 0; i<num; i++){
		Person p = dancer[i];
		if(p.sex =='M') EnQueue(Mdancers,p);
		else EnQueue(Fdancers,p);
	}
	cout<<"The dancing partners are :\n";
	while(!QueueEmpty(Mdancers) && !QueueEmpty(Fdancers)){
		//依次输出男士、女士的姓名
		Person p;
		DeQueue(Fdancers,p);
		cout<<p.name<<"  ";
		DeQueue(Mdancers,p);
		cout<<p.name<<endl;
	}
	if(!QueueEmpty(Mdancers)){
		//男士队列为非空，输出队头男士名字
		Person p = GetHead(Mdancers);
		cout<<"The first man to get a partner is :"<<p.name<<endl;
	}
	else if(!QueueEmpty(Fdancers)){
		Person p = GetHead(Fdancers);
		cout<<"The first woman to get a partner is :"<<p.name<<endl;
	}
}
int main(){
	SqQueue Mdancers,Fdancers;  //创建男士、女士循环顺序队列
	Person dancer[5] = {{"zhangsan",'M'},{"xiaohon",'F'},{"liqiang",'M'},{"xiaomei",'F'},{"zhaosi",'M'}};
	DancePartner(Mdancers,Fdancers,dancer,5);
	return 1;
};

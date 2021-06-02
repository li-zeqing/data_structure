//�����С�Ů����˳��ӣ�����ӵ���ʿ��Ůʿ�ȳ���������
//˳�����
#include <stdio.h>
#include <iostream>
using namespace std;

//���������߸�����Ϣ
typedef struct{
	char name[20];
	char sex;
}Person;

//ѭ��˳�����
#define MAXQSIZE 100
typedef struct{
	Person *base;   //�洢�ռ����ַ
	int front;
	int rear;
}SqQueue;

//��ʼ��ѭ������
bool InitQueue(SqQueue &Q){
	Q.base = new Person[MAXQSIZE];
	if(!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
}

//�п�ѭ������
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//���ض�ͷԪ��
Person GetHead(SqQueue Q){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear != Q.front)
		return Q.base[Q.front];

}
//�����βԪ��
bool EnQueue(SqQueue &Q,Person e){
	//�ж϶����Ƿ�Ϊ��
	if((Q.rear+1)%MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return true;
}

//ɾ����ͷԪ��
bool DeQueue(SqQueue &Q,Person &e){
	//�ж϶����Ƿ�Ϊ��
	if (Q.rear == Q.front) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return true;
}
//������
void DancePartner(SqQueue &Mdancers,SqQueue &Fdancers,Person dancer[],int num){
	//�ṹ����dance�д���������Ů��numΪ���������
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	//���ν������߸����Ա����ѭ��˳���
	for(int i = 0; i<num; i++){
		Person p = dancer[i];
		if(p.sex =='M') EnQueue(Mdancers,p);
		else EnQueue(Fdancers,p);
	}
	cout<<"The dancing partners are :\n";
	while(!QueueEmpty(Mdancers) && !QueueEmpty(Fdancers)){
		//���������ʿ��Ůʿ������
		Person p;
		DeQueue(Fdancers,p);
		cout<<p.name<<"  ";
		DeQueue(Mdancers,p);
		cout<<p.name<<endl;
	}
	if(!QueueEmpty(Mdancers)){
		//��ʿ����Ϊ�ǿգ������ͷ��ʿ����
		Person p = GetHead(Mdancers);
		cout<<"The first man to get a partner is :"<<p.name<<endl;
	}
	else if(!QueueEmpty(Fdancers)){
		Person p = GetHead(Fdancers);
		cout<<"The first woman to get a partner is :"<<p.name<<endl;
	}
}
int main(){
	SqQueue Mdancers,Fdancers;  //������ʿ��Ůʿѭ��˳�����
	Person dancer[5] = {{"zhangsan",'M'},{"xiaohon",'F'},{"liqiang",'M'},{"xiaomei",'F'},{"zhaosi",'M'}};
	DancePartner(Mdancers,Fdancers,dancer,5);
	return 1;
};

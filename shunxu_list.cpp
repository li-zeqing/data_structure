#include <stdio.h>
#include <iostream>
#define list_size 100
typedef int status;
#define ERROR 0
#define OK 1 
typedef int elemtype;	//�Զ���int����element

typedef struct	//˳����е�һ�����
{
	elemtype *elem;	//�洢�ռ�Ļ���ַ 
	int listsize; //˳������󳤶� 
	int length; //��ǰ˳���ĳ��� 
 } Sqlist;

status initializer_list(Sqlist &L);	//���� �����ʼ��
status creatnewlist(Sqlist &L,elemtype a[],int n );	//���� ����˳���
int insert(Sqlist &L,int i ,elemtype e);	//���� ���뺯�� 
void show(Sqlist L);	//���� ���˳���
status deletelist(Sqlist &L,int i, elemtype &e);	//���� ɾ������ 
int main(){
	Sqlist L;	//����һ��˳��� 
	int n = 9;
	elemtype a[] = {11,12,13,14,15,16,17,18,19};	//���� 
//	printf("���������ݵĸ���N��"); 
//	scanf("%d",&n);
	initializer_list(L);
	creatnewlist(L,a,n);
	show(L);
	
// ����һԪ�� 
	int k;
	printf("\n��������Ҫ����Ԫ�ص�λ�ã��ڼ���λ�ã���");
	scanf("%d",&k);
	insert(L,k,1);
//	for(int i =0;i<L.length;i++){
//		printf("%d\n",L.elem[i]); 
//	}	
	show(L);
	
//ɾ��һԪ��
	int m;
	elemtype e;
	printf("\n��������Ҫɾ��Ԫ�ص�λ�ã��ڼ���λ�ã���");
	scanf("%d",&m);
	deletelist(L,m, e);
	show(L);
	printf("\nɾ����Ԫ��Ϊ��%d",e);
	
	return 1;
} 



//�����ʼ��
status initializer_list(Sqlist &L)	 
{
	L.elem =new elemtype[list_size];
	if(!L.elem) return ERROR;	//�����ڴ�ʧ�� 
	for(int i=0;i<list_size;i++)
		L.elem[i] = 0; 
	L.length = 0;
	L.listsize = list_size;
	return OK;
 } 
 //����һ��˳��� 
 status creatnewlist(Sqlist &L,elemtype a[],int n )		
 {
 	int i;
 	if(n>list_size) ERROR; 
	else 
 		for(i=0;i<n;i++)
	 		{
	 			L.elem[i]=a[i];
	 			L.length++;
		 	}
	return OK;
  }
//���˳���
  void show(Sqlist L)	
  {
  	int i;
  	printf("��˳����ֵΪ��");
  	for(i=0;i<L.length;i++)
  	{	
	  	printf("\n\n");
  		printf("%d",L.elem[i]);
  		
	  }
   } 
 //�ڵ�i��λ�ò���Ԫ��e 
 status insert(Sqlist &L,int i,elemtype e)
 {
 	//�жϲ���λ���Ƿ�Ϸ�
	int j=0;
	if(L.length>=list_size){
		printf("˳����Ѿ���\n");
		return ERROR;
	} else if((i<1)||(i>L.length+1)){
		printf("�����λ�ò��Ϸ�");
		return ERROR;
	}else {
		for(j=L.length-1;j>=i-1;j--){
			L.elem[j+1]=L.elem[j];	//����λ���Ժ��Ԫ��ȫ�������ƶ�һ��λ�� 
		}
		L.elem[i-1]=e;
		L.length++;
		return OK;
	}
 	
  } 

//�ڵ�i��λ��ɾ��һԪ�أ���e��¼ɾ��Ԫ�� 
status deletelist(Sqlist &L,int i, elemtype &e) 
 {
 	if((i<1)||(i>L.length)){
 		printf("����ɾ��Ԫ��λ�ò��Ϸ�");
 		return ERROR;
	 }else{
	 	e = L.elem[i-1];
	 	for(int j=i-1;j<=L.length-1;j++)
	 	L.elem[j] = L.elem[j+1];
	 	L.length--;
	 	return OK;
	 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 

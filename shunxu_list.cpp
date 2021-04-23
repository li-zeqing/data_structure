#include <stdio.h>
#include <iostream>
#define list_size 100
typedef int status;
#define ERROR 0
#define OK 1 
typedef int elemtype;	//自定义int类型element

typedef struct	//顺序表中的一个结点
{
	elemtype *elem;	//存储空间的基地址 
	int listsize; //顺序表的最大长度 
	int length; //当前顺序表的长度 
 } Sqlist;

status initializer_list(Sqlist &L);	//声明 建表初始化
status creatnewlist(Sqlist &L,elemtype a[],int n );	//声明 建立顺序表
int insert(Sqlist &L,int i ,elemtype e);	//声明 插入函数 
void show(Sqlist L);	//声明 输出顺序表
status deletelist(Sqlist &L,int i, elemtype &e);	//声明 删除函数 
int main(){
	Sqlist L;	//创建一个顺序表 
	int n = 9;
	elemtype a[] = {11,12,13,14,15,16,17,18,19};	//数组 
//	printf("请输入数据的个数N："); 
//	scanf("%d",&n);
	initializer_list(L);
	creatnewlist(L,a,n);
	show(L);
	
// 插入一元素 
	int k;
	printf("\n请输入需要插入元素的位置（第几个位置）：");
	scanf("%d",&k);
	insert(L,k,1);
//	for(int i =0;i<L.length;i++){
//		printf("%d\n",L.elem[i]); 
//	}	
	show(L);
	
//删除一元素
	int m;
	elemtype e;
	printf("\n请输入需要删除元素的位置（第几个位置）：");
	scanf("%d",&m);
	deletelist(L,m, e);
	show(L);
	printf("\n删除的元素为：%d",e);
	
	return 1;
} 



//建表初始化
status initializer_list(Sqlist &L)	 
{
	L.elem =new elemtype[list_size];
	if(!L.elem) return ERROR;	//分配内存失败 
	for(int i=0;i<list_size;i++)
		L.elem[i] = 0; 
	L.length = 0;
	L.listsize = list_size;
	return OK;
 } 
 //创建一个顺序表 
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
//输出顺序表
  void show(Sqlist L)	
  {
  	int i;
  	printf("该顺序表的值为：");
  	for(i=0;i<L.length;i++)
  	{	
	  	printf("\n\n");
  		printf("%d",L.elem[i]);
  		
	  }
   } 
 //在第i个位置插入元素e 
 status insert(Sqlist &L,int i,elemtype e)
 {
 	//判断插入位置是否合法
	int j=0;
	if(L.length>=list_size){
		printf("顺序表已经满\n");
		return ERROR;
	} else if((i<1)||(i>L.length+1)){
		printf("插入的位置不合法");
		return ERROR;
	}else {
		for(j=L.length-1;j>=i-1;j--){
			L.elem[j+1]=L.elem[j];	//插入位置以后的元素全部往后移动一个位置 
		}
		L.elem[i-1]=e;
		L.length++;
		return OK;
	}
 	
  } 

//在第i个位置删除一元素，用e记录删除元素 
status deletelist(Sqlist &L,int i, elemtype &e) 
 {
 	if((i<1)||(i>L.length)){
 		printf("输入删除元素位置不合法");
 		return ERROR;
	 }else{
	 	e = L.elem[i-1];
	 	for(int j=i-1;j<=L.length-1;j++)
	 	L.elem[j] = L.elem[j+1];
	 	L.length--;
	 	return OK;
	 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include <iostream>
using namespace std;

typedef struct orderListNode{
	
	int occurTime;  //事件发生的时间
	int type; //type = 0表示到达事件；否则都是离开事件
	orderListNode *next; 
	
} *orderList;


void initOrderList( orderList &L ){
	
	L = new orderListNode;
	L->next = NULL;
}

int isEmptyOrderList(orderList L){
	
	return L->next == NULL;
	
}

void insertOrderList( orderList &L, int occurTime, int type ){
	
	orderList newNode = new orderListNode;
	newNode->occurTime = occurTime;
	newNode->type = type;
	
	orderList ptr, prePtr;
	prePtr = L;
	ptr = L->next;
	
	while( ptr && newNode->occurTime > ptr->occurTime ){
		ptr = ptr->next;
		prePtr = prePtr->next; 
	}
	
	newNode->next = prePtr->next;
	prePtr->next = newNode;
	
}

//取头元素
void delFirstOrderList( orderList L, int &occurTime, int &type ){
	
	occurTime = L->next->occurTime;
	type = L->next->type;
	
	L->next = L->next->next;
	
}

void orderListTraverse( orderList L ){
	
	L = L->next;
	while( L ){
		
		cout << "occurTime is : " << L->occurTime << "  "
			 << "type is: " << L->type << endl;
		
		L = L->next;
	}
	
	
}

//int main(){
//	
//	orderList L;
//	initOrderList( L );
//	
//	insertOrderList(L, 56, 0);
//	insertOrderList(L, 12, 4);
//	insertOrderList(L, 45, 5);
//	insertOrderList(L, 100, 6);
//	insertOrderList(L, 23, 7);
//	insertOrderList(L, 1, 8);
//	insertOrderList(L, 66, 9);
//	
//	orderListTraverse(L);
//	
//	int occurTime, type;
//	delFirstOrderList(L, occurTime, type);
//	cout << occurTime << "  " << type << endl;
////	
//	orderListTraverse(L);
//	
//}

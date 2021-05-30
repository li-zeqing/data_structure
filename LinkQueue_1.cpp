#include "orderList.cpp"




typedef struct queueNode{
	int arrivalTime; //�˿͵������е�ʱ��
	int duringTime;  //�˿ͽ��ܴ��ڷ��񻨷ѵ�ʱ��
	queueNode *next;


} *queueNodePtr ;

typedef struct linkQueue{

	queueNodePtr front;
	queueNodePtr rear;
	int length;

};


void initLinkQueue( linkQueue &Q ){

	queueNodePtr newNode = new queueNode;
	Q.front = Q.rear = newNode;
	newNode->next = NULL;
	Q.length = 0;

}

void enQueue( linkQueue &Q, int arrivalTime, int duringTime ){

	queueNodePtr newNode = new queueNode;
	newNode->arrivalTime = arrivalTime;
	newNode->duringTime = duringTime;
	newNode->next = Q.rear->next; //newNode->next = NULL;
	Q.rear->next = newNode;
	Q.rear = newNode;
	Q.length++;
}

void queueTraverse( linkQueue Q ){

	Q.front = Q.front->next;
	while( Q.front ){

		cout << "arrivalTime is : " << Q.front->arrivalTime
		<< "   " << "duringTime is : " << Q.front->duringTime << endl;

		Q.front = Q.front->next;

	}

	cout << "���еĳ����ǣ� " << Q.length << endl;


}

int isEmptyLinkQueue( linkQueue Q ){


	return Q.front == Q.rear;

}

//��ȡͷԪ�ص�duringTime
int getQueueFrontDuringTime(linkQueue Q){

	return Q.front->next->duringTime;

}

void deQueue( linkQueue &Q, int &arrivalTime, int &duringTime ){

	if( isEmptyLinkQueue(Q) ){

		cout << "��ǰ����Ϊ�գ��޷�����" << endl;
		return;

	}

	arrivalTime = Q.front->next->arrivalTime;
	duringTime = Q.front->next->duringTime;
//	Q.front->next = Q.front->next->next;
	queueNodePtr temp = Q.front->next;
	Q.front->next = Q.front->next->next;
	if( !Q.front->next )
		Q.rear = Q.front;
	delete temp;
	Q.length--;


}

//int main(){
//
//	linkQueue Q;
//	initLinkQueue(Q);
//
//	enQueue( Q, 3, 15 );
//	enQueue( Q, 2, 4 );
//	enQueue( Q, 7, 22 );
//
//
//
//	int arrivalTime, duringTime;
//	deQueue( Q, arrivalTime, duringTime );
//
//
//	queueTraverse(Q);
//	deQueue( Q, arrivalTime, duringTime );
//	deQueue( Q, arrivalTime, duringTime );
//
//
//	enQueue( Q, 700, 2200 );
//
////
////	cout << "�����ӵ�Ԫ���ǣ� " << arrivalTime << "  " << duringTime << endl;
//
//	queueTraverse(Q);
//}

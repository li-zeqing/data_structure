#include "linkQueue.cpp"
#include <stdlib.h>
#include <time.h>


#define WINDOWS_NUM 2
#define BANK_OPEN 0
#define BANK_CLOSE 200
#define ARRIVAL_INTER_TIME 5
#define DURING_TIME 30




orderList evList;
linkQueue queueWindow[WINDOWS_NUM + 1]; 
int humanNum;
double spentTime;
int occurTime, type;

void initBank(){
	
//	ev��ʾ������¼��б��������淢���ĵ�����뿪���¼� 
	initOrderList( evList );
	for( int i = 1; i <= WINDOWS_NUM; i++ )
		initLinkQueue(queueWindow[i]);
	
	humanNum = spentTime = 0;
	srand(time(0));
	
}

int generateRand( int interTime ){
	
	return rand() % interTime + 1;
	
}


int findMinLengthQueue( linkQueue queueWindow[] ){
	
	int minIndex = 1, minLength = queueWindow[1].length;
	for( int i = 2; i <= WINDOWS_NUM; i++ ){
		
		if( queueWindow[i].length < minLength ){
			
			minLength = queueWindow[i].length;
			minIndex = i;
			
		}
		
		
	}
	
	return minIndex;
	
}

void customerArrive(){
	
	humanNum++;
	
//	������һ���˿͵����ʱ���� 
	
	int newCustomerInterTime = generateRand( ARRIVAL_INTER_TIME );
//	����һ���¹˿͵�����¼��������뵽�¼��б��� 
	insertOrderList( evList, occurTime + newCustomerInterTime,	0 );
	
	int minLengthQueue = findMinLengthQueue( queueWindow );
	
	int newCustomerServiceTime = generateRand( DURING_TIME );
	enQueue( queueWindow[minLengthQueue], occurTime, newCustomerServiceTime );
	
//	����˿����Ŷ�֮ǰ����Ϊ�գ���������ϼ�����˿ͳ��ӵ�ʱ�� 
	if( 1 == queueWindow[minLengthQueue].length ){
		
		insertOrderList( evList, occurTime + newCustomerServiceTime, minLengthQueue ); 
		
	} 
	
	 
	
}


void customerLeave(){
	
	int customerLeaveIndex = type;
	int arrivalTime, duringTime;
	deQueue( queueWindow[customerLeaveIndex], arrivalTime, duringTime );
	
	spentTime += occurTime - arrivalTime;
	cout << "�ù˿������ѵ�ʱ���ǣ� " << occurTime - arrivalTime << endl << endl << endl; 
	if( !isEmptyLinkQueue(queueWindow[customerLeaveIndex]) )
		insertOrderList(evList, occurTime + getQueueFrontDuringTime(queueWindow[customerLeaveIndex]), customerLeaveIndex);
	
	
}

void bankOpen(){
	
	insertOrderList( evList, BANK_OPEN, 0 );
	
	
	while( !isEmptyOrderList(evList) ){
		
			
		delFirstOrderList(evList, occurTime, type);
		
		if( 0 == type ){
			
			/* TODO (#1#): ����һ�������¼�
 */
			if( occurTime <= BANK_CLOSE ){
				cout << "===============��һ���µĹ˿͵��===============" << endl;
				cout << "���ĵ���ʱ���ǣ� " << occurTime << endl << endl << endl; 
				customerArrive();
			}
				
			
			
		}
		else{
			
			cout << "��ǰ��һ���˿ʹӶ��� " << type << "�뿪" << endl;
			 
			/* TODO (#1#): ����һ���˿��뿪���¼� */
			customerLeave();
			
		}
		
	}
	
	
	
}


int main(){
	
	initBank();
	
	bankOpen();
	
	cout << "�ܹ���" << humanNum << "λ�˿�" << endl;
	cout << "�ܹ�������" << spentTime << "��ʱ��" << endl;
	cout << "ƽ�����ѵ�ʱ���ǣ�" << spentTime / humanNum << endl; 
	
}

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
	
//	ev表示有序的事件列表，用来保存发生的到达或离开的事件 
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
	
//	产生下一个顾客到达的时间间隔 
	
	int newCustomerInterTime = generateRand( ARRIVAL_INTER_TIME );
//	产生一个新顾客到达的事件，并插入到事件列表里 
	insertOrderList( evList, occurTime + newCustomerInterTime,	0 );
	
	int minLengthQueue = findMinLengthQueue( queueWindow );
	
	int newCustomerServiceTime = generateRand( DURING_TIME );
	enQueue( queueWindow[minLengthQueue], occurTime, newCustomerServiceTime );
	
//	如果顾客在排队之前队列为空，则可以马上计算出顾客出队的时间 
	if( 1 == queueWindow[minLengthQueue].length ){
		
		insertOrderList( evList, occurTime + newCustomerServiceTime, minLengthQueue ); 
		
	} 
	
	 
	
}


void customerLeave(){
	
	int customerLeaveIndex = type;
	int arrivalTime, duringTime;
	deQueue( queueWindow[customerLeaveIndex], arrivalTime, duringTime );
	
	spentTime += occurTime - arrivalTime;
	cout << "该顾客所花费的时间是： " << occurTime - arrivalTime << endl << endl << endl; 
	if( !isEmptyLinkQueue(queueWindow[customerLeaveIndex]) )
		insertOrderList(evList, occurTime + getQueueFrontDuringTime(queueWindow[customerLeaveIndex]), customerLeaveIndex);
	
	
}

void bankOpen(){
	
	insertOrderList( evList, BANK_OPEN, 0 );
	
	
	while( !isEmptyOrderList(evList) ){
		
			
		delFirstOrderList(evList, occurTime, type);
		
		if( 0 == type ){
			
			/* TODO (#1#): 这是一个到达事件
 */
			if( occurTime <= BANK_CLOSE ){
				cout << "===============有一名新的顾客到达！===============" << endl;
				cout << "他的到达时间是： " << occurTime << endl << endl << endl; 
				customerArrive();
			}
				
			
			
		}
		else{
			
			cout << "当前有一个顾客从队伍 " << type << "离开" << endl;
			 
			/* TODO (#1#): 这是一个顾客离开的事件 */
			customerLeave();
			
		}
		
	}
	
	
	
}


int main(){
	
	initBank();
	
	bankOpen();
	
	cout << "总共有" << humanNum << "位顾客" << endl;
	cout << "总共花费了" << spentTime << "的时间" << endl;
	cout << "平均花费的时间是：" << spentTime / humanNum << endl; 
	
}

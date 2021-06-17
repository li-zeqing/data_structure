#include <iostream>
#include <string.h>
using namespace std;

//求模式串T的next数组
void get_next(char T[] , int next[]){
	next[0] = -1;
	int i = -1;
	int j = 0;
	while(j < strlen(T)){
		if(i == -1 || T[i] == T[j]){
			i++;
			j++;
			next[j] = i;
		}
		else
			i = next[i];
	}
}



//KMP算法
int Index_kmp(char S[], char T[]){
	int i = 0,j = 0;
	int next[strlen(T)];
	get_next(T , next); //求模式串的next数组
	while(i <strlen(S)){
		if(j == -1 || S[i] == T[j]){
			++i;
			++j;    //继续比较后继字符
		}
		else
			j = next[j];    //模式串向右移动
		if(j == strlen(T))
			return i-strlen(T); //匹配成功
		}
		
		return -1;
}
int main(){
	//主串
	char S[] = "aaabaaaab";
	char T[] = "aaaab";
	int *next = new int[strlen(T)];
	get_next(T,next);
	for(int i =0 ;i<strlen(T);i++){
		cout<<next[i]<<endl;
	}


	cout<<Index_kmp(S, T)<<endl;
	
	
	
}

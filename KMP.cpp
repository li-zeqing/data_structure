#include <iostream>
#include <string.h>
using namespace std;

//��ģʽ��T��next����
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



//KMP�㷨
int Index_kmp(char S[], char T[]){
	int i = 0,j = 0;
	int next[strlen(T)];
	get_next(T , next); //��ģʽ����next����
	while(i <strlen(S)){
		if(j == -1 || S[i] == T[j]){
			++i;
			++j;    //�����ȽϺ���ַ�
		}
		else
			j = next[j];    //ģʽ�������ƶ�
		if(j == strlen(T))
			return i-strlen(T); //ƥ��ɹ�
		}
		
		return -1;
}
int main(){
	//����
	char S[] = "aaabaaaab";
	char T[] = "aaaab";
	int *next = new int[strlen(T)];
	get_next(T,next);
	for(int i =0 ;i<strlen(T);i++){
		cout<<next[i]<<endl;
	}


	cout<<Index_kmp(S, T)<<endl;
	
	
	
}

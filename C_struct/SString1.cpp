//�̶����ȴ�С�洢�ַ��� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 20
typedef struct{
	char data[Maxsize];
	int length=0;
}SString;
void StrAssign(SString &SS, char S[]){
	int i=0;
	for(i=0;S[i]!='\0';i++) {
		SS.data[i]=S[i];
		SS.length++;
	}
	SS.data[i]='\0';
}
bool StrCopy(SString &SS, SString S){
	if(S.length==0) return false;
	int i=0;
	for(i=0;S.data[i]!='\0';i++) {
		SS.data[i]=S.data[i];
	}
	SS.data[i]='\0';
	SS.length=S.length;
	return true;
}
bool StrConcat(SString &SS, SString S1, SString S2){//�ַ������� 
	if(S1.length==0||S2.length==0) return false;
	if(S1.length+S2.length<=Maxsize){//���ýض� 
		for(int i=0;S1.data[i]!='\0';i++) {
			SS.data[i]=S1.data[i];
		}
		for(int j=0;S2.data[j]!='\0';j++){
			SS.data[S1.length+j]=S2.data[j];	
		}
		SS.length=S1.length+S2.length;
	}
	else if(S1.length<Maxsize){//�ض�S2���� 
		for(int i=0;S1.data[i]!='\0';i++) {
			SS.data[i]=S1.data[i];
		}
		for(int j=0;j+S1.length<Maxsize;j++){
			SS.data[S1.length+j]=S2.data[j];	
		}
		SS.length=Maxsize;
	}
	else{
		for(int i=0;i<S1.length;i++) {//�ض�S2 
			SS.data[i]=S1.data[i];
		}
		SS.length=Maxsize;
	}
	return true;
} 
bool SubString(SString &SS, SString S1, int begin, int length){//���Ӵ� 
	if(S1.length<=0||S1.length<begin||S1.length<begin+length) return false;
	int j=0;
	for(int i=begin-1;i<begin+length-1;i++,j++){
		SS.data[j]=S1.data[i];
	}
	SS.data[j]='\0';
	SS.length=length;
	return true;
} 
int Index(SString S, SString T){//SΪ������TΪģʽ��,����ƥ���㷨 
	int i=0,j=0;
	while(i<S.length&&j<T.length){
		if(S.data[i]==T.data[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	} 
	if(j>=T.length){
		return i-T.length+1;
	}
	else return 0;
} 
int KMP_Index(SString S, SString T, int next[]){//KMPƥ���㷨 
	int i=0,j=0;
	while(i<S.length&&j<T.length){
		if(j==-1||S.data[i]==T.data[j]){
			i++;j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>=T.length) return i-T.length+1;
	else return 0;
} 
void Get_next(SString T, int next[]){
	int i=1,j=0;
	next[0]=-1;
	while(i<T.length){
		if(j==-1||T.data[i]==T.data[j]){
			i++;j++;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}	
}
int main(){
	SString SS;
	SString S1;
	StrAssign(SS,"aaaaaaaaab");
	StrAssign(S1,"aaab");
	//int next[S1.length]={-1,0,1,2};
	//int ans=KMP_Index(SS,S1,next);
	//printf("%d",ans);
	int next[S1.length]={0};
	Get_next(S1, next);
	printf("%d",next[3]);
	return 0;
} 

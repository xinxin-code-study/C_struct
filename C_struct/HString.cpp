//动态分配堆分配
#include <stdio.h>
#include <stdlib.h>
#include<iostream> 
using namespace std;
typedef struct{
	char *ch=NULL;
	int length;
}HString;
void StrAssign(HString &T, char *chars){//初始化 
    cout<<(int*)T.ch<<endl;
	if(T.ch!=NULL){
		free(T.ch);
	}
	cout<<2<<endl;
	int i;char *c;
	
	for(i=0,c=chars;*c!='\0';i++,c++);
	 
	T.length=i;
	T.ch=(char *)malloc(sizeof(char)*T.length);
	for(int j=0;j<i;j++){
		T.ch[j]=chars[j];
	}
} 
void StrConcat(HString &T, HString S1, HString S2){//串连接 
	if(T.ch) free(T.ch);
	T.ch=(char *)malloc(sizeof(char)*(S1.length+S2.length));
	for(int i=0;i<S1.length;i++){
		T.ch[i]=S1.ch[i];
	}
	for(int i=0;i<S2.length;i++){
		T.ch[S1.length+i]=S2.ch[i];
	}
	T.length=S1.length+S2.length;
}
bool SubString(HString &T, HString S1, int begin, int length){//求子串 
	if(T.ch) free(T.ch);
	if(begin<1||length<1||S1.length<begin||S1.length<begin+length) return false;
	int j=0;
	for(int i=begin-1,j=0;i<begin-1+length;i++,j++){
		T.ch[j]=S1.ch[i];
	}
	T.ch[j]='\0'; 
	T.length=length;
	return true;
}
int main(){//1.free,2.赋初始化 
	HString T;
	HString S1;
	HString S2;
	char *chars="ffffsddd";
	StrAssign(S1, chars);
	StrAssign(S2, chars);
	StrConcat(T, S1, S2);
	printf("%s", S1.ch);
	SubString(T, S1, 2, 3);
	printf("%s",T.ch);
	
	return 0;
}

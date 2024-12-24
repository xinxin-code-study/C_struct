#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef int ElemType;
//顺序栈 
typedef struct{
	ElemType data[Maxsize];//数组实现 
	int top;
}SqStack; 
void InitStack(SqStack &S){//初始化 
	S.top=-1;
}
bool StackEmpty(SqStack S){//是否为空 
	if(S.top==-1) return true;
	else return false;
}
bool Push(SqStack &S, ElemType e){//进栈 
	
    S.data[++S.top]=e; 
    return true;
}
bool Pop(SqStack &S, ElemType &e){//出栈 
	if(S.top==-1) return false;
	e=S.data[S.top--];
	return true;
}
bool GetTop(SqStack S, ElemType &e){
	if(S.top==-1) return false;
	e=S.data[S.top];
	return true;
}
int main(){//数组实现 
	SqStack S;
	InitStack(S);
	ElemType e1=5;
	Pop(S, e1);
	ElemType e=1;
	GetTop(S, e);
	printf("%d",e);
	return 0;
}

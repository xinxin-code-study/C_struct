#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef int ElemType;
//˳��ջ 
typedef struct{
	ElemType data[Maxsize];//����ʵ�� 
	int top;
}SqStack; 
void InitStack(SqStack &S){//��ʼ�� 
	S.top=-1;
}
bool StackEmpty(SqStack S){//�Ƿ�Ϊ�� 
	if(S.top==-1) return true;
	else return false;
}
bool Push(SqStack &S, ElemType e){//��ջ 
	
    S.data[++S.top]=e; 
    return true;
}
bool Pop(SqStack &S, ElemType &e){//��ջ 
	if(S.top==-1) return false;
	e=S.data[S.top--];
	return true;
}
bool GetTop(SqStack S, ElemType &e){
	if(S.top==-1) return false;
	e=S.data[S.top];
	return true;
}
int main(){//����ʵ�� 
	SqStack S;
	InitStack(S);
	ElemType e1=5;
	Pop(S, e1);
	ElemType e=1;
	GetTop(S, e);
	printf("%d",e);
	return 0;
}

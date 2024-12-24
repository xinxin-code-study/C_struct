#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef int ElemType;
typedef struct{
	ElemType data[Maxsize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue &Q){
	Q.front=Q.rear=0;
}
bool EnQueue(SqQueue &Q, ElemType e){
	if(Q.front==(Q.rear+1)%Maxsize) return false;
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;
	return true; 
}
bool DeQueue(SqQueue &Q, ElemType &e){
	if(Q.front==Q.rear) return false;
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%Maxsize;
	return true; 
}
int main(){
	SqQueue Q;
	InitQueue(Q);
	ElemType e=1;
	EnQueue(Q, e);
	ElemType e1;
	DeQueue(Q, e1);
	printf("%d",e1);
	return 0;
}

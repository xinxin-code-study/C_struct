#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct QNode{//节点 
	ElemType data;
	struct QNode *next;  
}QNode;
typedef struct {//队头队尾 
	QNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){//初始化 
	Q.front=(QNode *)malloc(sizeof(QNode));
	Q.rear=Q.front;
	Q.front->next=NULL; 
}
void DestoryQueue(LinkQueue &Q){//销毁从前往后销毁 
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}
bool EnQueue(LinkQueue &Q, ElemType e){//入队 
	QNode *p=(QNode *)malloc(sizeof(QNode));
	p->next=NULL;
	p->data=e;
	Q.rear->next=p;
	Q.rear=p;
	return true;
}
bool DeQueue(LinkQueue &Q, ElemType &e){//出队 
	if(Q.front==Q.rear) return false;
	QNode *p=Q.front->next;
	if(Q.front->next=Q.rear) Q.rear=Q.front;
	Q.front->next=Q.front->next->next;
	e=p->data;
	free(p);
	return true;
}
bool QueueEmpty(LinkQueue Q){//判断队列是否为空 
	if(Q.front==Q.rear) return true;
	else return false;
}
int main(){
	LinkQueue Q;
	InitQueue(Q);
	ElemType e=5;
	EnQueue(Q, e);
	ElemType e1;
	DeQueue(Q, e1);
	printf("%d",e1);
	DestoryQueue(Q);
	return 0;
}

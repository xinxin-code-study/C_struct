#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct QNode{//�ڵ� 
	ElemType data;
	struct QNode *next;  
}QNode;
typedef struct {//��ͷ��β 
	QNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){//��ʼ�� 
	Q.front=(QNode *)malloc(sizeof(QNode));
	Q.rear=Q.front;
	Q.front->next=NULL; 
}
void DestoryQueue(LinkQueue &Q){//���ٴ�ǰ�������� 
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}
bool EnQueue(LinkQueue &Q, ElemType e){//��� 
	QNode *p=(QNode *)malloc(sizeof(QNode));
	p->next=NULL;
	p->data=e;
	Q.rear->next=p;
	Q.rear=p;
	return true;
}
bool DeQueue(LinkQueue &Q, ElemType &e){//���� 
	if(Q.front==Q.rear) return false;
	QNode *p=Q.front->next;
	if(Q.front->next=Q.rear) Q.rear=Q.front;
	Q.front->next=Q.front->next->next;
	e=p->data;
	free(p);
	return true;
}
bool QueueEmpty(LinkQueue Q){//�ж϶����Ƿ�Ϊ�� 
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

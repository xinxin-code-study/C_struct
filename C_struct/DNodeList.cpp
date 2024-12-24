#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode{
	ElemType data; 
	int freq;
	struct DNode *next,*prior; 
}DNode,*DLinkList;
bool InitDList(DLinkList &L){//��ʼ��ͷ�ڵ� 
	L=(DNode *)malloc(sizeof(DNode));
	L->prior=NULL;
	L->next=NULL;
	return true;
}
int Length(DLinkList L){//���س��� 
	DNode *p=L;
	int i=0;
	while(p->next!=NULL){
		i++;
		p=p->next;
	}
	return i;
}
bool DListInsert(DLinkList &L, int i, ElemType e){//�ڵ�iλ�ò���ڵ� 
	DNode *p=L;
	int j=1;
	if(1>i||i>Length(L)+1) return false;
	while(j<i){//���ڵ� 
		p=p->next;
		j++;
	}
	DNode *q=(DNode *)malloc(sizeof(DNode));
	if(p->next==NULL){//����ĩβ 
		p->next=q;
		q->prior=p;
		q->data=e;
		q->next=NULL;
		
	}
	else{
		q->next=p->next;
		q->prior=p;
		p->next->prior=q;
		p->next=q;
		q->data=e;
	}
	return true;
	/*j=0;while(j<=i){ǰ��ڵ� 
		p=p->next;
		j++;	
	} 
	DNode *q=(DNode *)malloc(sizeof(DNode));
	q->prior=p->prior;
	p->prior->next=q;
	q->next=p;
	p->prior=q;
	q->data=e;
	*/
	}
void PrintDList(DLinkList L){//��ӡ���� 
	DNode *p=L->next;
	int j=1;
	while(j<=Length(L)){
		printf("��%2d���ڵ������Ϊ%3d\n",j,p->data);
		j++;
		p=p->next; 
	}
	if(Length(L)==0) printf("������û�ڵ㣬�����ڵ�\n"); 
}
bool DeleteDList(DLinkList &L, int i, ElemType &e){//ɾ����iλ�õĽڵ� 
	DNode *p=L;
	DNode *q;
	int j=1;
	if(i<1||i>Length(L)) return false;
	while(j<i){//��ɾ�ڵ� 
		p=p->next;
		j++;
	}
	q=p->next;
	if(q==NULL){//ɾ��ĩβ�ڵ㣻 
		p->next=NULL;
		free(q);
	}
	else{
		p->next=q->next;
		q->next->prior=p;
		free(q);
	}
	return true;
} 
DNode *HeadInsertDList(DLinkList &L){//ǰ������ 
	int i;
	scanf("%d",&i);
	while(i){
		DNode *q=(DNode *)malloc(sizeof(DNode));
		if(L->next==NULL){
			L->next=q;
			q->prior=L;
			q->next=NULL;
			scanf("%d",&q->data);
		}
		else{
			L->next->prior=q;
			q->prior=L;
			q->next=L->next;
			L->next=q;
			scanf("%d",&q->data);
		}
		i--;
	} 
	
	return L;
}
DNode *EndInsertDList(DLinkList &L){//β�� 
	DNode *p=L;int i=0;
	while(i<Length(L)){
		p=p->next;
		i++;
	}
	int j;
	scanf("%d",&j);
	while(j){
		DNode *q=(DNode *)malloc(sizeof(DNode));
		p->next=q;
		q->prior=p;
		q->next=NULL;
		p=q;
		scanf("%d",&q->data);
		j--;
	}
	return L;
} 
DNode *Locate(DLinkList &L,ElemType e){//Ƶ������ 
	DNode *p=L->next,*q,*s;
	while(p!=NULL){
		if(p->data==e){
			s=p->next;
			p->freq=(p->freq)+1;
			q=p->prior;
			q->next=p->next;
			p->next->prior=q;
			while(p->freq>=q->freq&&q!=L){
				q=q->prior;
			}
			p->next=q->next;
			p->prior=q;
			q->next=p;
			p->next->prior=p; 
			p=s;
		} 
		else p=p->next;
			
	}
	return L;
	
} 

int main(){
	DLinkList L;
	DLinkList L1;
	ElemType e;
	InitDList(L);
	InitDList(L1);
	L=EndInsertDList(L);
	
	return 0;
}

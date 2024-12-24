#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LoopNode{
	ElemType data;
	struct LoopNode *next,*piror; 
}LoopNode,*LoopLinkList;
typedef struct{//ѭ�������ͷ�ͱ�βָ�� 
	struct LoopNode *front,*rear;
}LLinkList; 
bool InitLoopList(LoopLinkList &L){//��ʼ�� 
	L=(LoopNode *)malloc(sizeof(LoopNode));
	L->next=L;
	L->piror=L; 
	return true;
}
int Length(LoopLinkList L){//ѭ�������� 
	LoopNode *p=L;
	int i=0;
	while(p->next!=L){
		i++;
		p=p->next;
	}
	return i; 
}
LoopNode *EndInsertList(LoopLinkList &L){//��巨���룬˳�� ÿ�β���Lָ���²���ڵ� 
	int i;
	scanf("%d",&i);
	while(i){
		LoopLinkList q=(LoopNode *)malloc(sizeof(LoopNode));
		
		L->next->piror=q;
	    q->next=L->next;
	    L->next=q;
	    q->piror=L;
	    scanf("%d",&q->data);
	    L=L->next;
		
		i--;
	}
	return L;
}
void PrintList(LoopLinkList L){//Lβ�ڵ���� 
	LoopLinkList p=L->next;
	int i=1;
	if(Length(L)==0) printf("������û�нڵ㣬�����ڵ�\n");
	while(i<=Length(L)){
		printf("��%2d���ڵ�����Ϊ%3d\n",i,p->next->data);
		i++;
		p=p->next;
	} 
}
LoopNode *HeadInsertList(LoopLinkList &L){//ǰ�巨����  �����ȴ���1��Lָ�򲻱� 
	int i;
	scanf("%d",&i);
	while(i){
		LoopLinkList q=(LoopNode *)malloc(sizeof(LoopNode));
		if(L->next==L){
			L->next=q;
			q->next=L;
			q->piror=L;
			L->piror=q;
			scanf("%d",&q->data);
			L=q; 
		}
		else{
			LoopLinkList p=L->next;//pÿ��ָ��ͷ�ڵ� 
			q->next=p->next;
			p->next->piror=q;
			p->next=q;
			q->piror=p;
			scanf("%d",&q->data); 
		}
		i--;
	}
	return L;
	
}
 
int main(){
	LoopLinkList L;//LΪβָ�� 
	InitLoopList(L);
	L=HeadInsertList(L);
	PrintList(L);
	printf("%d",Length(L));
	return 0;
}

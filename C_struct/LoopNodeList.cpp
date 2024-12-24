#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LoopNode{
	ElemType data;
	struct LoopNode *next,*piror; 
}LoopNode,*LoopLinkList;
typedef struct{//循环链表表头和表尾指针 
	struct LoopNode *front,*rear;
}LLinkList; 
bool InitLoopList(LoopLinkList &L){//初始化 
	L=(LoopNode *)malloc(sizeof(LoopNode));
	L->next=L;
	L->piror=L; 
	return true;
}
int Length(LoopLinkList L){//循环链表长度 
	LoopNode *p=L;
	int i=0;
	while(p->next!=L){
		i++;
		p=p->next;
	}
	return i; 
}
LoopNode *EndInsertList(LoopLinkList &L){//后插法插入，顺序 每次插入L指向新插入节点 
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
void PrintList(LoopLinkList L){//L尾节点遍历 
	LoopLinkList p=L->next;
	int i=1;
	if(Length(L)==0) printf("该链表没有节点，请插入节点\n");
	while(i<=Length(L)){
		printf("第%2d个节点数据为%3d\n",i,p->next->data);
		i++;
		p=p->next;
	} 
}
LoopNode *HeadInsertList(LoopLinkList &L){//前插法逆序  链表长度大于1，L指向不变 
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
			LoopLinkList p=L->next;//p每次指向头节点 
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
	LoopLinkList L;//L为尾指针 
	InitLoopList(L);
	L=HeadInsertList(L);
	PrintList(L);
	printf("%d",Length(L));
	return 0;
}

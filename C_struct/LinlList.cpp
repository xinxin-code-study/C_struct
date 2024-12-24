#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode,*LinkList;
bool InitList(LinkList &L){//����ͷ�ڵ� 
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	return true;
}
int Length(LinkList L){//���������� 
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
}
LNode *GetElem(LinkList L, int i){//����λ�÷���ָ�� 
	LNode *p=L;
	for(int j=0;j<i&&p!=NULL;j++){
		p=p->next;
	}
	p->data=1;
	return p;
}
LNode *LocateElem(LinkList L, ElemType e){//����ֵ����ָ�� 
	LNode *p=L->next;
	while(p!=NULL){
		if(p->data==e) return p;
		else p=p->next;
	}
	return NULL;
} 
bool ListInsert(LinkList &L, int i, ElemType e){//����iλ��һ���ڵ㣬Ԫ��ֵΪe
	LNode *p=L;
	int j=0;
	if(1>i||i>Length(L)+1) return false;
	while(1<=i&&i<=Length(L)+1&&j<i-1){
		p=p->next;
		j++;
	} 
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->next=p->next;
	p->next=s;
	s->data=e; 
	return true;
}
bool DeleteLNode(LinkList &L, int i, ElemType &e){//ɾ��iλ�õĽڵ� 
	LNode *p=L;
	if(1>i||i>Length(L)) return false;
	int j=0;
	while(j<i-1){
		p=p->next;
		j++;
	}
	LNode *q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
}
void PrintList(LinkList L){//��ӡ���� 
	LNode *p=L->next;
	for(int i=1;i<=Length(L);i++){
		printf("��%2d�ڵ�Ԫ��ֵΪ%3d\n",i,p->data);
		p=p->next;
	}
	printf("\n");
} 
LNode *List_HeadInsert(){//ͷ������ ���� 
	LNode *L;int i;int j=0;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&i);//�ڵ���� 
	while(j<i){
		
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->next=L->next;
		L->next=s;
		scanf("%d",&(s->data));
		j++;
	}
	return L;//ͷ��ڵ�����򣬿���ʵ��������� 
}
LNode *List_EndInsert(){//β������  ˳��  
	LNode *L,*r;int i;int j=0;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	r=L;
	scanf("%d",&i);
	while(j<i){
		LNode *p;
		p=(LNode *)malloc(sizeof(LNode));
		r->next=p;
		r=p;
		scanf("%d",&(p->data));
		j++;
	}
	r->next=NULL;
	return L;
}
void DeleteSameElem(LinkList &L, ElemType e){//ɾ����ͬ��ֵ�ڵ� 
	int j=1;
	LinkList p=L->next;
	while(j<=Length(L)){
		if(p->data==e){
			p=p->next;
			DeleteLNode(L,j,e);
			j--;
		}
		else p=p->next;
		j++;
	}
} 
void DeleteMinElem(LinkList &L, ElemType &e){//ɾ����Сֵ�ڵ� 
	LNode *pre=L,*q=L->next,*t=L->next;int i=Length(L);
	ElemType min=q->data;
	while(i){
		if(min>t->data){
			min=q->data;
			pre=q;
			q=q->next;
		}
		t=t->next;
		i--;
	}
	e=min;
	t=pre->next;
	q=q->next;
	pre->next=q;
	free(t);
} 
void ReverseList(LinkList &L){//����ʱ��O(n),�ռ�O(1)����ͷ���Ͽ�������ͷ�巨���� 
	LNode *p=L->next,*t=L->next;
	while(p->next!=NULL){
		p=p->next;
	}
	while(t!=p){
		L->next=t->next;
		t->next=p->next;
		p->next=t;
		t=L->next; 
	}
}
void Deletes_tElem(LinkList &L, ElemType s, ElemType t){//��same����ԭ������ 
	LNode *pri=L,*p=L->next;
	while(p!=NULL){
		if(p->data>=s&&p->data<=t){
			LNode *q;
			q=p;
		    p=p->next;
		    pri->next=p;
		    free(q);
		}
		else{
			pri=pri->next;
			p=p->next;
		} 
		
	}
} 
LNode *SameElemList(LinkList A, LinkList B){
	LNode *p=A->next;
	LNode *q=B->next;
	LNode *C=(LNode *)malloc(sizeof(LNode));
	C->next=NULL;
	LNode *s=C;
	while(q!=NULL&&p!=NULL){
		if(p->data==q->data){
			LNode *t=(LNode *)malloc(sizeof(LNode));
			t->data=q->data; 
			t->next=NULL;
			s->next=t;
			s=t;
			p=p->next;
			q=q->next;
	 	}
		 else if(q->data>p->data) p=p->next;
		 else q=q->next;	
	}
	return C;
}

void RightMove_i(LinkList &L, int i){
	LNode *p=L->next,*q;
	int j=1;
	while(j<=Length(L)-i){
		p=p->next;
		j++;
	}
	while(p->next!=NULL){
		q=p->next;
		p->next=p->next->next;
		q->next=L->next;
	    L->next=q;
	}
}
bool IsLoop(LinkList L){//�Ƿ�ѭ�� 
	LNode *fast=L->next,*slow=L->next;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) break;
	} 
	if(fast==NULL||fast->next==NULL) return false;
	else return true;
	LNode *p=L->next,*q=fast;
	while(p!=q){
		q=q->next;
		p=p->next;
	}
	return p;
}
int Abs_Elem(ElemType i){//���ؾ���ֵ 
	if(i>0) return i;
	else return -i;
}
void DeleteSameAbsElem(LinkList &L){//ɾ������ֵ��ͬ�Ľڵ� 
	int arr[Length(L)];int i=0;int j=0;int leap=0;
	LNode *q,*p=L;
	for(int t=0;t<Length(L);t++){
		arr[t]=0;
	}
	while(p->next!=NULL){
		arr[i]=Abs_Elem(p->next->data);
		while(j<i){
			if(arr[j]==arr[i]){
				q=p->next;
				p->next=q->next;
				free(q);
				leap=1;
				break;
			}
			j++; 	
		}
		if(leap==1) leap=0;
		else p=p->next;
		i++;
	}
	
}

void insert_sort(LinkList &L){//�������� 
	if(L->next==NULL) return;
	LNode* p=L->next;//pΪ���ź�������ڵ� 
	LNode* q=p->next;//��һ������ڵ� 
	while(q!=NULL){
		if(q->data>=p->data){//ֱ�ӷź��棬������λ�� 
			p=q;
			q=q->next;
		}else{
			p->next=q->next;
			LNode* left=L;
			while(q->data > left->next->data){
				left=left->next;
			}
			q->next=left->next;
			left->next=q; 
			q=p->next;
		}
	} 
} 
LNode *merge(LinkList &left,LinkList &right){
	LNode *head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	LNode *tail=head;
	while(left!=NULL&&right!=NULL){
		if(left->data>=right->data){
			tail->next=right;
			tail=right;
			right=right->next;
			tail->next=NULL;
		}else{
			tail->next=left;
			tail=left;
			left=left->next;
			tail->next=NULL;
		}
	}
	if(left==NULL) tail->next=right;
	else tail->next=left;
	PrintList(head);
	return head->next; 
}
LNode *merge_sort(LinkList &L){//�鲢���� ��� Lͷ�ڵ�,������ 
	if(L==NULL||L->next==NULL) return L;
	LNode *fast=L;
	LNode *slow=L;
	LNode *pre=NULL;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		pre=slow;
		slow=slow->next;
	}
	LNode *mid=pre; 
	mid->next=NULL;
	LNode *left=merge_sort(L);
	LNode *right=merge_sort(slow);
	return merge(left,right);
}
int main(){
	LinkList L;
	InitList(L);
	L=List_EndInsert();
	L->next=merge_sort(L->next);
	PrintList(L);
	return 0;
} 

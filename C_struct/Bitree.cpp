#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	int ltag,rtag;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree CreatBiTree(char *s){//#��������������� 
	BiTree node=NULL;
	static int index=0;
	char ch=s[index];
	index++;
	if(ch!='#'&&ch!='\0'){
		node=(BiTree)malloc(sizeof(BiTNode));
		node->data=ch;
		node->lchild=CreatBiTree(s);
		node->rchild=CreatBiTree(s);
	}
	else return NULL;
	return node;
}
void visit(BiTNode *node){
	printf("%c",node->data);
	return;
}
//�ݹ���������� 
void preOrder(BiTNode *root){//�������������
	if(root!=NULL){
		visit(root);
		preOrder(root->lchild);
		preOrder(root->rchild);
	} 
	else return;
} 
void inOrder(BiTNode *root){//�������������
	if(root!=NULL){
		inOrder(root->lchild);
		visit(root);
		inOrder(root->rchild);
	} 
	else return;
}
void postOrder(BiTNode *root){//������������� 
	if(root!=NULL){
		postOrder(root->lchild);
		postOrder(root->rchild);
		visit(root);
	}
	else return;
}
/*void uilizeStack_inOrder(BiTNode *root){//��ջʵ����������ǵݹ� 
	SqStack S;
	InitStack(S);
	BiTree p=root;
	while(p!=NULL||!StackEmpty(S)){
		if(p!=NULL){
			Push(S,p);
			p=p->lchild;
		}
		else{
			Pop(S,p);visit(p);
			p=p->rchild;
		}
	}
}*/ 
/*void uilizeStack_preOrder(BiTNode *root){//��ջʵ��������� 
	SqStack S;
	InitStack(S);
	BiTree p=root;
	while(p!=NULL||StackEmty(S)){
		if(p!=NULL){
		    visit(p);
			Push(S,p);
			p=p->lchild;		
		}else{
			Pop(S,p);p=p->rchild;
	} 
} */
int HeightBiTree(BiTree root){//���ĸ߶� 
	
	if(root!=NULL){
		int i=HeightBiTree(root->lchild);
		int j=HeightBiTree(root->rchild);
		return i>j?i+1:j+1;
	}
	else return 0;
}
void Thread_in(BiTree &p,BiTree &pre){//���������������� 
	if(p!=NULL){
		Thread_in(p->lchild,pre); 
		if(p->lchild==NULL){
			p->lchild=pre; 
			p->ltag=1;
		} 
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		Thread_in(p->rchild,pre);
	}else return;
}
void Thread_pre(BiTree &p,BiTree &pre){//���������������� 
	if(p!=NULL){
		if(p->lchild==NULL){
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		if(p->ltag==0) Thread_pre(p->lchild,pre); //�ж�lchild�Ƿ�Ϊ���������ӣ�������ظ� 
		Thread_pre(p->rchild,pre);
	} 
}
void CreatInThread(BiTree &p){//��������������������� 
	BiTree pre=NULL;
	if(p!=NULL){
		Thread_in(p,pre);
		pre->rchild=NULL;
		pre->rtag=1;
	}	
} 
BiTree FindBiNode(BiTree B,ElemType e){//����ָ��Ŀ��Ԫ��ֵ����ָ�� 
	 if(B!=NULL){
	 	if(B->data==e) return B;
	    else {
	 		BiTree T=B;
	 		T=FindBiNode(T->lchild,e);
	 		if(T!=NULL) return T;
	 		T=FindBiNode(T->rchild,e);
	 		if(T!=NULL) return T;
	 		
	 	}
	 }
} 
BiTree FindLimRchild(BiTree B){
	BiTree T=B;
	if(B->rtag==0&&B->rchild!=NULL) T=FindLimRchild(B->rchild);
	return T;
}
BiTree Find_in_pre(BiTree B,ElemType e){//������������ڵ��ǰ��
	BiTree p=FindBiNode(B,e);
	if(p->ltag==1&&p->lchild!=NULL) return p->lchild;
	else if(p->lchild==0)  
	
}
void Destory(BiTree root){//���ٶ����� 
	if(root!=NULL){
		Destory(root->lchild);
		Destory(root->rchild);
		free(root);
	}
	return;
}
int main(){
	char *s="124###3##";
	BiTree B=CreatBiTree(s);
	int height=HeightBiTree(B);
	printf("%d",height);
	char e=2;
	BiTree c=FindBiNode(B,e);
	Destory(B); 
	return 0;
} 

#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	int ltag,rtag;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree CreatBiTree(char *s){//#法创建先序二叉树 
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
//递归遍历二叉树 
void preOrder(BiTNode *root){//先序遍历二叉树
	if(root!=NULL){
		visit(root);
		preOrder(root->lchild);
		preOrder(root->rchild);
	} 
	else return;
} 
void inOrder(BiTNode *root){//中序遍历二叉树
	if(root!=NULL){
		inOrder(root->lchild);
		visit(root);
		inOrder(root->rchild);
	} 
	else return;
}
void postOrder(BiTNode *root){//后序遍历二叉树 
	if(root!=NULL){
		postOrder(root->lchild);
		postOrder(root->rchild);
		visit(root);
	}
	else return;
}
/*void uilizeStack_inOrder(BiTNode *root){//用栈实现中序遍历非递归 
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
/*void uilizeStack_preOrder(BiTNode *root){//用栈实现先序遍历 
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
int HeightBiTree(BiTree root){//树的高度 
	
	if(root!=NULL){
		int i=HeightBiTree(root->lchild);
		int j=HeightBiTree(root->rchild);
		return i>j?i+1:j+1;
	}
	else return 0;
}
void Thread_in(BiTree &p,BiTree &pre){//中序构造线索二叉树 
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
void Thread_pre(BiTree &p,BiTree &pre){//先序构造线索二叉树 
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
		if(p->ltag==0) Thread_pre(p->lchild,pre); //判断lchild是否为真正的左孩子，否则会重复 
		Thread_pre(p->rchild,pre);
	} 
}
void CreatInThread(BiTree &p){//创建中序遍历线索二叉树 
	BiTree pre=NULL;
	if(p!=NULL){
		Thread_in(p,pre);
		pre->rchild=NULL;
		pre->rtag=1;
	}	
} 
BiTree FindBiNode(BiTree B,ElemType e){//返回指向目标元素值结点的指针 
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
BiTree Find_in_pre(BiTree B,ElemType e){//查找中序遍历节点的前驱
	BiTree p=FindBiNode(B,e);
	if(p->ltag==1&&p->lchild!=NULL) return p->lchild;
	else if(p->lchild==0)  
	
}
void Destory(BiTree root){//销毁二叉树 
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

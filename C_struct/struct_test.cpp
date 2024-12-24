#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode{
	int weight;
	char data;
	struct BiTNode *lchild=NULL,*rchild=NULL;
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
int max(int a,int b){
	if(a>=b) return a;
	else return b;
}
int Depth(BiTree B){
	int depth=0;
	int lchild_depth=0;
	int rchild_depth=0;
	if(B==NULL) return depth;
	lchild_depth=Depth(B->lchild);
	rchild_depth=Depth(B->rchild);
	depth=1+max(lchild_depth,rchild_depth);
	return depth;
}
int depth1(BiTree B,int depth){
	int d=depth;
	if(B==NULL) return 0;
	else if(B->lchild==NULL&&B->rchild==NULL) return d;
	else return max(depth1(B->lchild,depth+1),depth1(B->rchild,depth+1)); 
}
int WplBiTree(BiTree B,int depth){//WPL树的带权路径长度 
	if(B==NULL) return 0;
	B->weight=1;
	if(B->lchild==NULL&&B->rchild==NULL) return B->weight*depth;
	else return WplBiTree(B->lchild,depth+1)+WplBiTree(B->rchild,depth+1);
}

int main(){
	char *c="ABD#G##E##CF###";
	BiTree B=CreatBiTree(c);
	int depth=Depth(B);
	printf("%d\n",depth); 
	depth=0;
	int Wpl=WplBiTree(B,depth);
	printf("%d",Wpl);
	return 0;
}

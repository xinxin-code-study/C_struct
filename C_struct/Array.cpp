//数组存储矩阵按行优先 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>//va_list ap;va_start(ap,最后一个固定参数);va_arg(ap,参数类型);va_end(ap)每次只能使用一个ap; 
#define Max_dim 3

typedef int ElemType;
typedef struct{
	int dim;//维数 
	ElemType *base;//第一个元素的首地址 
	int *bounds;//第i维元素的个数 
	int *constants;//第i维元素个数加1后,地址的偏移量 
}Array;
bool InitArray(Array &A,int dim,...){//维数dim后为初始n行*m列的矩阵 
	if(dim<1||dim>Max_dim) return false;
	A.dim=dim;
	A.bounds=(int*)malloc(dim*sizeof(int));
	int elemtotal=1;
	va_list ap;
	va_start(ap, dim);
	for(int i=0;i<dim;i++){
		A.bounds[i]=va_arg(ap,int);
		if(A.bounds[i]<0) return false;
		elemtotal*=A.bounds[i];
	}
	va_end(ap);
	A.base=(int *)malloc(elemtotal*sizeof(int));//elemtotal为n*m个元素个数 
	A.constants=(int*)malloc(dim*sizeof(int)); 
	A.constants[dim-1]=1;//跨列顺序存储，每次跨行加该行的元素个数 
	for(int i=dim-2;i>=0;i--){
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];
	}
	return true;
} 
bool DestoryArray(Array &A){
	if(A.base==NULL) return false;
	free(A.base); A.base=NULL;
	if(A.bounds==NULL) return false;
	free(A.bounds); A.bounds=NULL;
	if(A.constants==NULL) return false;
	free(A.constants); A.constants=NULL;  
}
bool Locate(Array A,va_list ap,int &off){//off为相对base的偏移量,va_list ap必须va_start后才能传参，可被其他函数的可变参数列表调用，不能直接使用
	off=0;
	for(int i=0;i<A.dim;i++){
		int ind=va_arg(ap,int);
		if(ind<0||ind>=A.bounds[i]) return false;
		off+=A.constants[i]*ind;
	} 
	va_end(ap);
	return true;
}
bool Value(Array A, ElemType &e,...){//传该位置元素的值给e 
	va_list ap;
	va_start(ap,e);
	int off;
	if(!Locate(A,ap,off)) return false;
	e=*(A.base+off);
	return true;
	 
}
bool Assign(Array &A, ElemType e,...){//赋予该位置的元素的值
	va_list ap;
	va_start(ap,e);
	int off;
	if(!Locate(A,ap,off)) return false;
	*(A.base+off)=e;
	return true;
	
}

int main(){
	Array arr;
	InitArray(arr,2,3,4);//row范围0到n-1,column范围0到m-1 
	int indices[2]={3,4};//位置 
	ElemType a=0,b=5;
	Assign(arr,b,indices[0],indices[1]);
	Value(arr,a,indices[0],indices[1]);
	printf("base的地址： %p\n",arr.base);
	printf("%d",a);
	DestoryArray(arr);
	return 0;
} 

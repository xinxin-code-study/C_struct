//����洢���������� 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>//va_list ap;va_start(ap,���һ���̶�����);va_arg(ap,��������);va_end(ap)ÿ��ֻ��ʹ��һ��ap; 
#define Max_dim 3

typedef int ElemType;
typedef struct{
	int dim;//ά�� 
	ElemType *base;//��һ��Ԫ�ص��׵�ַ 
	int *bounds;//��iάԪ�صĸ��� 
	int *constants;//��iάԪ�ظ�����1��,��ַ��ƫ���� 
}Array;
bool InitArray(Array &A,int dim,...){//ά��dim��Ϊ��ʼn��*m�еľ��� 
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
	A.base=(int *)malloc(elemtotal*sizeof(int));//elemtotalΪn*m��Ԫ�ظ��� 
	A.constants=(int*)malloc(dim*sizeof(int)); 
	A.constants[dim-1]=1;//����˳��洢��ÿ�ο��мӸ��е�Ԫ�ظ��� 
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
bool Locate(Array A,va_list ap,int &off){//offΪ���base��ƫ����,va_list ap����va_start����ܴ��Σ��ɱ����������Ŀɱ�����б���ã�����ֱ��ʹ��
	off=0;
	for(int i=0;i<A.dim;i++){
		int ind=va_arg(ap,int);
		if(ind<0||ind>=A.bounds[i]) return false;
		off+=A.constants[i]*ind;
	} 
	va_end(ap);
	return true;
}
bool Value(Array A, ElemType &e,...){//����λ��Ԫ�ص�ֵ��e 
	va_list ap;
	va_start(ap,e);
	int off;
	if(!Locate(A,ap,off)) return false;
	e=*(A.base+off);
	return true;
	 
}
bool Assign(Array &A, ElemType e,...){//�����λ�õ�Ԫ�ص�ֵ
	va_list ap;
	va_start(ap,e);
	int off;
	if(!Locate(A,ap,off)) return false;
	*(A.base+off)=e;
	return true;
	
}

int main(){
	Array arr;
	InitArray(arr,2,3,4);//row��Χ0��n-1,column��Χ0��m-1 
	int indices[2]={3,4};//λ�� 
	ElemType a=0,b=5;
	Assign(arr,b,indices[0],indices[1]);
	Value(arr,a,indices[0],indices[1]);
	printf("base�ĵ�ַ�� %p\n",arr.base);
	printf("%d",a);
	DestoryArray(arr);
	return 0;
} 

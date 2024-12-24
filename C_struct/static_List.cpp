#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0 //错误 
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2//溢出 
#define INFEASIBLE -1//不可行的
#define INT_MAX 1e9;
typedef int Status;
typedef int ElemType;
#define MaxSize 30
typedef struct{
        int length; 
        ElemType data[MaxSize];
}SqList;
Status SortSqList(SqList &L){//冒泡排序 
	int i;int j;
	ElemType temp;
	for(i=0;i<L.length;i++){
		for(j=0;j<L.length-1;j++){
			if(L.data[j]>L.data[j+1]){
				temp = L.data[j];
				L.data[j] = L.data[j+1];
				L.data[j+1] = temp;
			}
		}
	}
	return OK;
}
Status IntoSqList(SqList &L,ElemType e1,ElemType e2,ElemType e3,ElemType e4){//初始化 
    L.data[0] = e1 ; L.data[1] = e2; L.data[2] = e3;L.data[3] = e4;
    L.length = 4; 
}
Status Length(SqList L){
   return L.length;
}
Status LocateElem(SqList L,ElemType e){//返回元素位置，从0开始 
    int t;
    for(t=0;t<L.length;t++){
        if(L.data[t] == e){
            return t;
        } 
    }
    return ERROR;
}
Status GetElem(SqList L,int i){//返回地址的元素，从1开始 
    if(i<L.length && i>0){
        return L.data[i-1];
    }
    return ERROR;
}
Status ListInsert(SqList &L,int i,ElemType e){//根据地址从1开始，插入元素 
    if(i>0&&i<=L.length+1){
        int t,j;
    j = L.data[i-1];
    L.data[i-1] = e; 
    for(t = i-1;t < L.length;t++){
        L.data[t+1] = j;
        j = L.data[t+1];
    }
    L.length += 1;
    return OK;
    }
    return ERROR;
}
Status ListDelete(SqList &L,int i,ElemType &e){//删除该地址元素从1开始，返回 
    if(i>=1&&i<=L.length){
        int t;
        e = L.data[i-1];
        if(i==L.length) {
            L.length--;
            return OK;
        }
        for(t = i-1;t < L.length-1;t++){
              L.data[t] = L.data[t+1];
        }
        L.length --;
        return OK;
    }
    return ERROR;
}
Status PrintList(SqList L){//打印 
    for(int i = 0;i<L.length;i++){
        printf("%d ",L.data[i]);
    } 
    printf("\n");
    return OK;
}
Status IsEmpty(SqList L){//是否为空 
    if(L.length == 0) return TRUE;
    else return FALSE;   
}
Status DestoryList(SqList &L){
 
    L.length=0; 
    return OK;
}
Status ReMin(SqList &L,ElemType &e){//返回最小值 
    if(L.length==0){
        printf("ERROR\a");
        exit(1); 
    }
    int i;
    int p;
    e = L.data[0];
    for(i=0,p=0;i<L.length;i++){
        if(e>L.data[i]){
            e = L.data[i];
            p = i;
        }
    }
    L.data[p] = L.data[L.length-1];
    L.length--; 
    return OK;
}
Status ReverseList(SqList &L){//逆序 
    int i;
    ElemType t;
    for(i=0;i<L.length/2;i++){
        t = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = t;
    }
    return OK;
} 
Status DeleteSameList(SqList &L,ElemType e){//删除相同元素 
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            ListDelete(L,i+1,e);
            i--;
        } 
    }
    return OK;
}
Status Delete_s_tList(SqList &L,ElemType s,ElemType t){//删除在s-t区间元素值 
       int i;
       ElemType j;
       if(s<t){
           for(i=0;i<L.length;i++){
               if(L.data[i]>=s&&L.data[i]<=t){
                	ListDelete(L,i+1,j);
               	 	i--;
           		}
       		}
       		return OK;
       }
       printf("\a");
       printf("L删除区间错误"); 
       exit(1);
}
SqList AddList(SqList L1,SqList L2){//合并，返回结构体 
	SqList L3;
	int i,j;
	for(i=0;i<L1.length;i++){
		L3.data[i] = L1.data[i];
	}
	for(i=L1.length,j=0;i<L1.length+L2.length;i++,j++){
		L3.data[i] = L2.data[j];
	}
	L3.length=L1.length+L2.length;
	return L3;
} 
ElemType * AddList1(SqList L1,SqList L2){//返回数组合并，有问题！！！！ 
	static ElemType t[6];
	int i,j;
	for(i=0;i<L1.length;i++){
		t[i] = L1.data[i];
	}
	for(i=L1.length,j=0;i<L1.length+L2.length;i++,j++){
		t[i] = L2.data[j];
	}
	
	return t;
} 
Status FindingElem(SqList &L,ElemType e){//升序序列折中查找，//替换 
	SortSqList(L);
	int left=0,right=L.length,mid=(left+right)/2;
	ElemType temp;
	while(left<=right){
		if(e>L.data[mid]) left = mid+1;
		else if(e<L.data[mid]) right = mid-1;
		else break;
		mid=(left+right)/2;
	}
	if(L.data[mid]==e&& mid!=L.length-1){
		temp = L.data[mid];
		L.data[mid] = L.data[mid+1];
		L.data[mid] = temp;	
	}
	int i;
	if(left>right){
		for(i=L.length-1;i>right;i--) L.data[i+1]=L.data[i];
		L.data[i+1] = e;
		L.length++;
	}
} 
Status PrintThreeSame(SqList L,SqList L1,SqList L2){//打印n元组相同的元素值 
	int i,j,t;
	for(i=j=t=0;i<L.length&&j<L1.length&&t<L2.length;){
		static ElemType min;
		if(L.data[i]==L1.data[j]&&L1.data[j]==L2.data[t]){
			printf("%d ",L.data[i]);
			i++;j++;t++;
			
		}else {
			min= L.data[i]>L1.data[j] ? 
			(L1.data[j]>L2.data[t] ? L2.data[t]:L1.data[j]):
			(L.data[i]>L2.data[t] ? L2.data[t]:L.data[i]);
			if(min==L.data[i]) i++;
			else if(min==L1.data[j]) j++;
			else t++;
		}
		
	}
}
Status ReverseList_p(SqList &L,int begin,int end){//逆转区间 
	int i,j;
	ElemType e;
	for(i=begin,j=0;i<=(begin+end)/2;i++,j++){
		e = L.data[i];
		L.data[i] = L.data[end-j];
		L.data[end-j] = e;
	}
	return OK;
}
Status P_ReverseList(SqList &L,int p){//右移 
	ReverseList_p(L,0,L.length-p-1);
	ReverseList_p(L,L.length-p,L.length-1);
	ReverseList_p(L,0,L.length-1);
	return OK;
}
Status MidElemList(SqList L,SqList L1){//中位数 ???
	int s1,d1,m1,s2,d2,m2;
	s1=0;d1=L.length-1;
	s2=0;d2=L1.length-1;
	while(s1!=d1||s2!=d2){
		m1 = (s1+d1)/2;
		m2 = (s2+d2)/2;
		if(L.data[m1]==L1.data[m2]) return L.data[m1];
		if(L.data[m1]<L1.data[m2]){
			if((s1+d1)%2==0){
				s1=m1+1;
				d2=m2;
			}
			else{
				s1=m1+1;
				d2=m2;
			}
		}
		else{
			if((s1+d1)%2==0){
				d1=m1;
				s2=m2;
			}
			else{
				d1=m1;
				s2=m2+1;
			}
		}
	}
	 return L.data[s1]<L1.data[s2]?L.data[s1]:L1.data[s2];
		
	
}
Status Mid_Elem(SqList L,SqList L1){//中位数 
	int i,j;i=j=0;
	int leap=(L.length+L1.length)/2;
	while(i+j<leap-1){
		if(L.data[i]==L1.data[j]) j++;
		else if(L.data[i]>L1.data[j]) j++;
		else i++;
	}
	return L.data[i]>L1.data[j] ? L1.data[j]:L.data[i];
	
}
Status CountsElem(SqList L){//超过一半次数的元素 
	int i,j,count=0;
	ElemType ans=L.data[0]; 
	for(i=1;i<L.length;i++){
		for(j=i;j<L.length;j++){
			if(L.data[j]==ans) count++;
		}
		if(count>L.length/2) return ans;
		else ans=L.data[i];
	}
	return -1;
} 
Status MinIntElem(SqList L){
	int i,leap=1;
	SortSqList(L);
	for(i=0;i<L.length;i++){
		if(L.data[i]<=0||L.data[i]==leap) continue;
		if(L.data[i]>leap) {
			leap++;
			if(L.data[i]>leap) return leap;
		}
	}
}
Status my_abs(ElemType a){
	if(a>0) return a;
	else return -a;
}
Status my_Min(ElemType a, ElemType b, ElemType c){
	if(a<=b&&a<=c) return true;
	else return false; 
}
Status Find_Trip(SqList L, SqList L1, SqList L2){
	int i,j,k,ans;
	i=j=k=0;
	int D_min=INT_MAX;
	while(i<L.length&&j<L1.length&&k<L2.length){
		ans=my_abs(L.data[i]-L1.data[j])+my_abs(L.data[i]-L2.data[k])+my_abs(L1.data[j]-L2.data[k]);
		D_min=D_min>ans?ans:D_min;
		if(my_Min(L.data[i],L1.data[j],L2.data[k])) i++;
		else if(my_Min(L1.data[j],L.data[i],L2.data[k])) j++;
		else k++;	
	}
	return D_min;
}
int main(){
	ElemType e;
	int t;
 	SqList L,L1,L2;
 	IntoSqList(L,3,6,8,20);
 	IntoSqList(L1,0,2,4,15);
 	IntoSqList(L2,1,4,8,10);
	t=Find_Trip(L,L1,L2);
	printf("%d",t);
    return 0; 
}


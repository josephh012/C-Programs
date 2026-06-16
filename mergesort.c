#include<stdio.h>
void merge(int a[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int l[n1],r[n2];
	for(int i=0;i<n1;i++){
		l[i]=a[left+i];
	}
	for(int j=0;j<n2;j++){
		r[j]=a[mid+1+j];
	}
	int i=0,j=0,k=left;
	while(i<n1&&j<n2){
		if(l[i]<=r[j]){
			a[k]=l[i];
			i++;
		}
		else{
			a[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=l[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=r[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		merge(a,left,mid,right);
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
	}
}
void print(int a[],int n){
	printf("sorted array: ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int main(){
	int n,i;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	print(a,n);
}
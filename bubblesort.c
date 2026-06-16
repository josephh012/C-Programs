#include<stdio.h>
void bubble(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
}
int main(){
	int n,i;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("sorted array\n");
	print(a,n);
	bubble(a,n);
	printf("after sorting\n");
	print(a,n);
}
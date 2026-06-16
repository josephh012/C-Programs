#include<stdio.h>
int main(){
	int n,i,j,temp,item;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("sorted array=");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
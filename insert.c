#include<stdio.h>
int main(){
	int n,i,j,key;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("sorted array=");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
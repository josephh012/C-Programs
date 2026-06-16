#include<stdio.h>
int main(){
	int i,j,n,temp,min;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(min!=i){
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
	printf("after sorting=");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
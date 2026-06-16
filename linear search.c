#include<stdio.h>
int main(){
	int n,i,found=-1,search;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the elements to be searched: ");
	scanf("%d",&search);
	for(i=0;i<n;i++){
		if(a[i]==search){
			found=i;
		}
	}
	if(found!=-1){
		printf("element found, at %d th position",found+1);
	}
	else{
		printf("not found :(");
	}
}
	
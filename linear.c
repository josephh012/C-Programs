#include<stdio.h>
int main(){
	int n,i,search,flag=-1;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched: ");
	scanf("%d",&search);
	for(i=0;i<n;i++){
		if(a[i]==search){
			flag=i;
		}
	}
	if(flag!=-1){
		printf("element found at %d th position",flag+1);
	}
	else{
		printf("not found");
	}
}
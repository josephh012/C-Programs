#include<stdio.h>
int binary(int a[],int left,int right,int search){
	while(left<=right){
		int mid=(left+right)/2;
		if(a[mid]==search){
			return mid;
		}
		if(a[mid]<search){
			left=mid+1;
		}
		else{
			left=mid-1;
		}
	}
	return -1;
}
int main(){
	int n,i,search,result;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the element in sorted form: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched: ");
	scanf("%d",&search);
	result=binary(a,0,n-1,search);
	if(result==-1){
		printf("not found");
	}
	else{
		printf("element found at %d th position",result+1);
	}
}
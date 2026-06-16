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
	printf("enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the %d elements in sorted order:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the elements to be searched: ");
scanf("%d",&search);
result=binary(a,0,n-1,search);
if(result==-1){
	printf("not found :'( ");
}
else{
	printf("element found at %d index and at %d th position",result,result+1);
}
}
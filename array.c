#include<stdio.h>
int main(){
	int i,n,top=-1,item,choice=1;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	while(choice!=4){
		printf("\nCHOICES\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
		printf("enter ur choices: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			if(top==n-1){
				printf("stack OVERFLOW!\n");
			}
			else{
				printf("enter the elment to be pushed: ");
				scanf("%d",&item);
				top=top+1;
				a[top]=item;
			}
			break;
			case 2:
			if(top==-1){
				printf("stack underflow!\n");
			}
			else{
				printf("poped element is: %d",a[top]);
				top=top-1;
			}
			break;
			case 3:
			if(top==-1){
				printf("stack underflow!\n");
			}
			else{
				printf("displayed element is\n");
				for(i=0;i<n;i++){
					printf("%d ", a[i]);
				}
			}
			break;
			case 4:
			printf("exiting...");
			break;
			default:
			printf("invalid option pls choose a correct one!");
		}
	}
}
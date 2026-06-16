#include<stdio.h>
int main(){
int n,i,stack[50],choice=1,item,top=-1;
printf("enter the number of elements: ");
scanf("%d",&n);
while(choice!=4){
	printf("enter ur choice\n 1.push\n 2.pop\n 3.display\n 4.exit\n");
	printf("enter ur choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		printf("enter the element need to be pushed: ");
		scanf("%d",&item);
		if(top==n-1){
			printf("overflow\n");
		}
		else{
			top=top+1;
			stack[top]=item;
		}
		break;
		case 2:
		if(top==-1){
			printf("underflow\n");
		}
		else{
			printf("poped element is %d\n",stack[top]);
			top=top-1;
		}
		break;
		case 3:
		if(top==-1){
			printf("stack empty");
		}
		else{
			printf("displayed elements\n");
			for(i=0;i<=top;i++){
				printf("\n");
				printf(" %d ",stack[i]);
			}
		}
		break;
		case 4:
		printf("EXITING...");
		break;
	}
}
}
		
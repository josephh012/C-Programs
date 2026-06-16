#include<stdio.h>
int main(){
	int n,i,item,choice=1,rear=-1,front=-1;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	while(choice!=4){
		printf("\nchoices\n 1.enqueue\n 2.dequeue\n 3.display\n 4.exit\n");
		printf("enter ur choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("enter the element: ");
			scanf("%d",&item);
			if(front==-1&&rear==-1){
				front=0;
				rear=0;
				a[rear]=item;
			}
			else if(((rear+1)%n)==front){
				printf("queue full\n");
			}
			else{
				rear=(rear+1)%n;
				a[rear]=item;
			}
			break;
			case 2:
			if(front==-1&&rear==-1){
				printf("queue empty\n");
			}
			else if(front==rear){
				item=a[front];
				front=-1;
				rear=-1;
			}
			else{
				item=a[front];
				front=(front+1)%n;
			}
			break;
			case 3:
			if(front==-1&&rear==-1){
				printf("queue empty\n");
			}
			else{
				printf("displayed element:\n ");
				for(i=0;i<n;i++){
					printf("ith %d\n",a[i]);
					
				}
				printf("rear %d\n",a[rear]);
			}
			break;
			case 4:
			printf("exiting");
			break;
			default:
			printf("enter a valid option pls");
		}
	}
}
			
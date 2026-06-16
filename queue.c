#include<stdio.h>
int main(){
	int n,choice=1,front=0,rear=-1,item,i;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	int queue[n];
	while(choice!=4){
		printf("\nchoices\n 1.enqueue\n 2.dequeue\n 3.display\n 4.exit\n");
		printf("enter ur choices: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			if(rear==n-1){
				printf("queue full\n");
			}
			else{
				printf("enter the element need to be inserted: ");
				scanf("%d",&item);
				rear=rear+1;
				queue[rear]=item;
			}
			break;
			case 2:
			if(rear<front){
				printf("queue is empty\n");
			}
			else{
				printf("deleted element: %d",queue[front]);
				front=front+1;
				
			}
			break;
			case 3:
			if(rear<front){
				printf("queue is empty\n");
			}
			else{
				printf("displayed elements: ");
				for(i=0;i<n;i++){
					printf("%d ",queue[i]);
				}
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
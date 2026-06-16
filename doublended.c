#include<stdio.h>
int main(){
	int n,i,choice=1,item,front=-1,rear=-1;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	while(choice!=6){
		printf("\nchoices\n 1.enqueue front\n 2.enqueue rear\n 3.dequeue front\n 4.dequeue rear\n 5.display\n 6.exit\n");
		printf("enter ur choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			if((front==0&&rear==n-1)||(front==rear+1)){
				printf("queue full\n");
			}
			else{
				printf("enter the element to be inserted: ");
			    scanf("%d",&item);
				if(front==-1){
					front=rear=0;
				}
				else if(front==0){
					front=n-1;
				}
				else{
					front--;
				}
					a[front]=item;
					printf("%d added to the front of queue",item);
				
			}
			break;
			case 2:
			if((front==0&&rear==n-1)||(front==rear+1)){
				printf("queue full\n");
			}
			else{
				printf("enter the element need to be inserted: ");
				scanf("%d",&item);
				if(front==-1){
					front=rear=0;
				}
				else if(rear==n-1){
					rear=0;
				}
				else{
					rear++;
				}
					a[rear]=item;
					printf("%d added to the end of queue",item);
				
			}
			break;
			case 3:
			if(front==-1){
				printf("queue empty\n");
			}
			else{
				printf("%d deleted from front of queue",a[front]);
				if(front==rear){
					front=rear=-1;
				}
				else if(front==n-1){
					front=0;
				}
				else{
					front++;
				}
			}
			break;
			case 4:
			if(front==-1){
				printf("queue empty\n");
			}
			else{
				printf("%d deleted from the rear of queue",a[rear]);
				if(front==rear){
					front=rear=-1;
				}
				else if(rear==0){
					rear=n-1;
				}
				else{
					rear--;
				}
			}
			break;
			case 5:
			if(front==-1){
				printf("queue empty");
			}
			else{
				printf("displayed elements: ");
				if(rear>=front){
					for(i=front;i<=rear;i++){
						printf("%d ",a[i]);
					}
				}
				else{
					for(i=front;i<n;i++){
						printf("%d ",a[i]);
					}
					for(i=0;i<=rear;i++){
						printf("%d ",a[i]);
					}
				}
			}
			break;
			case 6:
			printf("exiting");
			break;
			default:
			printf("enter a valid optiom pls");
			break;
		}
	}
}
				
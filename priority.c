#include<stdio.h>
int main(){
	int n,choice=1,item,i,front=-1,rear=-1;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	while(choice!=4){
		printf("\nChoices\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n"); 
		printf("Enter your choice: "); 
		scanf("%d", &choice);
		switch(choice){
			case 1:
			if(rear==n-1){
				printf("queue is empty");
			}
			else{
				printf("enter the element: ");
				scanf("%d",&item);
			}
			if(front==-1&&rear==-1){
				front=rear=0;
				a[rear]=item;
			}
			else{
				rear=rear+1;
				int j=rear;
				while(j>=0&&a[j-1]>item){
					a[j]=a[j-1];
					j--;
					a[j]=item;
				}
			}
			break;
			case 2:
			if(front==-1&&rear==-1){
				printf("queue empty");
			}
			else{
				printf("deleted element: ",a[front]);
				if(front==rear){
					front=rear=-1;
				}
				else{
					front++;
				}
			}
			break;
			case 3:
			if(front==-1&&rear==-1){
				printf("queue empty");
			}
			else{
				printf("displayed: ");
				for(i=front;i<=rear;i++){
					printf("%d",a[i]);
				}
			}
			break;
			case 4: printf("Exiting...\n"); 
			break; 
			default: 
			printf("Enter a valid option, please.\n"); 
			break; 
			
		} }  }
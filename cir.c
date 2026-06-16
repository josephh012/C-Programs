#include<stdio.h>
int main(){
	int n,i,front=-1,rear=-1,choice=1,item;
	printf("enter the size: ");
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
				front=rear=0;
				a[rear]=item;
			}
			else if(((rear+1)%n)==front){
				printf("queu full\n");
			}
			else{
				rear=(rear+1)%n;
				a[rear]=item;
			}
			break;
			case 2:
			if(front==-1&&rear==-1){
				printf("empty\n");
			}
			else if(rear==front){
				item=a[front];
				rear=front=-1;
			}
			else{
				item=a[front];
				front=(front+1)%n;
			}
			break;
			case 3:
			if(front==-1&&rear==-1){
				printf("empty\n");
			}
			else{
				printf("displayed element: ");
				for(i=0;i<n;i++){
					printf("%d ",a[i]);
				}
			}
			break;
			case 4:
			printf("exiting");
			break;
		}
	}
}
				
				
			
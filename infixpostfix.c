#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item){
	if(top==MAX-1){
		printf("queue full\n");
		return;
	}
	stack[++top]=item;
}
char pop(){
	if(top<0){
		printf("queue empty");
		return -1;
	}
	return stack[top--];
}
int precedence(char op){
	switch(op){
		case'+':
		case'-':
		return 1;
		case'*':
		case'/':
		return 2;
		case'^':
		return 3;
		default:
		return 0;
	}
}
void infixtopostfix(char infix[],char postfix[]){
	int i=0,j=0;
	char item,x;
	push('(');
	strcat(infix,")");
	item=infix[i];
	while(item!='\0'){
		if(item=='('){
			push(item);
		}
		else if(isalnum(item)){
			postfix[j++]=item;
		}
		else if(item==')'){
			x=pop();
			while(x!='('){
				postfix[j++]=x;
				x=pop();
			}
		}
		else{
			while(precedence(stack[top])>=precedence(item)){
				postfix[j++]=pop();
			}
			push(item);
		}
		item=infix[++i];
	}
	postfix[j]='\0';
}
int main(){
	char infix[MAX],postfix[MAX];
	printf("enter the infix expression: ");
	gets(infix);
	infixtopostfix(infix,postfix);
	printf("postfix expression: %s",postfix);
}
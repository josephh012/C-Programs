#include<stdio.h>
void polyadd(int poly1[],int poly2[],int exp1[],int exp2[],int size1,int size2,int expresult[],int result[]){
	int i=0,j=0,k=0;
	while(i < size1 && j < size2){
		if(exp1[i]>exp2[j]){
			result[k]=poly1[i];
			expresult[k]=exp1[i];
			i++;
		}
		else if(exp1[i]<exp2[j]){
			result[k]=poly2[j];
			expresult[k]=exp2[j];
			j++;
		}
		else{
			result[k]=poly1[i]+poly2[j];
			expresult[k]=exp1[i];
			i++;
			j++;
		}
		k++;
	}
	while(i<size1){
		result[k]=poly1[i];
		expresult[k]=exp1[i];
		i++;
		k++;
	}
	while(j<size2){
		result[k]=poly2[j];
		expresult[k]=exp2[j];
		j++;
		k++;
	}
	printf("resultent polynomial: ");
	for(i=0;i<k;i++){
		printf("%dx^%d",result[i],expresult[i]);
		if(i!=k-1){
			printf("+");
		}
	}
	printf("\n");
}
int main(){
	int size1,size2;
	printf("enter the size of polynomial 1: ");
	scanf("%d",&size1);
	int poly1[size1],exp1[size1];
	printf("enter the terms (coef expo)\n");
	for(int i=0;i<size1;i++){
		scanf("%d%d",&poly1[i],&exp1[i]);
	}
	printf("enter the size of polynomial 2: ");
	scanf("%d",&size2);
	int poly2[size2],exp2[size2];
	printf("enter terms(coef expo)\n");
	for(int i=0;i<size2;i++){
		scanf("%d%d",&poly2[i],&exp2[i]);
	}
	int result[size1+size2],expresult[size1+size2];
	polyadd(poly1,poly2,exp1,exp2,size1,size2,expresult,result);
}
	
			
			
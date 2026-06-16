#include<stdio.h>
#define MAX 100
struct sparsematrix{
	int row;
	int column;
	int value;
};
void createsparse(int row,int column,int matrix[MAX][MAX],struct sparsematrix sparse[]){
	int k=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(matrix[i][j]!=0){
				sparse[k].row=i;
				sparse[k].column=j;
				sparse[k].value=matrix[i][j];
				k++;
			}
		}
	}
	sparse[k].row=-1;
}
void print(struct sparsematrix sparse[]){
	printf("rows\tcolumn\tvalue\n");
	for(int i=0;sparse[i].row!=-1;i++){
		printf("%d\t%d\t%d\n",sparse[i].row,sparse[i].column,sparse[i].value);
	}
}
int main(){
	int row,column,matrix[MAX][MAX];
	printf("enter the number of rows: ");
	scanf("%d",&row);
	printf("enter the number of columns: ");
	scanf("%d",&column);
	printf("enter the elements of the matrix:\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	struct sparsematrix sparse[MAX*MAX];
	createsparse(row,column,matrix,sparse);
	printf("sparse matrix representation:\n");
	print(sparse);
}
#include<stdio.h>

int main(){

int n;
int searchNum;
int quantityNum = 0;

printf("Enter how many numbers: ");
scanf("%d",&n);

int numbers[n];
printf("Enter Numbers\n");
for(int i =0,j =1; i<n; i++){

printf("Number %d: ",j);
scanf("%d", &numbers[i]);
j+=1;
}

printf("Which number you wanna search?: ");
scanf("%d",&searchNum);

for(int i=0; i < n; i++){
if(searchNum == numbers[i]){
quantityNum++;
}
}
printf("Numbers of  occurance: %d\n",quantityNum);


return 0;
}

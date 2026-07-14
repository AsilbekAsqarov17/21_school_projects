#include<stdio.h>


int main(){

int n;
printf("Enter how many numbers: ");
scanf("%d", &n);

int numbers[n];
for(int i = 0; i < n; i++){
scanf("%d", &numbers[i]);
}

printf("Square of numbers: ");
for(int i = 0; i < n; i++){
printf("%d ", numbers[i] * numbers[i]);
}
printf("\n");

return 0;
}

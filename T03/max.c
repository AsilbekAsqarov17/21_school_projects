#include<stdio.h>

int max(int a, int b){
int max_num;

if(a >= b){
max_num = a;
}
else if(a < b){
max_num = b;
}

return max_num;
}

int main(){

int num1;
int num2;

printf("Enter num1: ");
if(scanf("%d", &num1) != 1){
printf("n/a\n");
return 0;
}
printf("Enter num2: ");
if(scanf("%d", &num2) != 1){
printf("n/a\n");
}

printf("Max: %d\n", max(num1, num2));

return 0;
}

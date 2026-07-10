#include<stdio.h>

int main(){

double num1, num2;

if(scanf("%lf %lf", &num1, &num2) != 2){
printf("n/a\n");
}

if((num1*num1 + num2*num2) < 25){
printf("GOTCHA!\n");
}
else{
printf("MISS\n");
}

return 0;
}

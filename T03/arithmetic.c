#include<stdio.h>

int main(){

int num1;
int num2;
int sum;
int difference;
int product;
int quotient;

printf("Enter first num: ");
scanf("%d", &num1);

printf("Enter second num: ");
scanf("%d", &num2);

sum = num1 + num2;
printf("Sum: %d\n", sum);
difference = num1 - num2;
printf("Difference: %d\n", difference);
product = num1 * num2;
printf("Product: %d\n", product);

if(num2 == 0){
printf("Quotient: N/A\n");
}
else{
quotient = num1 / num2;
printf("Quotient: %d\n", quotient);
}

return 0;
}

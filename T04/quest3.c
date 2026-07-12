#include <stdio.h>

int fib_num(int n){

if(n==1 || n ==0){
return n;
}

return fib_num(n-1) + fib_num(n-2);
}


int main(){

int n;
printf("Enter Fibonacci number: ");
if(scanf("%d", &n) != 1){
printf("Wrong Input\n");
return 1;
}

printf("%d's number in Fibonacci sequance is %d\n", n, fib_num(n));

return 0;
}

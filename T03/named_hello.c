#include<stdio.h>

int main(){

int name;
printf("Enter integer: ");
if(scanf("%d", &name) != 1){
printf("Not Available\n");
}
else{
printf("Hello, %d!\n", name);
}

return 0;
}

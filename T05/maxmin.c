#include<stdio.h>

int main(){

int a, b, c;
int max;
int min;

printf("Enter 3 numbers: ");
scanf("%d %d %d", &a, &b, &c);

max = a;
if(a < b){
	if(b < c){
	max = c;
	}
	else{
	max = b;
	}
}
else if(a < c){
max = c;
}
printf("Max number is %d\n", max);

min = b;
if(a < b){
	if(a < c){
	min = a;
	}
	else{
	min= c;
	}
}
else if(c < b){
min = c;
}

printf("Min number is %d\n", min);

return 0;
}

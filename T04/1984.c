#include<stdio.h>

int largest_prime_number(int n){

int largest_prime = -1;

while(n % 2 ==0){
largest_prime = 2;
n /= 2;
}

for(int i = 3; i * i <= n; i += 2){
	while(n % i == 0){
	largest_prime = i;
	n /= i;
	}
}

if(n > 2){
largest_prime = n;
}

return largest_prime;
}

int main(){

int n;
int largest_prime;
printf("Enter number: ");

if(scanf("%d", &n) != 1){
printf("Not Integer!\n");
}
else{
largest_prime = largest_prime_number(n);
printf("Largest prime number of %d is %d\n", n, largest_prime);
}

return 0;
}

#include<stdio.h>

void input(int *numbers,int *length, int *error);

void output(const int *numbers, int length);

void shift_left(int *numbers, int length, int shift);

void reverse(int *numbers, int start, int end);

int main(){

int length;
int error=0;
printf("Enter how many numbers (max=10): ");
if(scanf("%d", &length) != 1 && length <= 10){
printf("Error\n");
return 0;
}

int numbers[length];
input(numbers,&length,&error);

if(error ||length<=0||length>10){
printf("n/a\n");
return 0;
}
int shift;
printf("How many shifts: ");
if(scanf("%d", &shift) != 1 && shift <= 10){
printf("Erorr!\n");
return 0;
}

if(shift >=0){ 
shift_left(numbers, length, shift);
}
else{
shift = length + shift;
shift_left(numbers, length, shift);
}

printf("Shifted %d times:", shift);
output(numbers, length);

}

void reverse(int *numbers, int start, int end){

while(start<end){
int temp = numbers[start];
numbers[start] =numbers[end];
numbers[end] = temp;
start++;
end--;
}

}

void shift_left(int *numbers, int length, int shift){
shift = shift % length;

reverse(numbers, 0, shift-1);
reverse(numbers, shift, length-1);
reverse(numbers, 0, length-1);
}

void shift_right(int *numbers, int length, int shift){

shift = length + shift;
shift_left(numbers, length, shift);

}

void input(int *numbers, int *length, int *error){

for(int i = 0, j=1; i <*length; i++, j++){
	printf("Enter %d: ", j);
	if(scanf("%d",(numbers + i)) != 1){
		*error = 1;
		return;
	}
}

}

void output(const int *numbers,int length){

for(int i= 0; i < length; i++){
printf("%d ", *(numbers + i));

}

}

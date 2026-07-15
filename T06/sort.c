#include<stdio.h>

void bubble_sort(int numbers[], int size){

for(int i =0; i< size - 1; i++){

	for(int j =0; j < size -i - 1; j++){

		if(numbers[j] > numbers[j+1]){
			int temp;
			temp = numbers[j+1];
			numbers[j+1] = numbers[j];
			numbers[j] = temp;
		}
	}
}

}

int main(){

int size;
printf("Enter how many numbers: ");
scanf("%d", &size);

int numbers[size];
printf("Enter numbers:\n");
for(int i = 0, j=1;i < size; i++){

printf("Number %d:", j);
scanf("%d", &numbers[i]);
j++;
}
bubble_sort(numbers, size);
printf("Sorted numbers: ");
for(int i =0; i <size; i++){

printf("%d ", numbers[i]);

} 


return 0;
}

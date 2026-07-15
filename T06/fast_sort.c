#include<stdio.h>

void merge(int numbers[], int left[], int left_size, int right[], int right_size){

int i =0, j =0, k =0;
while(i < left_size && j < right_size){

if(left[i] <= right[j]){
numbers[k] = left[i];
i += 1;
}else{
numbers[k] = right[j];
j += 1;
}
k += 1;
}

while(i<left_size){
numbers[k] = left[i];
k++;
i++;
}

while(j <right_size){
numbers[k] = right[j];
j++;
k++;
}

}

void merge_sort(int numbers[],int length){

if(length < 2){
return;
}

int middle = length / 2;
int left[middle];
int right[middle];

for(int i = 0; i < middle; i++){
left[i] = numbers[i];
}

for(int i = middle; i < length; i++){
right[i- middle] = numbers[i];
}

merge_sort(left, middle);
merge_sort(right, length - middle);

merge(numbers, left, middle, right, length-middle);

}

int main(){

int length;
printf("Enter how many numbers: ");
scanf("%d", &length);

int numbers[length];
printf("Enter Numbers:\n");
for(int i =0,j =1; i < length; i++, j++){
printf("Enter %d: ", j);
scanf("%d", &numbers[i]);
}
merge_sort(numbers, length);

printf("Merge Sorted Numbers: ");
for(int i = 0; i < length; i++){
printf("%d ",numbers[i]);
}

return 0;
}

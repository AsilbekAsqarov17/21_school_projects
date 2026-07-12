#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793246
#define STEPS 42

int main(){

double start = -PI;
double end = PI;
double step = (end -start)/(STEPS -1);

for(int i = 0;i <STEPS; i++){
	double x = start + i*step;
	double y1 = 1.0 / (x * x + 1.0);
	double y2_val = sqrt(x * x + 0.25) - x * x -0.25;
	double y2 = -1.0;
	if(y2_val >= 0.0){
		y2 = sqrt(y2_val);
	}
	double y3 = -1.0;
	if(x != 0.0){
		y3 = 1.0 / (x * x);
	}


printf("%.7f | ", x);
printf("%.7f | ", y1);

if(y2 >= 0.0){
printf("%.7f | ", y2);
}
else{
printf("- |");
}

if(y3 >= 0.0){
printf("%.7f\n", y3);
}
else{
printf("-\n");
}

}

return 0;
}

#include<stdio.h>
#include<math.h>

double fun();
int main(){

double res = fun();
double epsilon = 1E-6;

if(fabs(res) < epsilon){
printf("OK!\n");
}

return 0;
}

double fun(){
return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20));
}

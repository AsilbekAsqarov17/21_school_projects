#include<stdio.h>
#include<math.h>

double calculate(double x){

double term1 = 7e-3 * pow(x, 4);
double term2 = ((22.8 * cbrt(x) - 1e3) * x+3)/(x*x /2.0);
double term3 = x * pow(10.0 + x, (2.0 / x));

return term1 + term2 - term3 - 1.01;

}

int main(){
double x;
printf("Enter float number:");
if(scanf("%lf", &x) != 1){
printf("n/a\n");
}
double y = calculate(x);
printf("%.1f\n", y);

return 0;
}

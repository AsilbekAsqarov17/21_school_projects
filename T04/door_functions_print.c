#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define X_STEPS 42
#define Y_STEPS 21

int main() {
    double start_x = -PI;
    double end_x = PI;
    double step_x = (end_x - start_x) / (X_STEPS - 1);

    double start_y = 0.0;
    double end_y = 1.0;
    double step_y = (end_y - start_y) / (Y_STEPS - 1);

    for (int i = 0; i < X_STEPS; i++) {
        double x = start_x + i * step_x;

        double y1 = 1.0 / (x * x + 1.0);

        double y2_val = sqrt(x * x + 0.25) - x * x - 0.25;
        double y2 = -1.0; 
        if (y2_val >= 0.0) {
            y2 = sqrt(y2_val);
        }

        double y3 = -1.0;
        if (x != 0.0) {
            y3 = 1.0 / (x * x);
        }

        int pos1 = -1, pos2 = -1, pos3 = -1;

        if (y1 >= start_y && y1 <= end_y) {
            pos1 = (int)round((y1 - start_y) / step_y);
        }
        if (y2 >= start_y && y2 <= end_y) {
            pos2 = (int)round((y2 - start_y) / step_y);
        }
        if (y3 >= start_y && y3 <= end_y) {
            pos3 = (int)round((y3 - start_y) / step_y);
        }

        for (int j = 0; j < Y_STEPS; j++) {
            if (j == pos1 || j == pos2 || j == pos3) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

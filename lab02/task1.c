#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double x_start, x_end, dx;

    // Введення параметрів англійською
    printf("Enter Xstart, Xend, dX separated by space: ");
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        fprintf(stderr, "Error: Invalid input.\n");
        return 1;
    }

    // Валідація
    if (x_start >= x_end || dx <= 0.0) {
        fprintf(stderr, "Validation error: Xstart < Xend and dX > 0 required.\n");
        return 1;
    }

    // Шапка таблиці
    printf("+------------+--------------+\n");
    printf("|     X      |     Y(X)     |\n");
    printf("+------------+--------------+\n");

    double eps = 1e-9;
    for (double x = x_start; x <= x_end + eps; x += dx) {
        if (x <= 1.0) {
            double y = cos(x);
            printf("| %10.2lf | %12.4lf |\n", x, y);
        } else if (x <= 4.0) {
            if (fabs(x - 1.0) < eps) {
                printf("| %10.2lf | [Undefined]  |\n", x);
            } else {
                double y = 1.0 / (x - 1.0);
                printf("| %10.2lf | %12.4lf |\n", x, y);
            }
        } else {
            double y = 2.0 * x - 5.0;
            printf("| %10.2lf | %12.4lf |\n", x, y);
        }
    }

    printf("+------------+--------------+\n");

    return 0;
}
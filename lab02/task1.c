#include <stdio.h>
#include <math.h>

int main(void) {
    double xs, xe, dx;

    printf("Enter Xstart, Xend, dX separated by space: ");
    if (scanf("%lf %lf %lf", &xs, &xe, &dx) != 3) {
        fprintf(stderr, "Error: Invalid input.\n");
        return 1;
    }

    if (xs >= xe || dx <= 0.0) {
        fprintf(stderr, "Validation error: Xstart < Xend and dX > 0 required.\n");
        return 1;
    }

    printf("+------------+--------------+\n");
    printf("|     X      |     Y(X)     |\n");
    printf("+------------+--------------+\n");

    const double eps = 1e-9;
    for (int i = 0; ; i++) {
        double x = xs + i * dx;
        if (x > xe + eps) break;

        if (x <= 1.0) {
            printf("| %10.2lf | %12.4lf |\n", x, cos(x));
        } else if (x <= 4.0) {
            if (fabs(x - 1.0) < eps) {
                printf("| %10.2lf | %12s |\n", x, "[Не визначено]");
            } else {
                printf("| %10.2lf | %12.4lf |\n", x, 1.0 / (x - 1.0));
            }
        } else {
            printf("| %10.2lf | %12.4lf |\n", x, 2.0 * x - 5.0);
        }
    }

    printf("+------------+--------------+\n");
    return 0;
}
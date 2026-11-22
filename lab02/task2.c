#include <stdio.h>
#include <math.h>

int main(void) {
    double x, eps;

    // 1. Enter X and eps
    printf("Enter X and eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2 || eps <= 0) {
        printf("Input error!\n");
        return 1;
    }

    double a = 1.0;
    double sum = a;
    int n = 0;
    int count = 1;

    // 2. Loop
    while (fabs(a) >= eps) {
        if (count >= 100000) {
            printf("Iteration limit exceeded!\n");
            break;
        }

        a = a * (x * x) / ((2 * n + 1) * (2 * n + 2));
        sum += a;

        n++;
        count++;
    }

    // 3. Exact and error
    double exact = cosh(x);
    double error = fabs(sum - exact);

    // 4. Print results
    printf("\nCalculated sum : %.8f\n", sum);
    printf("Exact value    : %.8f\n", exact);
    printf("Absolute error : %.8e\n", error);
    printf("Iterations     : %d\n", count);

    return 0;
}
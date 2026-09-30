#include <stdio.h>

int main(void) {
    // Питомий опір міді (ро) = 0.0175 Ом * мм^2 / м
    const double rho = 0.0175; 
    
    double l, S, R;

    // 1. Запит та зчитування довжини провідника l
    printf("Enter wire length l (m): ");
    if (scanf("%lf", &l) != 1) {
        printf("Error: please enter a number.\n");
        return 1;
    }

    // Перевірка на від'ємну або нульову довжину
    if (l <= 0) {
        printf("Error: wire length must be greater than 0!\n");
        return 1;
    }

    // 2. Запит та зчитування площі перерізу S
    printf("Enter cross-section S (mm^2): ");
    if (scanf("%lf", &S) != 1) {
        printf("Error: please enter a number.\n");
        return 1;
    }

    // Перевірка на ділення на нуль та від'ємну площу
    if (S <= 0) {
        printf("Error: cross-section must be greater than 0 (to avoid division by zero)!\n");
        return 1;
    }

    // 3. Обчислення опору за формулою: R = rho * (l / S)
    R = rho * (l / S);

    // 4. Виведення результату з одиницями вимірювання (Ом) та точністю 3 знаки після коми
    printf("\nResistance R = %.3lf Ohm\n", R); //%.3lf — «заглушка» (специфікатор формату):

    return 0;
}
#include <stdio.h>
#include <math.h>

int main(void) {
    double x, eps;

    // 1. Вводимо X та точність eps
    printf("Введіть X та eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2 || eps <= 0) {
        printf("Помилка введення!\n");
        return 1;
    }

    double a = 1.0;     // Перший член ряду (при n=0 це 1)
    double sum = a;     // Сума ряду
    int n = 0;          // Лічильник
    int count = 1;      // Кількість ітерацій

    // 2. Рахуємо суму, поки доданок за модулем більший за eps
    while (fabs(a) >= eps) {
        if (count >= 100000) { // Захист від нескінченного циклу
            printf("Перевищено ліміт ітерацій!\n");
            break;
        }

        // Обчислюємо наступний доданок через попередній
        a = a * (x * x) / ((2 * n + 1) * (2 * n + 2));
        sum += a;

        n++;
        count++;
    }

    // 3. Точне значення через cosh(x) та похибка
    double exact = cosh(x);
    double error = fabs(sum - exact);

    // 4. Вивід результатів
    printf("\nОбчислена сума: %.8f\n", sum);
    printf("Точне значення : %.8f\n", exact);
    printf("Похибка         : %.8e\n", error);
    printf("Ітерацій        : %d\n", count);

    return 0;
}
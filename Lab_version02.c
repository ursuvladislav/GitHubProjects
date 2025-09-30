#include <stdio.h>
#include <math.h>

int main() {
    const double EPS = 1e-12;

    double a, b, c;
    double x1, x2, dx;

    printf("\nВведите a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Ошибка ввода коэффициентов.\n");
        return 1;
    }

    printf("Введите X начальный, X конечный и шаг dX: ");
    if (scanf("%lf %lf %lf", &x1, &x2, &dx) != 3) {
        printf("Ошибка ввода параметров интервала.\n");
        return 1;
    }

    if (fabs(dx) < EPS) {
        printf("Шаг dX не должен быть нулевым.\n");
        return 1;
    }

    if ((x2 - x1) * dx < 0) {
        printf("Знак dX не соответствует направлению от начальному X к конечному X.\n");
        return 1;
    }


    printf("\n%12s\t%12s\n", "X", "F(X)");
    printf("--------------------------------------\n");

    for (double x = x1;
         (dx > 0) ? (x <= x2 + EPS) : (x >= x2 - EPS);
         x += dx)
    {
        double F;

        if (a < 0 && fabs(x) > EPS) {
            F = a * x * x + b * b * x;

        } else if (a > 0 && fabs(x) <= EPS) {
            if (fabs(x - c) <= EPS) {
                printf("%12.5g\t%12s\n", x, "деление на 0");
                continue;
            }
            F = x - (x - a) / (x - c);

        } else {
            if (fabs(c) < EPS) {
                printf("%12.5g\t%12s\n", x, "деление на 0");
                continue;
            }
            F = 1.0 + x / c;
        }

        printf("%12.5g\t%12.5g\n", x, F);
    }

    return 0;
}
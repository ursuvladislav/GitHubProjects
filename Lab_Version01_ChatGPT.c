#include <stdio.h>

int main() {

    printf("\n\n");

    double a, b, c;
    double x1, x2, dx;
    double x, F;

    printf("Введите a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("Введите X начальный, X конечный и  шаг dX: ");
    scanf("%lf %lf %lf", &x1, &x2, &dx);

    printf("\n   X\t\tF(X)\n");
    printf("-------------------------\n");

    for (x = x1; x <= x2; x += dx) {
        if (a < 0 && dx != 0) {
            F = a * x * x + b * b * x;
        } else if (a > 0 && x == 0) {
            F = x - (x-a)/(x-c);
        } else {
            F = 1 + x / c;
        }
        printf("%8.2lf\t%8.2lf\n", x, F);
    }

    printf("\n\n");
    return 0;
}

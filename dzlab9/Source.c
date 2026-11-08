#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ".UTF8");
    char ch;
    int k, cont;

    do {
        printf("Введите символ, из которого будет строиться фигура: ");
        scanf(" %c", &ch);

        printf("Введите размер фигуры k (количество символов в единице длины): ");
        scanf("%d", &k);

        if (k <= 0) {
            printf("Ошибка: размер фигуры должен быть больше нуля.\n");
        }
        else {
            /* По горизонтали: 1 единица = k символов, x от 0 до 4.
               По вертикали: 1 единица = 2k строк (символ в консоли примерно вдвое выше своей ширины), y от 3 до -4. */
            for (int r = 0; r <= 14 * k; r++) {
                double y = 3.0 - (double)r / (2.0 * k);
                for (int c = 0; c <= 4 * k; c++) {
                    double x = (double)c / k;
                    int inside = (x >= 0) &&
                        ((y >= 0 && x * x / 16.0 + y * y / 9.0 <= 1.0) ||
                            (y < 0 && x * x + y * y <= 16.0));
                    putchar(inside ? ch : ' ');
                }
                putchar('\n');
            }
        }

        printf("Продолжить? (Да - введите любое число, Нет - введите 0): ");
        scanf("%d", &cont);
    } while (cont != 0);

    return 0;
}
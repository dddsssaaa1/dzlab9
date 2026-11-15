#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void draw_trapezoid(char ch, int b, int h, int c) {
    double a = (c - b) / 2.0;

    for (int r = 0; r < h; r++) {
        double t = (double)r / (h - 1);
        double left = a * (1.0 - t);
        double width = b + (c - b) * t;
        int xl = (int)(left + 0.5);
        int xr = (int)(left + width - 1 + 0.5);

        for (int x = 0; x <= xr; x++) {
            int on_contour = (x == xl || x == xr || r == 0 || r == h - 1);
            putchar((x >= xl && on_contour) ? ch : ' ');
        }
        putchar('\n');
    }
}

int main(void) {
    setlocale(LC_ALL, ".UTF8");
    char ch;
    int ans;
    int b, h, c;

    do {
        printf("Введите символ, которым рисуется фигура: ");
        scanf(" %c", &ch);

        printf("Введите верхнее основание b: ");
        scanf("%d", &b);

        printf("Введите высоту h (не меньше 2): ");
        scanf("%d", &h);

        printf("Введите нижнее основание c (не меньше b): ");
        scanf("%d", &c);

        if (b <= 0 || h < 2 || c < b) {
            printf("Ошибка: должно выполняться b > 0, h >= 2, c >= b.\n");
        }
        else {
            draw_trapezoid(ch, b, h, c);
        }

        printf("Продолжить? (Да - 1, нет - 0): ");
        scanf("%d", &ans);
    } while (ans != 0);

    return 0;
}
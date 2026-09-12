#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, const char * argv[]) {
    int x, y;
    printf("Введите два числа: ");
    scanf("%d%d", &x, &y);
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}

#include <stdio.h>

int fact(int n){
    int f = 1;
    while (n > 0) {
        f *= n;
        n--;
    }
    return f;
}

int isStrongNumber(int n){
    int sn = 0;
    int temp = n;
    while (temp > 0){
        sn += fact(temp%10);
        temp /= 10;
    }
    if (sn == n){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    int a, b;
    printf("type two numbers: ");
    scanf("%d%d", &a, &b);
    for (int i = a; i<b; i++){
        if (isStrongNumber(i)){
            printf("%d\n", i);
        }
    }
}

#include <stdio.h>

void tree(int n){
    int w = n - 1;
    int d = 1;
    for (int i = 0; i < n; i++){
        for (int i = 0; i < w; i++){
            printf(" ");
        }
        for (int i = 0; i < d; i++){
            printf("*");
        }
        
        printf("\n");
        w -= 1;
        d += 2;
    }
}

int main(int argc, const char * argv[]) {
    tree(6);
    return 0;
}

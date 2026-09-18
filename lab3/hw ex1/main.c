#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n;
    printf("Enter the height of a pyramid: ");
    scanf("%d", &n);
    int c = 1;
    
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n-i-1; k++){
            printf(" ");
        }
        for (int j = 0; j < i+1; j++){
            printf("%d", c++);
        }
        printf("\n");
    }
}

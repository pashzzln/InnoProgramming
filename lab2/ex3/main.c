#include <stdio.h>
#include <string.h>

void tree(int n){
    int d = 0;
    char str[n];
    for (int i = 0; i < n/2; i++){
        d++;
        memset(str, '*', d);
        str[d] = '\0';
        printf("%s\n", str);
    }
    for (int i = 0; i < n/2; i++){
        memset(str, '*', d);
        str[d] = '\0';
        printf("%s\n", str);
        d--;
    }
    
}

void triangleRight(int n){
    int w = n - 1;
    int d = 1;
    for (int i = 0; i < n; i++){
        for (int i = 0; i < d; i++){
            printf("*");
        }
        for (int i = 0; i < w; i++){
            printf(" ");
        }
        
        printf("\n");
        w -= 1;
        d += 1;
    }
}

void rectangle(int n){
    int w = 4;
    for (int i = 0; i < n; i++){
        for (int i = 0; i < w; i++){
            printf("*");
        }
        
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    char choice[20];
    printf("choose rectangle, tree or triangle: ");
    scanf("%s", choice);
    if (strcmp(choice, "rectangle") == 0) {
        rectangle(6);
    } else if (strcmp(choice, "tree") == 0) {
        tree(6);
    } else if (strcmp(choice, "triangle") == 0) {
        triangleRight(6);
    }
    return 0;
}

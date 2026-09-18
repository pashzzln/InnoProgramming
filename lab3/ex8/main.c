#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    
    char* s = &str;
    char* e;
    
    for(int i = 0; i < 100; i++){
        if(str[i] == '\0'){
            e = &str[i-1];
            break;
        }
    }
    
    int l = e - s + 1;
    printf("the length of the string - %d\n", l);
    
    return 0;
}

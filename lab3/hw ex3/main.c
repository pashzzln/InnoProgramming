#include <stdio.h>

int main(int argc, const char * argv[]) {
    char str1[100];
    char str2[100];
    
    printf("Enter string: ");
    scanf("%99s", str1);
    
    char* s1 = str1;
    char* s2 = str2;
    
    while (*s1 != '\0'){
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0';
    
    printf("Old string - %s\n", str1);
    printf("New string - %s\n", str2);
    
    return 0;
}

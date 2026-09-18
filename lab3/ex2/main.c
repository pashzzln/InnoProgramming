#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int count[26] = {0};
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    for (int i = 0; i < strlen(str); i++){
        count[(int)(str[i]) - 97]++;
    }
    
    char let[26];
    for (int i = 0; i < 26; i++) {
        let[i] = (char)(i+97);
    }
    
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 25 - i; j++){
            if (count[j] < count[j+1]){
                int c = count[j]; count[j] = count[j+1]; count[j+1] = c;
                int l = let[j]; let[j] = let[j+1]; let[j+1] = l;
            }

        }
    }
    
    
    
    for (int i = 0; i < 26; i++){
        if (count[i] != 0) {
            printf("%c ", let[i]);
            for (int j = 0; j < count[i]; j ++){
                printf(".");
            }
            printf("\n");
        }
    }
}

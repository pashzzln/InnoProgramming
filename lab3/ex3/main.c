#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char pass[4];
    printf("Enter pass: ");
    scanf("%3s", pass);
    
    int c = 0;
    char guess[4];
    guess[3] = '\0';
    for (int i = 32; i < 127; i++){
        for (int j = 32; j < 127; j++){
            for (int k = 32; k < 127; k++){
                c++;
                guess[0] = (char)i;
                guess[1] = (char)j;
                guess[2] = (char)k;
                if (strcmp(pass, guess) == 0){
                    printf("found – %s\n", guess);
                    printf("attempts – %d\n", c);
                    goto done;
                }
            }
        }
    }
    done: return 0;
    //printf("%s", guess);
}

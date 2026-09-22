#include <stdio.h>

typedef union crypting{
    unsigned long long l;
    char b[8];
} c;

void encrypting(c* un){
    char temp;
    for (int i = 7; i > 0; i -= 2){
        temp = un->b[i];
        un->b[i] = un->b[i-1];
        un->b[i-1] = temp;
    }
    
}

int main(int argc, const char * argv[]) {
    c un;
    
    printf("Enter num: ");
    scanf("%llu", &un.l);
    
    printf("Original message: %llu\n", un.l);
    encrypting(&un);
    printf("Encrypted message: %llu\n", un.l);
    encrypting(&un);
    printf("Decrypted message: %llu\n", un.l);
}

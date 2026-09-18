#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char *str = "adfaskdflakjsdflak";
    char str2[strlen(str)+1];
    strcpy(str2, str);
    printf("%s", str2);
}

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *fp = fopen("output.txt", "w");
    char str[100];
    fgets(str, 100, stdin);
    fputs(str, fp);
    fclose(fp);

    return 0;
}

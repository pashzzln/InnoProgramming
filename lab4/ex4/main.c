#include <stdio.h>

typedef struct recipe{
    
    char name[50];
    int numOfIngridients;
    char ingridients[10][20];
    
} recipe;

void printCookbook(recipe cookbook[], int n){
    for (int i = 0; i < n; i++){
        printf("Recipe %d: %s\n", i+1, cookbook[i].name);
        printf("%d ingridients: \n", cookbook[i].numOfIngridients);
        for (int j = 0; j < cookbook[i].numOfIngridients; j++){
            printf("    • %s\n", cookbook[i].ingridients[j]);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    
    printf("How many recipes: ");
    scanf("%d", &n);
    
    recipe cookbook[n];
    
    for(int i = 0; i < n; i++){
        
        printf("Enter name of recipe: ");
        scanf("%s", cookbook[i].name);
        
        printf("Enter number of ingridients: ");
        scanf("%d", &cookbook[i].numOfIngridients);
        
        for(int j = 0; j < cookbook[i].numOfIngridients; j++){
            printf("Enter ingridient: ");
            scanf("%s", cookbook[i].ingridients[j]);
        }
    }
    
    printCookbook(cookbook, n);
}

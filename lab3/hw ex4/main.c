#include <stdio.h>

void setMatrix (int rows, int cols, int arr[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("[%d][%d] = ", i, j);
            scanf("%d", *(arr + i) + j);
        }
    }
}

void getMatrix (int rows, int cols, int arr[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];
    
    setMatrix(rows, cols, arr);
    getMatrix(rows, cols, arr);
}

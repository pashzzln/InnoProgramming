#include <stdio.h>

int main(int argc, const char * argv[]) {
    int len;
    printf("Enter length: ");
    scanf("%d", &len);
    
    int arr[len];
    
    printf("Enter numbers: ");
    for (int i =  0; i < len; i++){
        
        int a;
        scanf("%d", &a);
        
        arr[i] = a;
    }
    
    
    
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (arr[i] == arr[j]){
                arr[j] = -1;
            }
        }
    }
    
    int new_len = 0;;
    
    for (int i = 0; i < len; i++){
        if (arr[i] != -1){
            new_len += 1;
        }
    }
    
    int new_arr[new_len];
    
    for (int i = 0; i < new_len; i++){
        for (int j = 0; j < len; j++){
            if (arr[j] != -1){
                new_arr[i] = arr[j];
                arr[j] = -1;
                break;
            }
        }
    }
    
    for (int i = 0; i < new_len; i++){
        printf("%d ", new_arr[i]);
    }
}

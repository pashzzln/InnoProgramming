#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    Student,
    TA,
    Professor,
} role;

typedef enum {
    Secondary,
    Bachelor,
    Master,
    PhD,
} degree;

typedef struct moodle_member{
    char name[10];
    role r;
    degree d;
} mm;

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter number of members: ");
    scanf("%d", &n);
    
    mm members[n];
    
    for (int i = 0; i < n; i++){
        
        mm mm;
        
        printf("Enter name of the member: ");
        scanf("%s", mm.name);
        
        char role[10];
        printf("Enter role of the member: ");
        scanf("%s", role);
        if (strcmp(role, "Student") == 0){
            mm.r = 0;
        } else if (strcmp(role, "TA") == 0){
            mm.r = 1;
        } else if (strcmp(role, "Professor") == 0){
            mm.r = 2;
        }
        
        char degree[10];
        printf("Enter degree of the member: ");
        scanf("%s", degree);
        if (strcmp(degree, "Secondary") == 0){
            mm.d = 0;
        } else if (strcmp(degree, "Bachelor") == 0){
            mm.d = 1;
        } else if (strcmp(degree, "Master") == 0){
            mm.d = 2;
        } else if (strcmp(degree, "PhD") == 0){
            mm.d = 3;
        }
        
        members[i] = mm;
    }
    
    for (int i =  0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (members[i].r < members[j].r){
                mm temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
            if (members[i].r == members[j].r){
                if (members[i].d < members[j].d){
                    mm temp = members[i];
                    members[i] = members[j];
                    members[j] = temp;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        printf("Member %s, ", members[i].name);
        switch(members[i].r){
            case 0:
                printf("role - %s, ", "Student");
                break;
            case 1:
                printf("role - %s, ", "TA");
                break;
            case 2:
                printf("role - %s, ", "Professor");
                break;
        }
        switch(members[i].d){
            case 0:
                printf("degree - %s\n", "Secondary");
                break;
            case 1:
                printf("degree - %s\n", "Bachelor");
                break;
            case 2:
                printf("degree - %s\n", "Master");
                break;
            case 3:
                printf("degree - %s\n", "PhD");
                break;
        }
    }
}

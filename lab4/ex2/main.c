#include <stdio.h>

typedef struct exam_day {
    int day;
    char month[9];
    int year;
} exam_day;

typedef struct student {
    char name[20];
    char surname[30];
    int groupNum;
    exam_day date;
} student;

int main(int argc, const char * argv[]) {
    student st;
    exam_day ed;
    
    printf("Enter a name: ");
    scanf("%s", &st.name);
    
    printf("Enter a surname: ");
    scanf("%s", &st.surname);
    
    printf("Enter a group number: ");
    scanf("%d", &st.groupNum);
    
    printf("Enter the day of the exam: ");
    scanf("%d", &st.date.day);
    
    printf("Enter the month of the exam: ");
    scanf("%s", &st.date.month);
    
    printf("Enter the year of the exam: ");
    scanf("%d", &st.date.year);
    
    printf("Student %s %s from group %d will pass the exam on the %d of %s in %d", st.name, st.surname, st.groupNum, st.date.day, st.date.month, st.date.year);
}

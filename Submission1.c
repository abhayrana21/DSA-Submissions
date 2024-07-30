#include <stdio.h>
#include <stdlib.h>

struct student{
    int roll;
    char name[100];
    char divs[100];
    int sub1,sub2,sub3;
    int total;
};

int main() {
    int i,n=10;
    struct student s[n];

    for(i=0; i<n; i++) {
        printf("Enter the details for student %d:\n",i+1);

        printf("Roll no.: ");
        scanf("%d",&s[i].roll);

        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);

        printf("Division: ");
        fgets(s[i].divs, sizeof(s[i].divs), stdin);

        printf("Subject 1 marks: ");
        scanf("%d",&s[i].sub1);

        printf("Subject 2 marks: ");
        scanf("%d",&s[i].sub2);

        printf("Subject 3 marks: ");
        scanf("%d",&s[i].sub3);

        s[i].total = s[i].sub1+s[i].sub2+s[i].sub3;
    }

    printf("\nStudent Information:\n");
    for(i=0; i<n; i++) {
        printf("Roll no.: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Division: %s\n", s[i].divs);
        printf("Subject 1: %d\n", s[i].sub1);
        printf("Subject 2: %d\n", s[i].sub2);
        printf("Subject 3: %d\n", s[i].sub3);
        printf("Total marks: %d\n\n",s[i].total);
    }

    return 0;
}

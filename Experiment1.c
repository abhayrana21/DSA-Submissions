#include <stdio.h>
#include <string.h>

int MAX_STUDENTS = 10;

struct Student {
    int roll_number;
    char name[50];
};

void insertStudent(struct Student students[], int *count);
void deleteStudent(struct Student students[], int *count);
void searchStudent(struct Student students[], int count);
void displayStudents(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert student\n");
        printf("2. Delete student\n");
        printf("3. Search student\n");
        printf("4. Display all students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &count);
                break;
            case 2:
                deleteStudent(students, &count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                displayStudents(students, count);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void insertStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot insert more students. List is full.\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_number);
    printf("Enter name: ");
    scanf("%s", students[*count].name);
    (*count)++;
    printf("Student inserted successfully.\n");
}

void deleteStudent(struct Student students[], int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }
    (*count)--;
    printf("Student deleted successfully.\n");
}

void searchStudent(struct Student students[], int count) {
    int roll_number, i;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_number);
    for (i = 0; i < count; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Student found: Roll Number: %d, Name: %s\n", students[i].roll_number, students[i].name);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_number);
}

void displayStudents(struct Student students[], int count) {
    int i;
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("Roll Number\tName\n");
    printf("-----------\t----\n");
    for (i = 0; i < count; i++) {
        printf("%d\t\t%s\n", students[i].roll_number, students[i].name);
    }
}

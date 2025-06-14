#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int roll;
    char name[50];
    float marks;
    char grade;
} Student;

Student students[MAX];
int count = 0;

void calculateGrade(Student *s) {
    if (s->marks >= 90) s->grade = 'A';
    else if (s->marks >= 75) s->grade = 'B';
    else if (s->marks >= 60) s->grade = 'C';
    else if (s->marks >= 40) s->grade = 'D';
    else s->grade = 'F';
}

void addStudent() {
    if (count >= MAX) {
        printf("Maximum student limit reached.\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);
    printf("Enter name: ");
    scanf(" %[^\n]s", students[count].name);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);
    calculateGrade(&students[count]);
    count++;
    printf("Student added successfully!\n");
}

void modifyStudent() {
    int roll, found = 0;
    printf("Enter roll number to modify: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            calculateGrade(&students[i]);
            printf("Record updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found.\n");
}

void deleteStudent() {
    int roll, found = 0;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            printf("Record deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found.\n");
}

void searchStudent() {
    int roll, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Roll: %d\nName: %s\nMarks: %.2f\nGrade: %c\n",
                   students[i].roll, students[i].name,
                   students[i].marks, students[i].grade);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found.\n");
}

void displayStudents() {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f | Grade: %c\n",
               students[i].roll, students[i].name,
               students[i].marks, students[i].grade);
    }
}

void sortStudentsByRoll() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].roll > students[j + 1].roll) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Sorted by roll number.\n");
}

void sortStudentsByMarks() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Sorted by marks.\n");
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f,%c\n", students[i].roll, students[i].name,
                students[i].marks, students[i].grade);
    }
    fclose(fp);
    printf("Data saved to file.\n");
}

void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File not found. Starting fresh.\n");
        return;
    }
    count = 0;
    while (fscanf(fp, "%d,%[^,],%f,%c\n", &students[count].roll, students[count].name,
                  &students[count].marks, &students[count].grade) == 4) {
        count++;
    }
    fclose(fp);
    printf("Data loaded from file.\n");
}

int main() {
    int choice;
    loadFromFile();
    do {
        printf("\n1. Add Student\n2. Modify Student\n3. Delete Student\n");
        printf("4. Search Student\n5. Display All\n6. Sort by Roll\n7. Sort by Marks\n");
        printf("8. Save to File\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: modifyStudent(); break;
            case 3: deleteStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayStudents(); break;
            case 6: sortStudentsByRoll(); break;
            case 7: sortStudentsByMarks(); break;
            case 8: saveToFile(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 9);
    return 0;
}
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

// Function to add a student
void addStudent(struct Student s[], int *count)
{
    if (*count >= 100)
    {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].roll);

    printf("Enter Name: ");
    scanf("%49s", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student s[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n--- STUDENT RECORDS ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRoll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

// Function to search for a student
void searchStudent(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

// Main function
int main()
{
    struct Student s[100];
    int count = 0, choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(s, &count);
                break;

            case 2:
                displayStudents(s, count);
                break;

            case 3:
                searchStudent(s, count);
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

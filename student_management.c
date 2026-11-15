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
void deleteStudent(struct Student s[], int *count)
{
    int roll, i, j, found = 0;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < *count; i++)
    {
        if (s[i].roll == roll)
        {
            for (j = i; j < *count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            (*count)--;
            found = 1;

            printf("\nStudent deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}
void updateStudent(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf("%49s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nStudent updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}
{
    struct Student s[100];
    int count = 0, choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update student\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");

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
            updateStudent(s, count);
            break;

            case 5:
            deleteStudent(s, count);
            break;
            
            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

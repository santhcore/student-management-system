#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

// Add Student
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

// Display Students
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

// Search Student
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
        printf("\nStudent not found!\n");
}

// Update Student
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
        printf("\nStudent not found!\n");
}

// Delete Student
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
        printf("\nStudent not found!\n");
}

// Save Students
void saveStudents(struct Student s[], int count)
{
    FILE *fp = fopen("students.dat", "wb");

    if (fp == NULL)
    {
        printf("Error saving records!\n");
        return;
    }

    if (fwrite(&count, sizeof(int), 1, fp) != 1 ||
        fwrite(s, sizeof(struct Student), count, fp) != (size_t)count)
    {
        printf("Error writing records!\n");
    }
    else
    {
        printf("Records saved successfully!\n");
    }

    fclose(fp);
}

// Load Students
void loadStudents(struct Student s[], int *count)
{
    FILE *fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        return;
    }

    if (fread(count, sizeof(int), 1, fp) != 1 ||
        *count < 0 || *count > 100)
    {
        *count = 0;
        fclose(fp);
        return;
    }

    if (fread(s, sizeof(struct Student), *count, fp) !=
        (size_t)*count)
    {
        *count = 0;
    }

    fclose(fp);
}

// Main Function
int main()
{
    struct Student s[100];
    int count = 0, choice;

    // Load records at startup
    loadStudents(s, &count);

    printf("Student records loaded: %d\n", count);

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
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
                deleteStudent(s, &count);
                break;

            case 6:
                saveStudents(s, count);
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

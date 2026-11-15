#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

// Function to calculate grade
void calculateGrade(float marks)
{
    if (marks >= 90)
        printf("Grade: A+\n");
    else if (marks >= 80)
        printf("Grade: A\n");
    else if (marks >= 70)
        printf("Grade: B\n");
    else if (marks >= 60)
        printf("Grade: C\n");
    else if (marks >= 50)
        printf("Grade: D\n");
    else if (marks >= 40)
        printf("Grade: E\n");
    else
        printf("Grade: F\n");
}

// Function to add student
void addStudent(struct Student s[], int *count)
{
    int i;

    if (*count >= 100)
    {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].roll);

    if (s[*count].roll <= 0)
    {
        printf("Invalid roll number!\n");
        return;
    }

    for (i = 0; i < *count; i++)
    {
        if (s[i].roll == s[*count].roll)
        {
            printf("Roll Number already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%49s", s[*count].name);

    printf("Enter Marks (0-100): ");
    scanf("%f", &s[*count].marks);

    if (s[*count].marks < 0 || s[*count].marks > 100)
    {
        printf("Invalid marks!\n");
        return;
    }

    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents(struct Student s[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No student records found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRoll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
        calculateGrade(s[i].marks);
    }
}

// Function to search student
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
            calculateGrade(s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to update student
void updateStudent(struct Student s[], int count)
{
    int roll, i, found = 0;
    float newMarks;

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf("%49s", s[i].name);

            printf("Enter New Marks (0-100): ");
            scanf("%f", &newMarks);

            if (newMarks < 0 || newMarks > 100)
            {
                printf("Invalid marks!\n");
                return;
            }

            s[i].marks = newMarks;

            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to delete student
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

            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to save student records
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

// Function to load student records
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

// Function to calculate class average
void calculateAverage(struct Student s[], int count)
{
    int i;
    float total = 0;

    if (count == 0)
    {
        printf("No student records available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total += s[i].marks;
    }

    printf("\nTotal Students: %d\n", count);
    printf("Total Marks: %.2f\n", total);
    printf("Class Average: %.2f\n", total / count);
}

// Function to generate performance report
void performanceReport(struct Student s[], int count)
{
    int i, topper = 0, lowest = 0;

    if (count == 0)
    {
        printf("No student records available!\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (s[i].marks > s[topper].marks)
            topper = i;

        if (s[i].marks < s[lowest].marks)
            lowest = i;
    }

    printf("\n===== PERFORMANCE REPORT =====\n");

    printf("\nTopper:\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Marks: %.2f\n", s[topper].marks);

    printf("\nLowest Scorer:\n");
    printf("Name: %s\n", s[lowest].name);
    printf("Roll Number: %d\n", s[lowest].roll);
    printf("Marks: %.2f\n", s[lowest].marks);
}

// Function to generate individual percentage report
void studentPercentage(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\n===== STUDENT REPORT =====\n");
            printf("Name: %s\n", s[i].name);
            printf("Roll Number: %d\n", s[i].roll);
            printf("Marks: %.2f\n", s[i].marks);
            printf("Percentage: %.2f%%\n", s[i].marks);

            calculateGrade(s[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Main function
int main()
{
    struct Student s[100];
    int count = 0, choice;

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
        printf("7. Calculate Class Average\n");
        printf("8. Student Performance Report\n");
        printf("9. Student Percentage Report\n");

        printf("\nEnter your choice: ");
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

            case 7:
                calculateAverage(s, count);
                break;

            case 8:
                performanceReport(s, count);
                break;

            case 9:
                studentPercentage(s, count);
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

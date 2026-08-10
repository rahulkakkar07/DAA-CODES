#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main()
{
    int n, i, j;
    int topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    /* Input details */
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        printf("Enter marks in 5 subjects:\n");

        for(j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);

            s[i].total = s[i].total + s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        /* Find grade */
        if(s[i].percentage >= 90)
            s[i].grade = 'A';
        else if(s[i].percentage >= 80)
            s[i].grade = 'B';
        else if(s[i].percentage >= 70)
            s[i].grade = 'C';
        else if(s[i].percentage >= 60)
            s[i].grade = 'D';
        else if(s[i].percentage >= 40)
            s[i].grade = 'E';
        else
            s[i].grade = 'F';

        classTotal = classTotal + s[i].percentage;

        /* Find topper */
        if(s[i].percentage > s[topper].percentage)
        {
            topper = i;
        }
    }

    /* Display all student results */
    printf("\n========== STUDENT RESULTS ==========\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    /* Display topper */
    printf("\n========== CLASS TOPPER ==========\n");
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);

    /* Display failed students */
    printf("\n========== FAILED STUDENTS ==========\n");

    for(i = 0; i < n; i++)
    {
        int failed = 0;

        for(j = 0; j < 5; j++)
        {
            if(s[i].marks[j] < 40)
            {
                failed = 1;
            }
        }

        if(failed == 1)
        {
            printf("%s (Roll No: %d)\n", s[i].name, s[i].roll);
        }
    }

    /* Class average */
    printf("\n========== CLASS AVERAGE ==========\n");
    printf("Class Average: %.2f\n", classTotal / n);

    return 0;
}
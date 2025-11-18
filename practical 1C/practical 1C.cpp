#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    char roll_no[10];
    int age;
    float avgMarks;
};

// Bubble Sort Function
void BubbleSort(struct student arr[], int n)
{
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].avgMarks > arr[j + 1].avgMarks)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%s", s[i].roll_no);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    BubbleSort(s, n);

    printf("\nStudents sorted by Average Marks (Ascending order):\n");
    printf("Roll No\t\tName\t\tAge\tAverage Marks\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%s\t\t%d\t%.2f\n", s[i].roll_no, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}


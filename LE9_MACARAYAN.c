#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    int numStudents;
    int age;
    int i;

    char name[100];
    char course[100];
    char line[200];

    printf("Writing Student Database:\n");

    printf("How many students do you want to record? ");
    scanf("%d", &numStudents);
    getchar();

    file = fopen("student_records.txt", "w");

    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    for (i = 1; i <= numStudents; i++) {

        printf("\nStudent %d\n", i);

        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Age: ");
        scanf("%d", &age);
        getchar();

        printf("Enter Course: ");
        fgets(course, sizeof(course), stdin);
        course[strcspn(course, "\n")] = '\0';

        fprintf(file, "Student %d\n", i);
        fprintf(file, "Name: %s\n", name);
        fprintf(file, "Age: %d\n", age);
        fprintf(file, "Course: %s\n", course);
        fprintf(file, "----------------------\n");
    }

    fclose(file);

    printf("\nStudent database successfully saved to file.\n");

    printf("\nReading Student Database:\n\n");

    file = fopen("student_records.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

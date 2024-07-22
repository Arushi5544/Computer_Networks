#include <stdio.h>
#include <string.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void callByValue(struct student_info student) {
    printf("Using call-by-value:\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %02d-%02d-%04d\n", student.age.day, student.age.month, student.age.year);
}

void callByAddress(struct student_info *student) {
    printf("Using call-by-address:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %02d-%02d-%04d\n", student->age.day, student->age.month, student->age.year);
}

void main() {
    struct student_info student;
    student.roll_no = 544;
    strcpy(student.name, "Arushi");
    student.CGPA = 8.84;
    student.age.day = 06;
    student.age.month = 04;
    student.age.year = 2004;
    callByValue(student);
    callByAddress(&student);
}

#include "input.h"
#include "table.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

Student student;
Department department;
Student edit_student;
Department dept_edit;
Course course;
Enrollment enroll;

void studentInput(){
  printf("Enter Student Id: ");
  scanf("%d", &student.student_id);
  printf("Enter Student Name: ");
  scanf("%s", student.name);
  printf("Enter Student Dept: ");
  scanf("%s", student.dept);
}

void departmentInput(){
  printf("Enter Department Id: ");
  scanf("%d", &department.dept_id);
  printf("Enter Dept Name: ");
  scanf("%s", department.dept_name);
}

void courseInput(){
  printf("Enter course code: ");
  scanf("%d",&course.course_code);
  printf("Enter Course Name: ");
  scanf("%s", course.course_name);
  printf("Enter Dept Name: ");
  scanf("%s", course.dept);
}

void enrollInput(){
  printf("Enter enroll id: ");
  scanf("%d", &enroll.enrollId);
  printf("Enter student id: ");
  scanf("%d", &enroll.studentId);
  printf("Enter course code: ");
  scanf("%d",&enroll.courseCode);
}

void changeEntryForStudent(){
  while(getchar() != '\n');
  char buffer[50];

  printf("Enter update Id (Enter to skip): ");
  fgets(buffer, sizeof(buffer), stdin);
  edit_student.student_id = (buffer[0] != '\n') ? atoi(buffer) : 0;
  
  printf("Enter update Name (Enter to skip): ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  strcpy(edit_student.name, buffer);  // Empty string if Enter pressed
  
  printf("Enter update Dept (Enter to skip): ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  strcpy(edit_student.dept, buffer);  // Empty string if Enter pressed
}

void changeEntryForDept(){
  while(getchar()!='\n');
  char buffer[50];

  printf("Enter update Id (Enter to Skip): ");
  fgets(buffer, sizeof(buffer), stdin);
  dept_edit.dept_id = (buffer[0]!='\n')? atoi(buffer): 0;

  printf("Enter update Name (Enter to Skip): ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  strcpy(dept_edit.dept_name, buffer);
}

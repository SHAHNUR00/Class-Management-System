#ifndef TABLE_H
#define TABLE_H

struct Student{
  int student_id;
  char name[10];
  char dept[10];
};

struct Course{
  int course_code;
  char course_name[20];
  char dept[10];
};

struct Department{
  int dept_id;
  char dept_name[10];
};

struct Enrollment{
  int enrollId;
  int studentId;
  int courseCode;
};

extern Student student;
extern Student edit_student;
extern Student editStudent[50];
extern Department department;
extern Department dept_edit;
extern Department editDept[50];
extern Course course;
extern Course course_edit;
extern Course editCourse[50];
extern Enrollment enroll;
extern Enrollment edit_enroll;
extern Enrollment editEnroll[50];

void addTable(const char *tableName);
void displayTable(const char *tableName);
void changeTable(const char *tableName, int id);
void writeTable(const char *tableName, int numIndex);
void deleteTable(const char *tableName, int id);
void sortTable(const char *tableName);
bool isExist(const char *tableName, int id);

#endif

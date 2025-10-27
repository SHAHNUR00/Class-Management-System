#include "table.h"
#include "header.h"
#include "input.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

Student editStudent[50];
Department editDept[50];

bool isExist(const char *tableName, int id){
  char path[20];
  snprintf(path, sizeof(path), "%s.txt", tableName);

  FILE *fp;
  fp = fopen(path, "r");

  if(strcmp(tableName, "student")==0){
    Student s;
    while(fscanf(fp, "%d%s%s", &s.student_id, s.name, s.dept)==3){
      if(s.student_id==id){
        fclose(fp);
        return true;
      }
    }
    fclose(fp);
    return false;
  }
  return false;
}

void sortTable(const char *table){
  FILE *fp;
  fp =fopen(table, "r");
  if(fp == nullptr){
    printf("File is not opened\n");
    return;
  }
  if(strcmp(table,"student.txt")==0){
    int length=0;
    while(fscanf(fp, "%d%s%s",&editStudent[length].student_id, editStudent[length].name, editStudent[length].dept)==3){
      length++;
    }
    fclose(fp);
    std::sort(editStudent, editStudent+length, [](Student a, Student b){
      return a.student_id < b.student_id;
    });
    writeTable(table, length);
  }
}

void addTable(const char *tableName){
  char path[20];
  snprintf(path, sizeof(path), "%s.txt", tableName);

  printf("%s\n", path);

  FILE *fp;
  fp = fopen(path,"a");
  if(fp==nullptr){
    printf("File is not Opened!\n");
    return;
  }
  if(strcmp(tableName, "student")==0){
    studentInput();
    fprintf(fp, "%d\t%s\t%s\n",student.student_id, student.name, student.dept);
    fclose(fp);
    sortTable(path);
    changeHeader(tableName);
  }

  else if(strcmp(tableName, "dept")==0){
    departmentInput();
    fprintf(fp, "%d\t%s\n",department.dept_id, department.dept_name);
    fclose(fp);
    changeHeader(tableName);
  }
  else if(strcmp(tableName, "course")==0){
    courseInput();
    fprintf(fp,"%d\t%s\t%s\n",course.course_code, course.course_name, course.dept);
    fclose(fp);
    changeHeader(tableName);
  }
  else if(strcmp(tableName, "enroll")==0){
    enrollInput();
    fprintf(fp, "%d\t%d\t%d\n",enroll.enrollId, enroll.studentId, enroll.courseCode);
    fclose(fp);
    changeHeader(tableName);
  }
}

void displayTable(const char *tableName){
  char path[20];
  snprintf(path, sizeof(path), "%s.txt", tableName);
  FILE *fp;
  fp = fopen(path, "r");
  if(fp==nullptr){
    printf("File is not opended!\n");
    return;
  }
  if(strcmp(tableName, "student")==0){
    printf("StudentId\tName\tDept\n");
    Student student;
    while(fscanf(fp, "%d%s%s",&student.student_id, student.name, student.dept)==3){
      printf("%d\t\t%s\t%s\n", student.student_id, student.name, student.dept);
    }
  }
  else if(strcmp(tableName, "dept")==0){
    Department department;
    printf("DeptId\tDept_Name\n");
    while(fscanf(fp,"%d%s",&department.dept_id,department.dept_name)==2){
      printf("%d\t%s\n", department.dept_id, department.dept_name);
    }
  }
  else if(strcmp(tableName, "course")==0){
    Course course;
    printf("%-10s %-20s %-10s\n", "Code", "Name", "Dept");
    while(fscanf(fp, "%d%s%s",&course.course_code, course.course_name, course.dept)==3){
      printf("%-11d%-21s%-12s\n",course.course_code, course.course_name, course.dept);
    }
  }
  else if (strcmp(tableName, "enroll")==0){
    Enrollment enrollment;
    printf("%-10s %-10s %-10s\n","enrollId","studenId","course Code");
    while(fscanf(fp, "%d%d%d",&enrollment.enrollId, &enrollment.studentId, &enrollment.courseCode)==3){
      printf("%-10d %-10d %-10d\n",enrollment.enrollId, enrollment.studentId, enrollment.courseCode);
    }
  }
  fclose(fp);
}

void changeTable(const char *tableName, int id){
  char path[20];
  snprintf(path, sizeof(path), "%s.txt", tableName);

  FILE *fp;
  fp = fopen(path,"r");
  if(fp==nullptr){
    printf("File is not opened!\n");
    return;
  }
  if(strcmp(tableName, "student")==0){
    int _index=0;
    Student student;
    while(fscanf(fp, "%d%s%s",&student.student_id, student.name, student.dept)==3){
      if(student.student_id == id){
        changeEntryForStudent();
        if(edit_student.student_id!=0){
          student.student_id=edit_student.student_id;
        }
        if(strcmp(edit_student.name,"")!=0){
          strcpy(student.name, edit_student.name);
        }
        if(strcmp(edit_student.dept,"")!=0){
          strcpy(student.dept,edit_student.dept);
        }
      }
      editStudent[_index].student_id = student.student_id;
      strcpy(editStudent[_index].name, student.name);
      strcpy(editStudent[_index].dept, student.dept);
      _index++;
    }
    writeTable(path, _index);
  }
  else if(strcmp(tableName, "dept")==0){
    int _index=0;
    Department dept;
    while(fscanf(fp, "%d%s",&dept.dept_id, dept.dept_name)==2){
      if(dept.dept_id == id){
        changeEntryForDept();
        if(dept_edit.dept_id!=0){
          dept.dept_id = dept_edit.dept_id;
        }
        if(strcmp(dept_edit.dept_name, "")!=0){
          strcpy(dept.dept_name, dept_edit.dept_name);
        }
      }
      editDept[_index].dept_id = dept.dept_id;
      strcpy(editDept[_index].dept_name, dept.dept_name);
      _index++;
    }
    writeTable(path, _index);
  }
  fclose(fp);
}

void deleteTable(const char *tableName, int id){
  char path[20];
  snprintf(path, sizeof(path), "%s.txt",tableName);
  FILE *fp;
  fp = fopen(path, "r");
  if(fp==nullptr){
    printf("File is not opened!\n");
    return;
  }
  FILE *file;
  file = fopen("temp.txt","w");
  if(file==nullptr){
    printf("File is not opened\n");
    return;
  }
  if(strcmp(tableName, "student")==0){
    Student s;
    while(fscanf(fp, "%d%s%s",&s.student_id, s.name, s.dept)==3){
      if(s.student_id==id) continue;
      fprintf(file, "%d\t%s\t%s\n", s.student_id, s.name, s.dept);
    }
    rename("temp.txt",path);
    fclose(file);
    fclose(fp);
    deleteTable("enroll",id);
  }
  else if(strcmp(tableName, "enroll")==0){
    Enrollment e;
    while(fscanf(fp, "%d%d%d", &e.enrollId, &e.studentId, &e.courseCode)==3){
      if(e.studentId == id) continue;
      fprintf(file, "%d\t%d\t%d\n",e.enrollId, e.studentId, e.courseCode);
    }
    rename("temp.txt",path);
    fclose(file);
    fclose(fp);
  }
}

void writeTable(const char *tableName, int numIndex){
  FILE *fp;
  fp = fopen(tableName, "w");
  if(fp == nullptr){
    printf("File is not opened!\n");
    return;
  }
  if(strcmp(tableName, "student.txt")==0){
    for(int i=0; i<numIndex; i++){
      fprintf(fp, "%d\t\t%s\t%s\n",editStudent[i].student_id, editStudent[i].name, editStudent[i].dept);
    }
  }

  else if(strcmp(tableName, "dept.txt")==0){
    for(int i=0; i<numIndex; i++){
      fprintf(fp,"%d\t%s\n",editDept[i].dept_id, editDept[i].dept_name);
    }
  }
  fclose(fp);
}

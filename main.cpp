#include "table.h"
#include <cstdio>

void printMenue(const char *table){
  printf("1. Add new %s in table\n",table);
  printf("2. Display %s table\n",table);
  printf("3. Edit any row in %s table\n",table);
  printf("4. Delete a row from %s table\n", table);
}

void changeId(const char *table){
  int id;
  printf("Enter the Id: ");
  scanf("%d",&id);
  if(isExist(table, id)){
    changeTable(table, id);
  }
  else{
    printf("%s does not exists!\n", table);
  }
}

void deleteId(const char *table){
  int id;
  printf("Enter the Id: ");
  scanf("%d",&id);
  if(isExist(table, id)){
    deleteTable(table, id);
  }
  else{
    printf("%s does not exists!\n", table);
  }
}

int main(){
  int table;
  int operation;
  printf("1. Student\n");
  printf("2. Dept\n");
  printf("3. Course\n");
  printf("4. Enrollment\n");
  printf("Which table do you want: ");
  scanf("%d", &table);
  if(table==1){
    printMenue("student");
    printf("Enter the operation: ");
    scanf("%d", &operation);
    if(operation==1) addTable("student");
    else if(operation==2) displayTable("student");
    else if(operation==3){
      changeId("student");
    }
    else if(operation==4){
      deleteId("student");
    }
  }
  else if(table==2){
    printMenue("dept");
    printf("Enter the operation: ");
    scanf("%d", &operation);
    if(operation==1) addTable("dept");
    else if(operation==3){
      changeId("dept");
    }
    else if(operation==4){
      deleteId("dept");
    }
  }
  else if(table==3){
    printMenue("course");
    printf("Enter the operation: ");
    scanf("%d", &operation);
    if(operation==1) addTable("course");
    else if(operation==2) displayTable("course");
  }
  else if(table==4){
    printMenue("enrollment");
    printf("Enter the operation: " );
    scanf("%d",&operation);
    if(operation==1) addTable("enroll");
    else if(operation==2) displayTable("enroll");
  }
}

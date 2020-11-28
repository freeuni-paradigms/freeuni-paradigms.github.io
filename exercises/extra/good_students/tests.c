#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "good_students.h"


#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

void* AddStudent(char* student, unsigned char score, void* address, size_t* address_length){
  // name  +  '\0'  +  score
  int addition = strlen(student) + 1 + 1 ;
  int start_index = *address_length;               // same + addition + ending
  void* result = realloc(address, sizeof(char) * (*address_length + addition + 1));

  strcpy((char*)result + start_index, student);
  memcpy((char*)result + start_index + strlen(student) + 1, &score, 1);
  strcpy((char*)result + start_index + strlen(student) + 1 + 1, "");

  *address_length += addition;

  return result;
}

bool Test1(){
    void* ptr = NULL;
    size_t length = 0;

    ptr = addStudent("Nika", 156, ptr, &length);
    ptr = addStudent("Luka", 90, ptr, &length);
    ptr = addStudent("Kosta", 150, ptr, &length);
    
    char* result = GoodStudents(ptr);

    return result != NULL && strcmp(result, "Nika Kosta") == 0;
}

bool Test2(){
    void* ptr = NULL;
    size_t length = 0;

    ptr = addStudent("David", 120, ptr, &length);
    ptr = addStudent("James", 158, ptr, &length);
    ptr = addStudent("George", 255, ptr, &length);
    
    char* result = GoodStudents(ptr);

    return result != NULL && strcmp(result, "James George") == 0;
}

bool Test3(){
    void* ptr = NULL;
    size_t length = 0;

    ptr = addStudent("Lika", 2, ptr, &length);
    ptr = addStudent("Gvantsa", 5, ptr, &length);
    ptr = addStudent("Charlie", 5, ptr, &length);
    ptr = addStudent("Elene", 124, ptr, &length);
    ptr = addStudent("Jumberi", 56, ptr, &length);
    
    char* result = GoodStudents(ptr);

    return result != NULL && strcmp(result, "") == 0;
}


int main(){
  Test("Test1 ", Test1);
  Test("Test2 ", Test2);
  Test("Test3 ", Test3);
  return 0;
}
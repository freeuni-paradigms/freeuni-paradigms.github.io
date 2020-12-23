#include <stdbool.h>

typedef struct {
  int id;
  char* first_name;
  char* last_name;
  int score;
} Student;

typedef struct {
  int n;
  void* students;
} StudentList;

bool CheckPassed(void* student) {
  return ((Student*)student)->score > 40;
}

int NumPassedThreshold(StudentList list) {
  int count = 0;
  for (int i = 0; i < list.n; ++i) {
    if (CheckPassed((Student*)list.students + i)) {
      ++count;
    }
  }
  return count;
}

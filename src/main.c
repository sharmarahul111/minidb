#include<stdio.h>
#include "schema.c"
#include "input.h"

int main(){
  Field *field = {
    {1, INT, 24},
    {1, FLOAT, 55.66},
    {5, STRING, "Hello"}
  }
  Row row = {3, field};
  Column col1 = {2, "ID"};
  Column col2 = {5, "point"};
  Column col3 = {4, "Text"};
  Table table = {3,3};
  welcomeMessage();

  return 0;
}

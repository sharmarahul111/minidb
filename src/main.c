#include<stdio.h>
#include "schema.h"
#include "input.h"
#include "output.h"

int main(){
  Data d1, d2, d3;
  d1.i = 24;
  d2.f = 55.66;
  d3.c = "Hello";
  Field field[] = {
    {1, INT, d1},
    {1, FLOAT, d2},
    {5, STRING, d3}
  };
  Row row[] = {
    {3, field}
  };
  Column col[] = {
    {2, "ID", INT},
    {5, "point", FLOAT},
    {4, "Text", STRING}
  };
  Table table = {3,1, col, row};
  // welcomeMessage();
  printTable(table);

  return 0;
}

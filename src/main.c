#include<stdio.h>
#include "schema.h"
#include "input.h"

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
  Table table = {3,3, col, row};
  // welcomeMessage();
  printf("%d\n", table.row[0].field[0].data.i);
  printf("%f\n", table.row[0].field[1].data.f);
  printf("%s\n", table.row[0].field[2].data.c);
  printf("\n");
  printf("%s\n", table.column[0].name);
  printf("%s\n", table.column[1].name);
  printf("%s\n", table.column[2].name);

  return 0;
}

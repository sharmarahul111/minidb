#include <stdlib.h>
#include <string.h>
#include "schema.h"
#include "dummy_table.h"
void dummy_table(Table *table){
  int column_count = 3;
  int row_count = 4;
  int field_count = 3;
  Column *cp;
  Row *rp;
  Row **rpp;
  Field *fp;
  cp = (Column *) malloc(column_count * sizeof(Column));
  rpp = (Row **) malloc(row_count * sizeof(Row *));
  fp = (Field *) malloc(field_count * row_count * sizeof(Field));

  cp[0] = (Column) {"ID", INT};
  cp[1] = (Column) {"Float", FLOAT};
  cp[2] = (Column) {"Text", CHAR32};


  char *names[] = {"Mark", "Jake", "David", "Sully"};
  float points[] = {34.65, 240.63, 473.34, 412.64};
  int i;
  for (i=0;i<row_count;i++) {
    fp[i*field_count+0] = (Field) {1, INT, (Data) {.i32 = i+1}};
    fp[i*field_count+1] = (Field) {1, FLOAT, (Data) {.f32 = points[i]}};
    fp[i*field_count+2] = (Field) {32, CHAR32, (Data) {.s = NULL}};
    fp[i*field_count+2].type = CHAR32;
    strcpy(fp[i*field_count+2].data.c32, names[i]);

    rp = (Row *) malloc(sizeof(Row));
    *rp = (Row) {fp+i*field_count};
    rpp[i] = rp;
  }
  *table = (Table) {column_count, row_count, cp, rpp, "Table o1"};
}


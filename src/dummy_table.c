#include <stdlib.h>
#include "schema.h"
#include "dummy_table.h"
Table* dummy_table(void){
  int table_count = 1;
  int column_count = 3;
  int row_count = 4;
  int field_count = 3;
  Table *tp;
  Column *cp;
  Row *rp;
  Row **rpp;
  Field *fp;
  tp = (Table *) malloc(table_count * sizeof(Table));
  cp = (Column *) malloc(column_count * sizeof(Column));
  rp = (Row *) malloc(row_count * sizeof(Row));
  rpp = (Row **) malloc(row_count *sizeof(Row *));
  fp = (Field *) malloc(field_count * row_count * sizeof(Field));

  cp[0] = (Column) {2, "ID", INT};
  cp[1] = (Column) {5, "Float", FLOAT};
  cp[2] = (Column) {4, "Text", STRING};


  char *names[] = {"Mark", "Jake", "David", "Sully"};
  float points[] = {34.65, 240.63, 473.34, 412.64};
  int i;
  for (i=0;i<row_count;i++) {
    fp[i*field_count+0] = (Field) {1, INT, (Data) {.i = i+1}};
    fp[i*field_count+1] = (Field) {1, FLOAT, (Data) {.f = points[i]}};
    fp[i*field_count+2] = (Field) {10, STRING, (Data) {.c = names[i]}};

    rp[i] = (Row) {field_count, fp+i*field_count};
    rpp[i] = &rp[i];
  }
  tp[0] = (Table) {column_count, row_count, cp, rpp};
  return tp;
}


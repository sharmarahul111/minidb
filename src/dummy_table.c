#include<stdlib.h>
#include "schema.h"
#include "dummy_table.h"
Table* dummy_table(){
  int table_count = 1;
  int column_count = 3;
  int row_count = 1;
  int field_count = 3;
  Table *tp;
  Column *cp;
  Row *rp;
  Field *fp;
  tp = (Table *) malloc(table_count*sizeof(Table));
  cp = (Column *) malloc(column_count*sizeof(Column));
  rp = (Row *) malloc(row_count*sizeof(Row));
  fp = (Field *) malloc(field_count*sizeof(Field));

  Data d1, d2, d3;
  d1.i = 24;
  d2.f = 55.66;
  d3.c = "Hello";

  fp[0] = (Field) {1, INT, d1};
  fp[1] = (Field) {1, FLOAT, d2};
  fp[2] = (Field) {5, STRING, d3};

  cp[0] = (Column) {2, "ID", INT};
  cp[1] = (Column) {5, "point", FLOAT};
  cp[2] = (Column) {4, "Text", STRING};

  rp[0] = (Row) {3, fp};

  tp[0] = (Table) {3,1, cp, rp};
  return tp;
}

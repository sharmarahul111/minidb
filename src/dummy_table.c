#include <stdlib.h>
#include <string.h>
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
  // char *ch;
  tp = (Table *) malloc(table_count * sizeof(Table));
  cp = (Column *) malloc(column_count * sizeof(Column));
  rpp = (Row **) malloc(row_count * sizeof(Row *));
  fp = (Field *) malloc(field_count * row_count * sizeof(Field));

  cp[0] = (Column) {2, "ID", INT};
  cp[1] = (Column) {5, "Float", FLOAT};
  cp[2] = (Column) {4, "Text", CHAR32};


  char *names[] = {"Mark", "Jake", "David", "Sully"};
  float points[] = {34.65, 240.63, 473.34, 412.64};
  int i;
  for (i=0;i<row_count;i++) {
    // ch = (char *) malloc(20*sizeof(char));
    // strcpy(ch, names[i]);
    fp[i*field_count+0] = (Field) {1, INT, (Data) {.i = i+1}};
    fp[i*field_count+1] = (Field) {1, FLOAT, (Data) {.f = points[i]}};
    fp[i*field_count+2] = (Field) {32, CHAR32, (Data) {.c = NULL}};
    fp[i*field_count+2].type = CHAR32;
    strcpy(fp[i*field_count+2].data.char32, names[i]);

    rp = (Row *) malloc(sizeof(Row));
    *rp = (Row) {fp+i*field_count};
    rpp[i] = rp;
  }
  tp[0] = (Table) {column_count, row_count, cp, rpp};
  return tp;
}


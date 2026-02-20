#include <stdio.h>
#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "dummy_table.h"
#include "query.h"

int main(void){
  // welcomeMessage();
  Row *rp;
  Table *table = dummy_table();
  printTable(table);

  rp = (Row *) malloc(sizeof(Row));
  *rp = (Row) {3, (Field []){
    (Field) {1, INT, (Data) {.i = 999}},
    (Field) {1, FLOAT, (Data) {.f = 444.44}},
    (Field) {10, STRING, (Data) {.c = "New User"}}

  }};
  table_insert(table, rp);
  printTable(table);


  return 0;
}

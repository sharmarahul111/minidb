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
  *rp = (Row) {(Field []){
    (Field) {1, INT, (Data) {.i = 999}},
    (Field) {1, FLOAT, (Data) {.f = 444.44}},
    (Field) {10, STRING, (Data) {.c = "New User"}}

  }};
  table_insert(table, rp);
  printf("\nAfter Insert:\n");
  printTable(table);
  table_delete(table, &table->row[1]);
  printf("\nAfter Delete:\n");
  printTable(table);
  printf("\nAfter Update:\n");
  table_update(table, &table->row[0], table->row[1]);
  printTable(table);


  return 0;
}

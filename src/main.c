#include <stdio.h>
#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "dummy_table.h"
#include "query.h"
INPUT_MODE MODE = MAIN_MENU;
int main(void){
  int choice;
  Table *table = dummy_table();
  Database db = {1, table};
  welcome_message();
  while(1){
    choice = input_choice();
    if (choice==0) {
      printf("Bye\n");
      exit(0);
    }
    switch(MODE){
      case MAIN_MENU:
        mode_main_menu(table, choice);
        break;
      case TABLE_MENU:
        mode_table_menu(table, choice);
        break;
      default:
        exit(1);
    }

    // welcome_message();
    select_menu(MODE);
  }
  /*
  print_table(table);
  Row *rp;
  rp = (Row *) malloc(sizeof(Row));
  *rp = (Row) {(Field []){
    (Field) {1, INT, (Data) {.i = 999}},
    (Field) {1, FLOAT, (Data) {.f = 444.44}},
    (Field) {10, STRING, (Data) {.c = "New User"}}

  }};
  table_insert(table, rp);
  printf("\nAfter Insert:\n");
  print_table(table);
  table_delete(table, &table->row[1]);
  printf("\nAfter Delete:\n");
  print_table(table);
  printf("\nAfter Update:\n");
  table_update(table, &table->row[0], table->row[1]);
  print_table(table);
  */

  return 0;
}

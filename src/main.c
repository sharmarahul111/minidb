#include <stdio.h>
#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "dummy_table.h"
#include "query.h"
extern char* table_menu[];
int main(void){
  int choice;
  INPUT_MODE mode = TABLE_MENU;
  welcome_message();
  Table *table = dummy_table();
  while(1){
    choice = input_choice();
    if (choice==0) {
      printf("Bye\n");
      exit(0);
    }
    switch(mode){
      case MAIN_MENU:
        mode_main_menu(table, choice);
      case TABLE_MENU:
        mode_table_menu(table, choice);
        break;
      default:
        exit(1);
    }

    // welcome_message();
    show_menu(table_menu, 4);
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

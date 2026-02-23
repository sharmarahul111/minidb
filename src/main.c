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
  Database db;
  db.table_count = 2;
  db.table_index = 0;
  strcpy(db.name, "My DB");
  dummy_table(&db.tables[0]);
  dummy_table(&db.tables[1]);
  welcome_message();
  while(1){
    choice = input_choice();
    if (choice==0) {
      printf("Bye\n");
      exit(0);
    }
    switch(MODE){
      case MAIN_MENU:
        mode_main_menu(&db, choice);
        break;
      case TABLE_MENU:
        mode_table_menu(&db.tables[db.table_index], choice);
        break;
      default:
        exit(1);
    }

    select_menu(MODE);
  }

  return 0;
}

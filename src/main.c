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
  Table *tables[] = {dummy_table(), dummy_table()};
  Database db = {2, 0,"My DB", tables};
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
        mode_table_menu(db.tables[db.table_index], choice);
        break;
      default:
        exit(1);
    }

    select_menu(MODE);
  }

  return 0;
}

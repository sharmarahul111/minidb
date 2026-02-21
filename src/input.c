#include <stdio.h>
#include <stdlib.h>
#include "input.h"
char *main_menu[] = {
  "Show databases",
  "Show tables",
  "Select database",
  "Select Table"
};
char *table_menu[] = {
  "Insert new row",
  "Delete a row",
  "Update a row"
};
char prompt[] = "> ";
void show_menu(char *menu[], int count){
  int i;
  for(i=0;i<count;i++){
    printf("%d) %s\n", i+1, menu[i]);
  }
  printf("0) Exit\n");
}
int input_choice(void){
  int choice;
  printf("\n%s", prompt);
  scanf("%d", &choice);
  return choice;
}
void welcome_message(void){
  printf("Hello user!\n");
  // show_menu(main_menu, 4);
  show_menu(table_menu, 3);

}

void mode_table_menu(int choice){
  enum {
    SELECT,
    INSERT,
    UPDATE,
    DELETE
  };
  switch (choice) {
    case SELECT:
      break;
    case INSERT:
      break;
    case UPDATE:
      break;
    case DELETE:
      break;
    
  }

}
void mode_main_menu(int choice){

}

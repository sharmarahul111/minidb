#include <stdio.h>
#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "query.h"
#define CUSTOM_MENU_SIZE 20
#define STRING_SIZE 32
char main_menu[][STRING_SIZE] = {
  "Show Tables",
  "Select Table",
  "Create Table",
  "Delete Table",

};
char table_menu[][STRING_SIZE] = {
  "Show table",
  "Insert new row",
  "Update a row",
  "Delete a row",
  "Main menu"
};
char custom_menu[CUSTOM_MENU_SIZE][32];

extern INPUT_MODE MODE;
char prompt[] = "> ";
void show_menu(char menu[][STRING_SIZE], int count){
  int i;
  for(i=0;i<count;i++){
    printf("%d) %s\n", i+1, menu[i]);
  }
}
int input_choice(void){
  int choice;
  printf("\n%s", prompt);
  scanf("%d", &choice);
  return choice;
}
void select_menu(int mode){
  switch (mode) {
    case MAIN_MENU:
      show_menu(main_menu, 4);
      break;
    case TABLE_MENU:
      show_menu(table_menu, 5);
      break;
    default:
      exit(1);
  }

}
void welcome_message(void){
  printf("Hello user! ");
  printf("Press 0 to exit anytime\n");
  show_menu(main_menu, 4);
}

void mode_main_menu(Database *db, int choice){
  enum {
    SHOW_TABLES = 1,
    SELECT_TABLE,
    CREATE_TABLE,
    DELETE_TABLE
  };
  switch (choice) {
    case SHOW_TABLES:
      break;
    case SELECT_TABLE:
      input_db_select_table(db);
      break;
    case CREATE_TABLE:
      break;
    case DELETE_TABLE:
      break;
    default:
      exit(0);
  }

}
void mode_table_menu(Table *table, int choice){
  enum {
    SELECT=1,
    INSERT,
    UPDATE,
    DELETE,
    GOTO_MAIN_MENU
  };
  switch (choice) {
    case SELECT:
      print_table(table);
      break;
    case INSERT:
      input_table_insert(table);
      break;
    case UPDATE:
      input_table_update(table);
      break;
    case DELETE:
      input_table_delete(table);
      break;
    case GOTO_MAIN_MENU:
      // Add table exiting selection functiom
      MODE = MAIN_MENU;
      break;
    default:
      exit(0);

  }

}

void input_db_select_table(Database *db){
  int table_choice;
  for (int i=0;i<db->table_count;i++) {
    strcpy(custom_menu[i], db->table[i].name);
  }
  printf("Select table:\n");
  show_menu(custom_menu, db->table_count);
  table_choice = input_choice();

  // <= table_count cuz enum index starts with 1 here
  if(table_choice >= 0 && table_choice <= db->table_count){
    db->table_index = table_choice-1; // starts with 1
    MODE = TABLE_MENU;
  } else {
    printf("Error: Table not selected\n");
  }
}
void input_table_update(Table *table){
  int id;
  printf("Enter %s:", table->column[0].name);
  scanf("%d", &id);
  for(int i=0;i<table->row_size;i++){
    if (table->row[i]->field[0].data.i == id) {
      for (int j=0;j<table->column_size;j++) {
        printf("%s: ", table->column[j].name);
        switch(table->column[j].type){
          case INT:
            printf("%d -> ", table->row[i]->field[j].data.i);
            scanf("%d", &table->row[i]->field[j].data.i);
            break;
          case FLOAT:
            printf("%.2f -> ", table->row[i]->field[j].data.f);
            scanf("%f", &table->row[i]->field[j].data.f);
            break;
          case CHAR32:
            printf("'%s' -> ", table->row[i]->field[j].data.char32);
            scanf("%s", table->row[i]->field[j].data.char32);
            break;
          case STRING:
            printf("'%s' -> ", table->row[i]->field[j].data.c);
            scanf("%s", table->row[i]->field[j].data.c);
            break;
        }
      }
    }
  }

}
void input_table_delete(Table *table){
  int id;
  printf("Enter %s:", table->column[0].name);
  scanf("%d", &id);
  for(int i=0;i<table->row_size;i++){
    if (table->row[i]->field[0].data.i == id) {
      table_delete(table, &table->row[i]);
      // The last row gets inserted to this index
      // so i-- incase last one is also a match
      i--;
    }
  }
}
void input_table_insert(Table *table){
  int i;
  Row *rp = (Row *) malloc(sizeof(Row));
  Field *fp = (Field *) malloc(table->column_size*sizeof(Field));
  for (i=0;i<table->column_size;i++) {
    printf("%s : ", table->column[i].name);
    switch(table->column[i].type){
      case INT:
        scanf("%d", &(fp[i].data.i));
        break;
      case FLOAT:
        scanf("%f", &(fp[i].data.f));
        break;
      case CHAR32:
        scanf("%s", fp[i].data.char32);
        break;
      case STRING:
        fp[i].data.c = (char *) malloc(20*sizeof(char));
        scanf("%s", fp[i].data.c);
        break;
    }
    *rp = (Row) {fp};
    // printf("\n");

  }
  table_insert(table, rp);
}

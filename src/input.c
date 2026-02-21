#include <stdio.h>
#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "query.h"
char *main_menu[] = {
  "Show databases",
  "Show tables",
  "Select database",
  "Select Table"
};
char *table_menu[] = {
  "Show table",
  "Insert new row",
  "Update a row",
  "Delete a row",
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
  show_menu(table_menu, 4);

}

void mode_table_menu(Table *table, int choice){
  enum {
    SELECT=1,
    INSERT,
    UPDATE,
    DELETE
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
    default:
      exit(0);

  }

}
void mode_main_menu(Table *table, int choice){
  (void) table;
  (void) choice;
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
      table_delete(table, table->row);
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

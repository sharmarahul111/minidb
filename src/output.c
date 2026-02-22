#include <stdio.h>
#include "schema.h"
#include "output.h"
void print_table(Table *table){
  int i,j;
  int c = table->column_size;
  printf("Table: %s\n", table->name);
  print_(12, c);
  printf("|");
  for (i=0;i<c;i++) {
    printf(" %-*s |",9, table->column[i].name);
  }
  printf("\n");
  print_(12, c);
  for (i=0;i<table->row_size;i++) {
    printf("|");
    for (j=0;j<c;j++) {
      switch(table->column[j].type){
        case INT:
          printf(" %*d |", 9, table->row[i]->field[j].data.i32);
          break;
        case FLOAT:
          printf(" %*.2f |", 9, table->row[i]->field[j].data.f32);
          break;
        case CHAR32:
          printf(" %-*s |", 9, table->row[i]->field[j].data.c32);
          break;
        case STRING:
          printf(" %-*s |", 9, table->row[i]->field[j].data.s);
          break;


      }
    }
    printf("\n");
    print_(12, c);
  }

}
void print_tables(Database *db){
  int i;
  int c = 1; // Only tables, no attribute column
  print_(12, 1);
  printf("| %-*s |",9, db->name);
  printf("\n");
  print_(12, 1);
  for (i=0;i<db->table_count;i++) {
    printf("| %-*s |", 9, db->tables[i]->name);
    printf("\n");
  }
  print_(12, c);
}
void print_(int cell_size,int column_size){
  int i;
  for (i=0;i<column_size*cell_size+1;i++) {
    printf("%c", i%cell_size==0?'+':'-');
  }
  printf("\n");
}

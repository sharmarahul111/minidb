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
          printf(" %*d |", 9, table->row[i]->field[j].data.i);
          break;
        case FLOAT:
          printf(" %*.2f |", 9, table->row[i]->field[j].data.f);
          break;
        case CHAR32:
          printf(" %-*s |", 9, table->row[i]->field[j].data.char32);
          break;
        case STRING:
          printf(" %-*s |", 9, table->row[i]->field[j].data.c);
          break;


      }
    }
    printf("\n");
    print_(12, c);
  }

}
void print_(int cell_size,int column_size){
  int i;
  for (i=0;i<column_size*cell_size+1;i++) {
    printf("%c", i%cell_size==0?'+':'-');
  }
  printf("\n");
}

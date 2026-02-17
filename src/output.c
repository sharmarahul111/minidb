#include<stdio.h>
#include "schema.h"
#include "output.h"
void printTable(Table table){
  int i,j;
  int c = table.column_size;
  print_(13, c);
  printf("|");
  for (i=0;i<c;i++) {
    printf(" %10s |", table.column[i].name);
  }
  printf("\n");
  print_(13, c);
  for (i=0;i<table.row_size;i++) {
    printf("|");
    for (j=0;j<c;j++) {
      switch(table.column[j].type){
        case INT:
          printf(" %10d |", table.row[i].field[j].data.i);
          break;
        case FLOAT:
          printf(" %10f |", table.row[i].field[j].data.f);
          break;
        case STRING:
          printf(" %10s |", table.row[i].field[j].data.c);
          break;


      }
    }
    printf("\n");
    print_(13, c);
  }

}
void print_(int cell_size,int column_size){
  int i;
  for (i=0;i<column_size*cell_size+1;i++) {
    printf("%c", i%cell_size==0?'+':'-');
  }
  printf("\n");
}

#include <stdlib.h>
#include <string.h>
#include "schema.h"
#include "query.h"

// TODO: rerurn type int with error code
// or somekind of error throwing

void db_create_table(Database *db, char name[32], Column *column, int column_size){
  db->tables[db->table_count].column_size = column_size;
  db->tables[db->table_count].row_size = 0;
  db->tables[db->table_count].row = (Row **) malloc(sizeof(Row*));
  db->tables[db->table_count].column = column;
  strcpy(db->tables[db->table_count].name, name);
  db->table_count++;
}
void db_delete_table(Database *db, int table_index){
  table_truncate(&db->tables[table_index]);
  free(db->tables[table_index].column);
  db->tables[table_index] = db->tables[db->table_count-1];
  db->table_count--;
  // memset(&db->tables[db->table_count], 0, sizeof(Table));

}
void table_truncate(Table *table){
  // to delete
  // row, row pointer, column, field pointer
  for (int i=0;i<table->row_size;i++) {
    for (int j=0;j<table->column_size;j++){
      if(table->column[j].type == STRING){
        free(table->row[i]->field[j].data.s);
      }
    }
    free(table->row[i]->field);
    free(table->row[i]);
  }
  free(table->row);
}
void table_insert(Table *table, Row *row){
  // TODO: Sanitize the input
  (table->row_size)++;
  table->row = (Row **) realloc(table->row, table->row_size * sizeof(Row *));
  table->row[table->row_size-1] = row;
}

// Deallocates the specified row
// Puts last row to current row pointer
// rocates pointer array
void table_delete(Table *table, Row **rowp){
  // TODO: Check size
  for(int i=0;i<table->column_size;i++){
    if (table->column[i].type == STRING) {
      free((*rowp)->field[i].data.s);
    }
  }
  free(*rowp);
  *rowp = table->row[table->row_size-1];
  table->row = (Row **) realloc(table->row, (table->row_size-1) * sizeof(Row *));
  (table->row_size)--;
}

void table_update(Table *table, Row **rowp, Row *new_row){
  // Might need table later
  (void) table;
  free(*rowp);
  *rowp = new_row;
}

// void table_select(Table *table, Row **rowp[], int row_size){
//
// }

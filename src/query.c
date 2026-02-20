#include <stdlib.h>
#include "schema.h"
#include "query.h"

void table_insert(Table *table, Row *row){
  // TODO: Sanitize the input
  (table->row_size)++;
  table->row = (Row **) realloc(table->row, table->row_size * sizeof(Row *));
  table->row[table->row_size-1] = row;
}

void table_delete(Table *table, Row **rowp){
  // TODO: Check size
  (table->row_size)--;
  free(*rowp);
  *rowp = table->row[table->row_size];
  table->row = (Row **) realloc(table->row, table->row_size * sizeof(Row *));
}

void table_update(Table *table, Row **rowp, Row *new_row){
  (void) table;
  free(*rowp);
  *rowp = new_row;
}

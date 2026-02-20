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

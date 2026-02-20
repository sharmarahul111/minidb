#ifndef QUERY_MODULE
#define QUERY_MODULE
void table_insert(Table *table, Row *row);
void table_delete(Table *table, Row **rowp);
void table_select(Table *table, Row **rowp[], int row_size);
void table_update(Table *table, Row **rowp, Row *new_row);
#endif

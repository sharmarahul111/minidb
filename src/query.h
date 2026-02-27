#ifndef QUERY_MODULE
#define QUERY_MODULE
void db_create_table(Database *db, char name[32], Column *column, int column_size);
void db_delete_table(Database *db, int table_index);
void table_insert(Table *table, Row *row);
void table_truncate(Table *table);
void table_delete(Table *table, Row **rowp);
void table_select(Table *table, Row **rowp[], int row_size);
void table_update(Table *table, Row **rowp, Row *new_row);
#endif

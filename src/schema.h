typedef enum {
  INT,
  FLOAT,
  STRING
} DataType;

typedef union {
  int i;
  float f;
  char *c;
} Data;

typedef struct {
  int size;
  DataType type;
  Data data;
} Field;

typedef struct {
  Field *field;
} Row;

typedef struct {
  int name_size;
  char *name;
  DataType type;
} Column;

typedef struct {
  int column_size;
  int row_size;
  Column *column;
  // TODO: Use capacity to avoid unnecessary reallocs
  Row **row;
} Table;

typedef struct {
  int table_count;
  Table *table;
} Database;

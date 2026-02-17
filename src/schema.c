typedef enum {
  INT,
  FLOAT,
  STRING
} DataType;

typedef union {
  DataType type;
  int i;
  float f;
  char *c;
} Data;

typedef struct {
  int size;
  Data data;
} Field;

typedef struct {
  Field *field;
} Row;

typedef struct {
  char *name;
  DataType type;
} Column;

typedef struct {
  int column_size;
  int row_size;
  Column *column;
  Row *row;
} Table;

typedef struct {
  int table_count;
  Table *table;
} Database;

typedef enum {
  INT,
  FLOAT,
  CHAR32,
  STRING
} DataType;

typedef union {
  int i32;
  float f32;
  char *s;
  char c32[32];
} Data;

typedef struct {
  int size;
  // currently not in use but maybe needed for NULL values
  DataType type;
  Data data;
} Field;

typedef struct {
  Field *field;
} Row;

typedef struct {
  int name_size;
  char name[32];
  DataType type;
} Column;

typedef struct {
  int column_size;
  int row_size;
  Column *column;
  // TODO: Use capacity to avoid unnecessary reallocs
  Row **row;
  char name[32];
} Table;

typedef struct {
  int table_count;
  int table_index;
  char name[32];
  Table **tables;
} Database;

#ifndef INPUT_MODULE
#define INPUT_MODULE
typedef enum {
  MAIN_MENU = 1,
  TABLE_MENU
} INPUT_MODE;

int input_choice(void);
void welcome_message(void);
void show_menu(char *menu[], int count);
// MODE operations
void mode_main_menu(Table *table, int choice);
void mode_table_menu(Table *table, int choice);

// Table CRUD operations
void input_table_insert(Table *table);
#endif

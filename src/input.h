#ifndef INPUT_MODULE
#define INPUT_MODULE
typedef enum {
  MAIN_MENU,
  TABLE_MENU
} INPUT_MODE;

int input_choice(void);
void welcome_message(void);
void show_menu(char *menu[], int count);
// MODE operations
void mode_main_menu(int choice);
void mode_table_menu(int choice);
#endif

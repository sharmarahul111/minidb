#include <stdio.h>
#include <stdlib.h>
#include "input.h"
char *main_menu[] = {
  "Show databases",
  "Show tables",
  "Select database",
  "Select Table"
};
char prompt[] = ">";
void showMenu(char *menu[], int count){
  int i;
  for(i=0;i<count;i++){
    printf("%d. %s\n", i+1, menu[i]);
  }
}
int inputChoice(void){
  int choice;
  printf("\n%s", prompt);
  scanf("%d", &choice);
  return choice;
}
void welcomeMessage(void){
  printf("Hello user!\n");
  showMenu(main_menu, 4);

}

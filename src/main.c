#include<stdio.h>
#include "schema.h"
#include "input.h"
#include "output.h"
#include "dummy_table.h"

int main(){
  // welcomeMessage();
  Table *table = dummy_table();
  printTable(table);

  return 0;
}

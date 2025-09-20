#include "stdio.h"
#include "string.h"
#include <complex.h>
// Definere alle Arrays og variabler
#define MAX_LENGTH 15

int correctpart = 0;
int i;
int PARTS_COUNT;
char answer[50];
// beskriver alle genstande på lager
char Inventory[][MAX_LENGTH] = {
    "PLC module",
    "Servo motor",
    "hydraulic pump",
};
// beskriver special queries
char Queries[2][50] = {"Do you actually have any parts?",
                       "Is there anything in stock at all?"};
// dividere totalstørrelsen af alle hele arrayet med byte størrelse pr genstand
int PARTS_COUNT = sizeof(Inventory) / sizeof(Inventory[0]);

int main(void) {

  printf("Hello welcome to the sparepart inventory!\n");
  while (1) {
    // får user input
    puts("which part do you need?");
    fgets(answer, 50, stdin);
    answer[strcspn(answer, "\n")] =
        '\0'; // replacer \n(enter) med \0(string end)
    // Tjekker hvis bruger Inputtet matcher nogle af vores special queries
    if (strcmp(Queries[0], answer) == 0 || strcmp(Queries[1], answer) == 0) {
      printf("Yes we have %d parts in stock:\n", PARTS_COUNT);
      while (i < PARTS_COUNT) {
        puts(Inventory[i]);
        ++i;
      }
      continue; // hvis inputtet matcher skipper den resten af loopet og går
                // tilbage til start
    }
    // sammenligner user input med vores vores lager
    int i = 0;
    while (i != PARTS_COUNT) {
      if (strcmp(Inventory[i], answer) == 0) {
        printf("i have got a %s", Inventory[i]);
        printf(" here for you!");
        return 0;
      }

      ++i;
    }
    printf("im afraid we dont have any %s in inventory: \n", answer);
  }
}

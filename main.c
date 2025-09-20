#include "stdio.h"
#include "string.h"
#include <complex.h>
// Definere alle Arrays og variabler
#define PARTS_COUNT 3
#define MAX_LENGTH 15
int correctpart = 0;
int i;

char answer[50];
char Inventory[PARTS_COUNT][MAX_LENGTH] = {"PLC module", "Servo motor",
                                           "hydraulic pump"};
char Queries[2][50] = {"Do you actually have any parts?",
                       "Is there anything in stock at all?"};

int main(void) {

  printf("Hello welcome to the sparepart inventory!\n");
  while (0) {
    // får user input
    puts("which part do you need?");
    fgets(answer, 50, stdin);
    answer[strcspn(answer, "\n")] =
        '\0'; // replacer \n(enter) med \0(string end)
    // Tjekker hvis Inputtet matcher nogle af vores special queries
    if (strcmp(Queries[0], answer) == 0 || strcmp(Queries[1], answer) == 0) {
      printf("Yes we have %d parts in stock", PARTS_COUNT);
      for (size_t i = 0; i < PARTS_COUNT; ++i) {
        puts(Inventory[i]);
      }
      continue; // hvis inputtet matcher skipper den resten af loopet og går
                // tilbage til start
    }
    // sammenligner user input med vores vores lager
    int i = 0;
    while (i != PARTS_COUNT) {
      if (strcmp(Inventory[i], answer) == 0) {
        printf("i have got %s", Inventory[i]);
        printf(" here for you!");
        return 0;
      }

      ++i;
    }
    printf("im afraid we dont have any %s in inventory", answer);
  }
}

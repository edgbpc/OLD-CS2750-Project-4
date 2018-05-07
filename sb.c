//Author: Eric Goodwin
//CS2750 Assignment 4
//Dr, Sanjiv Bhatia

#include <stdio.h> //for printf
#include <time.h>  //for srand
#include <stdlib.h> //for rand
#include <memory.h> //for memset
#include <math.h> //for floor
//#include <string.h>
#include <stdbool.h> //for bool
#include "card_t.h" //for card struct

//bit macros
#define TEST_BIT(i, j) ((i) & ( 1 << (7-j))) //provided in class 
#define SET_BIT(i, j) ((i) |= ( 1 << (7-j))) //provided in class

//global variables
card_t DeckofCards[52];
unsigned char bit[7];


//function prototypes
void displayDeck (card_t*);
int Compare (const void*, const void* );
void createDeck (card_t*);
void shuffleDeck(card_t*);

int main ()
{
	memset(bit, 0, sizeof(7));

	srand(time(NULL));  //seeds the timer for rand

	createDeck(DeckofCards);
	printf("************ Deck before Shuffle ************\n");
	displayDeck(DeckofCards);
	
	shuffleDeck(DeckofCards);
	printf("************ Deck before Shuffle ************\n");
	displayDeck(DeckofCards);

	qsort(DeckofCards, 52, sizeof(card_t), Compare);
	printf("************ Deck Organized by Suit  ************\n");
	displayDeck(DeckofCards);

	return 0;
}

//function definations

//This function populates the array of cards using the provided struct
void createDeck (card_t *DeckofCards)
{
int m,n;
  for (m = clubs; m <= spades; m++){
     for (n = Ace; n <= King; n++){ // added enum in the header card_t to allow for this
        int index = (m*13) + n; // increments 0 - 51
           DeckofCards[index].suit = m;
	   DeckofCards[index].number = n;
    }
  }
}

//this function shuffles the deck using bitwise operators
void shuffleDeck(card_t* DeckofCards)
{
  bool search = true;  //set flag to keep while loop going
  int r;
  int index = 0;
  
  for (index; index < 52; index++){
     // int i = 13/8; //provided in class
     // int j = 13 % 8; //provided in class
      r = (rand () % 51 ) + 1;
      if ( (TEST_BIT( bit[(r/8)] , ( r % 8)) ) == 0 ){
        SET_BIT( bit[(r/8)] , (r % 8));
      }
      else {
        while (search){ 
	r++; //increments the random number by 1 to set the next bit
           if (r > 51){ //prevents incrementing past 51 
               r = 0;
           } 
           if ( (TEST_BIT( bit[(r/8)] , (r % 8)) ) == 0){
              SET_BIT( bit[(r/8)] , (r % 8));
              search = false; //stops searching when 0 is found
           }
         } 
	search = true;
      }
    DeckofCards[index].suit = r / 13;
    DeckofCards[index].number = r % 13;
 }
}

//displayDeck uses a switch to display the DeckofCards
void displayDeck ( card_t* DeckofCards ){
int index;
for ( index = 0; index <=51; index++){

	switch(DeckofCards[index].number){
		case 0:
			printf("Ace of ");
			break;
		case 1:
			printf("Two of ");
			break;
		case 2:
			printf("Three of ");
			break;
		case 3:
			printf("Four of ");
			break;
		case 4:
			printf("Five of ");
			break;
		case 5:
			printf("Six of ");
			break;
		case 6:
			printf("Seven of ");
			break;
		case 7:
			printf("Eight of ");
			break;
		case 8:
			printf("Nine of ");
			break;
		case 9:
			printf("Ten of ");
			break;
		case 10:
			printf("Jack of ");
			break;
		case 11: 
			printf("Queen of ");
			break;
		case 12:
			printf("King of ");
			break;
	}
	switch(DeckofCards[index].suit){
		case 0 : 
			printf("Clubs\n");
			break;
		case 1 :
			printf("Diamonds\n");
			break;
		case 2 :
			printf("Hearts\n");
			break;
		case 3:
			printf("Spades\n");
			break;
	}
  }
}
//previous version of displayDeck.  replaced by switch above
/*if ( DeckofCards[index].suit == 0 )
    {
    if ( DeckofCards[index].number == 0 )
       printf("Ace of ");
    else if ( DeckofCards[index].number == 1 )
        printf("Two of ");
    else if ( DeckofCards[index].number == 2 )
        printf("Three of ");
    else if ( DeckofCards[index].number == 3 )
        printf("Four of ");
    else if ( DeckofCards[index].number == 4 )
        printf("Five of ");
    else if ( DeckofCards[index].number == 5 )
        printf("Six of ");
    else if ( DeckofCards[index].number == 6 )
        printf("Seven of ");
    else if ( DeckofCards[index].number == 7 )
        printf("Eight of ");
    else if ( DeckofCards[index].number == 8 )
       printf("Nine of ");
    else if ( DeckofCards[index].number == 9 )
       printf("Ten of " );
    else if ( DeckofCards[index].number == 10 )
       printf("Jack of ");
    else if ( DeckofCards[index].number == 11 )
       printf("Queen of ");
    else if ( DeckofCards[index].number == 12 )
       printf("King of ");
printf("Clubs\n");
    }
else if ( DeckofCards[index].suit == 1 )
    {
    if ( DeckofCards[index].number == 0 )
       printf("Ace of ");
    else if ( DeckofCards[index].number == 1 )
        printf("Two of ");
    else if ( DeckofCards[index].number == 2 )
        printf("Three of ");
    else if ( DeckofCards[index].number == 3 )
        printf("Four of ");
    else if ( DeckofCards[index].number == 4 )
        printf("Five of ");
    else if ( DeckofCards[index].number == 5 )
        printf("Six of ");
    else if ( DeckofCards[index].number == 6 )
        printf("Seven of ");
    else if ( DeckofCards[index].number == 7 )
        printf("Eight of ");
    else if ( DeckofCards[index].number == 8 )
       printf("Nine of ");
    else if ( DeckofCards[index].number == 9 )
       printf("Ten of ");
    else if ( DeckofCards[index].number == 10 )
       printf("Jack of ");
    else if ( DeckofCards[index].number == 11 )
       printf("Queen of ");
    else if ( DeckofCards[index].number == 12 )
       printf("King of ");
printf("Diamonds\n");
    }
else if ( DeckofCards[index].suit == 2 )
    {
    if ( DeckofCards[index].number == 0 )
       printf("Ace of ");
    else if ( DeckofCards[index].number == 1 )
        printf("Two of ");
    else if ( DeckofCards[index].number == 2 )
        printf("Three of ");
    else if ( DeckofCards[index].number == 3 )
        printf("Four of ");
    else if ( DeckofCards[index].number == 4 )
        printf("Five of ");
    else if ( DeckofCards[index].number == 5 )
        printf("Six of ");
    else if ( DeckofCards[index].number == 6 )
        printf("Seven of ");
    else if ( DeckofCards[index].number == 7 )
        printf("Eight of ");
    else if ( DeckofCards[index].number == 8 )
       printf("Nine of ");
    else if ( DeckofCards[index].number == 9 )
       printf("Ten of ");
    else if ( DeckofCards[index].number == 10 )
       printf("Jack of ");
    else if ( DeckofCards[index].number == 11 )
       printf("Queen of ");
    else if ( DeckofCards[index].number == 12 )
       printf("King of ");
printf("Hearts\n");
    }
else if ( DeckofCards[index].suit == 3 )
    {
    if ( DeckofCards[index].number == 0 )
       printf("Ace of ");
    else if ( DeckofCards[index].number == 1 )
        printf("Two of ");
    else if ( DeckofCards[index].number == 2 )
        printf("Three of ");
    else if ( DeckofCards[index].number == 3 )
        printf("Four of ");
    else if ( DeckofCards[index].number == 4 )
        printf("Five of ");
    else if ( DeckofCards[index].number == 5 )
        printf("Six of ");
    else if ( DeckofCards[index].number == 6 )
        printf("Seven of ");
    else if ( DeckofCards[index].number == 7 )
        printf("Eight of ");
    else if ( DeckofCards[index].number == 8 )
       printf("Nine of ");
    else if ( DeckofCards[index].number == 9 )
       printf("Ten of ");
    else if ( DeckofCards[index].number == 10 )
       printf("Jack of ");
    else if ( DeckofCards[index].number == 11 )
      printf("Queen of ");
    else if ( DeckofCards[index].number == 12 )
      printf("King of ");
   printf("Spades\n");
    }
}
}*/

//Compare function neccesary for qsort.  Similiar function as in shuffle.c but compares the suit member function
int Compare (const void * a , const void * b)
{
int p1 = ((card_t*)a)->suit;
int p2 = ((card_t*)b)->suit;

return p1 - p2;

}


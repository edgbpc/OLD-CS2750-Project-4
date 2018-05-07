//Author: Eric Goodwin
//CS2750 Assignment 4
//Create a program to shuffle a deck of cards. The suits and cards are to be defined as
//typedef enum { clubs, diamonds, hearts, spades} suit_t;
//typedef struct
//{
//unsigned int number : 4;
//suit_t suit : 2;
//} card_t;
//Declare an array of cards with a complete deck of 52 cards. Populate the cards using a loop such that
//all the cards of a single suit are together in order as Ace, 2, 3, 4, . . ., King. Shuffle the cards using
//the following algorithm.
//Generate a random number between 0 and 51, and call it r. Swap the cards at position 0 and position:
//r. Repeat the loop for a total of 52 iterations.
//At the end of the shuffle, print the array.
//Then, sort the array using qsort(3C) such that all the cards with the same number are together.
//This program will be called shuffle.

#include <stdio.h> //for printf
#include <time.h>  //for srand
#include <stdlib.h> //for rand
#include "card_t.h" //for card struct

//global variables
card_t DeckofCards[52];  //initalizes struct for the deck of cards that will be randomized
card_t TempDeck; //used in process to shuffle the deck of cards


//function prototyoes
int Compare (const void*, const void* );
void displayDeck (card_t*);  // displays the deck of cards, called multiple times in the progam 
void createDeck(card_t*); //populates DeckofCards 
void shuffleDeck(card_t*); //shuffles DeckofCards

int main () {

	srand(time(NULL));  //seeds the timer for rand

	createDeck(DeckofCards);
	printf("************ Deck before Shuffle ************\n");
	displayDeck(DeckofCards); //displays the cards before the shuffle was not a requirement 


	shuffleDeck(DeckofCards);
	printf("************ Deck After Shuffle ************\n");
	displayDeck(DeckofCards);

	qsort(DeckofCards, 52, sizeof(card_t), Compare);
	printf("************ Deck Organized by Card Value ************\n");
	displayDeck(DeckofCards);
	
	return 0;
}




//function definations

//createDeck populates DeckofCards by nested assigning cards to the member functions suit and number
void createDeck( card_t* DeckofCards ){
int m, n; 
  for ( m = clubs; m <= spades; m++ ){ //this code populates the struct with the cards
    for (n = Ace; n <= King; n++ ){
         int index = (m*13) + n; //used to increment through the array
         DeckofCards[index].suit = m;
         DeckofCards[index].number = n;
     }   
  }
}


//shuffleDeck uses a second card_t struct to swap cards between 0 element and random element
void shuffleDeck( card_t* DeckofCards){
int tmpIndex;  
   for ( tmpIndex = 0; tmpIndex <52; tmpIndex++){  //this code executes the "shuffle"
	int r = ( rand() % 51 ) +1;
        TempDeck.suit = DeckofCards[0].suit;
	TempDeck.number = DeckofCards[0].number;
	DeckofCards[0].suit = DeckofCards[r].suit;
	DeckofCards[0].number = DeckofCards[r].number;
	DeckofCards[r].suit = TempDeck.suit;
	DeckofCards[r].number = TempDeck.number;
   }
}
//displayDeck prints the card numbers and suits stored in the DeckofCards array.  Time allowing, this may be changed to a switch in order to reduce number of lines of code.  
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
//original displayDeck function.  replaced with the switch above
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

//Compare function necessary for the qsort command ran to organize to the cards by number.  by changing ->number to ->suit, can be made or organize by suit.  Function appears as such in the sb.c program.
int Compare (const void * a , const void * b)
{
int p1 = ((card_t*)a)->number;
int p2 = ((card_t*)b)->number;

return p1 - p2;
 
}


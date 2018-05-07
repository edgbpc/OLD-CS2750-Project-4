#ifndef card_t_h
#define card_t_h

typedef enum { clubs, diamonds, hearts, spades} suit_t;
typedef enum { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King } face_t;
typedef struct
{
face_t number : 4;
suit_t suit : 2;
} card_t;

#endif


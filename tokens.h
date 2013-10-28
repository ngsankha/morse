#ifndef morse_token

#define morse_token 1

#define PUSH_TO_INT_STACK 0 // .
#define DUPL_TOP_OF_INT_STACK 1 // _
#define SWAP_INT_STACK_ITEMS 2 // _.
#define POP_FROM_INT_STACK 3 // __

#define PUSH_TO_CHAR_STACK 4 // _..
#define DUPL_TOP_OF_CHAR_STACK 5 // _._
#define SWAP_CHAR_STACK_ITEMS 6 // __.
#define POP_FROM_CHAR_STACK 7 // ___

#define ADD_TWO_INTS 8 // _...
#define SUB_TWO_INTS 9 // _.._
#define MUL_TWO_INTS 10 // _._.
#define DIV_TWO_INTS 11 // _.__
#define MOD_TWO_INTS 12 // __..

#define PRINT_TOP_INT 13 // __._
#define PRINT_TOP_CHAR 14 // ___.
#define INPUT_TOP_INT 15 // ____
#define INPUT_TOP_CHAR 16 // _....

#define GOTO_LINE 17 // _..._
#define GOTO_IF_POSITIVE 18 // _.._.
#define GOTO_IF_NEGATIVE 19 // _..__
#define GOTO_IF_ZERO 20 // _._..

#endif
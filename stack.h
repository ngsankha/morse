#ifndef morse_stack

#define morse_stack 1

#include <stdio.h>
#include <stdlib.h>

#define ERR_INT_STACK_EMPTY  "Error: Empty Integer Stack.\n"
#define ERR_CHAR_STACK_EMPTY "Error: Empty Integer Stack.\n"

struct intNode {
    int data;
    struct intNode *next;
} *intTop;

struct charNode {
    char data;
    struct charNode *next;
} *charTop;

void initStacks();
int popInt();
int peekInt();
void pushInt(int);
char popChar();
char peekChar();
void pushChar(char);

#endif

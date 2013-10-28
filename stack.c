#include "stack.h"

void initStacks() {
    intTop = NULL;
    charTop = NULL;
}

int popInt() {
    struct intNode *var = intTop;
    int data;
    if (var == intTop) {
        data = intTop->data;
        intTop = intTop->next;
        free(var);
    } else
        printf(ERR_INT_STACK_EMPTY);
    return data;
}

int peekInt() {
    int data = popInt();
    pushInt(data);
    return data;
}

void pushInt(int value) {
    struct intNode *temp;
    temp = (struct intNode *) malloc(sizeof(struct intNode));
    temp->data = value;
    if (intTop == NULL) {
        intTop = temp;
        intTop->next = NULL;
    } else {
        temp->next = intTop;
        intTop = temp;
    }
}

char popChar() {
    struct charNode *var = charTop;
    char data;
    if (var == charTop) {
        data = charTop->data;
        charTop = charTop->next;
        free(var);
    } else
        printf(ERR_CHAR_STACK_EMPTY);
    return data;
}

char peekChar() {
    int data = popChar();
    pushChar(data);
    return data;
}

void pushChar(char value) {
    struct charNode *temp;
    temp = (struct charNode *) malloc(sizeof(struct charNode));
    temp->data = value;
    if (charTop == NULL) {
        charTop = temp;
        charTop->next = NULL;
    } else {
        temp->next = charTop;
        charTop = temp;
    }
}

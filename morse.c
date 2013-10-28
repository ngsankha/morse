#include "stack.h"
#include "tokens.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

#define ERR_FILE_OPEN "Error: Unable to openfile.\n"
#define ERR_FILE_UNSPECIFIED "Error! No input file specified.\n"
#define ERR_LINE_NOT_FOUND "Error: Line not found.\n"
#define ERR_FILE_OPEN_CODE 1
#define ERR_LINE_NOT_FOUND_CODE 2

size_t lineLen = 0;
ssize_t read;
FILE *fp;
int lineNum;

char *readLine();
void openFile(char*);
void parseTokens(char*);
char *str_replace(char*, char*, char*);
int parseInt(char*);
int binary_decimal(int);
void jumpLine(char*);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf(ERR_FILE_UNSPECIFIED);
        exit(ERR_FILE_OPEN_CODE);
    } else {
        initStacks();
        openFile(argv[1]);
        while (1) {
            parseTokens(readLine());
        }
    }
}

char *readLine() {
    char *line = NULL;
    read = getline(&line, &lineLen, fp);
    if (read == -1)
        exit(0);
    lineNum++;
    return line;
}

void openFile(char *file) {
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf(ERR_FILE_OPEN);
        exit(ERR_FILE_OPEN_CODE);
    }
    lineNum = 0;
}

char *str_replace(char *str, char *old, char *new) {
    char *ret, *r;
    const char *p, *q;
    size_t oldlen = strlen(old);
    size_t count, retlen, newlen = strlen(new);

    if (oldlen != newlen) {
        for (count = 0, p = str; (q = strstr(p, old)) != NULL; p = q + oldlen)
            count++;
        retlen = p - str + strlen(p) + count * (newlen - oldlen);
    } else
        retlen = strlen(str);

    if ((ret = malloc(retlen + 1)) == NULL)
        return NULL;

    for (r = ret, p = str; (q = strstr(p, old)) != NULL; p = q + oldlen) {
        ptrdiff_t l = q - p;
        memcpy(r, p, l);
        r += l;
        memcpy(r, new, newlen);
        r += newlen;
    }
    strcpy(r, p);

    return ret;
}

int binary_decimal(int n) {
    int decimal = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }
    return decimal;
}

int parseInt(char *token) {
    char *semiMorse = str_replace(token, ".", "0");
    char *binary = str_replace(semiMorse, "_", "1");
    int bin = atoi(binary);
    return binary_decimal(bin);
}

void parseTokens(char *line) {
    char* token = strtok(line, " ");
    if (token) {
        int cmd = parseInt(token);
        switch (cmd) {
            case PUSH_TO_INT_STACK: {
                token = strtok(NULL, " ");
                int data = parseInt(token);
                pushInt(data);
                break;
            }
            case DUPL_TOP_OF_INT_STACK:
                pushInt(peekInt());
                break;
            case SWAP_INT_STACK_ITEMS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1);
                pushInt(data2);
                break;
            }
            case POP_FROM_INT_STACK:
                popInt();
                break;

            case PUSH_TO_CHAR_STACK: {
                token = strtok(NULL, " ");
                char data = (char) parseInt(token);
                pushChar(data);
                break;
            }
            case DUPL_TOP_OF_CHAR_STACK:
                pushChar(peekChar());
                break;
            case SWAP_CHAR_STACK_ITEMS: {
                char data1 = popChar();
                char data2 = popChar();
                pushChar(data1);
                pushChar(data2);
                break;
            }
            case POP_FROM_CHAR_STACK:
                popChar();
                break;

            case ADD_TWO_INTS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1 + data2);
                break;
            }
            case SUB_TWO_INTS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1 - data2);
                break;
            }
            case MUL_TWO_INTS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1 * data2);
                break;
            }
            case DIV_TWO_INTS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1 / data2);
                break;
            }
            case MOD_TWO_INTS: {
                int data1 = popInt();
                int data2 = popInt();
                pushInt(data1 % data2);
                break;
            }

            case PRINT_TOP_INT: {
                int data = peekInt();
                printf("%d\n", data);
                break;
            }
            case PRINT_TOP_CHAR: {
                char data = peekChar();
                printf("%c", data);
                break;
            }
            case INPUT_TOP_INT: {
                int data;
                scanf("%d", &data);
                pushInt(data);
                break;
            }
            case INPUT_TOP_CHAR: {
                char data;
                data = getchar();
                pushChar(data);
                break;
            }
            case GOTO_LINE:
                jumpLine(token);
                break;
            case GOTO_IF_POSITIVE:
                if (peekInt() > 0)
                    jumpLine(token);
                break;
            case GOTO_IF_NEGATIVE:
                if (peekInt() < 0)
                    jumpLine(token);
                break;
            case GOTO_IF_ZERO:
                if (peekInt() == 0)
                    jumpLine(token);
                break;
        }
    }
}

void jumpLine(char *token) {
    char *line = NULL;
    token = strtok(NULL, " ");
    int data = parseInt(token);
    data--;
    rewind(fp);
    lineNum = 0;
    while (lineNum != data) {
        read = getline(&line, &lineLen, fp);
        if (read == -1) {
            printf(ERR_LINE_NOT_FOUND);
            exit(ERR_LINE_NOT_FOUND_CODE);
        }
        lineNum++;
    }
}
#ifndef morse

#define morse 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "stack.h"
#include "tokens.h"

#define ERR_FILE_OPEN           "Error: Unable to openfile.\n"
#define ERR_FILE_UNSPECIFIED    "Error! No input file specified.\n"
#define ERR_LINE_NOT_FOUND      "Error: Line not found.\n"

#define ERR_FILE_OPEN_CODE      1
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

#endif
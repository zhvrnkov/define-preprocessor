//
//  getword.c
//  TableLookup
//
//  Created by Vlad Zhavoronkov on 7/15/19.
//  Copyright © 2019 Vlad Zhavoronkov. All rights reserved.
//

#include "getword.h"
#define isalowable(c) !(c == ' ' || c == ',' || c == ';' || c == '\t' || c == '\n' || c == '(' || c == ')')

char *getword(const char *src, int *pointer) {
    while (!isalowable(src[*pointer]))
        *pointer += 1;
    int initialPointer = *pointer;
    char c;
    while((c = src[*pointer]) && isalowable(c)) {
        *pointer += 1;
    }
    char *buffer = malloc(*pointer - initialPointer);
    int bufferPointer = 0;
    while (initialPointer < *pointer) {
        buffer[bufferPointer++] = src[initialPointer];
        initialPointer++;
    }
    buffer[bufferPointer] = '\0';
    
    return buffer;
}

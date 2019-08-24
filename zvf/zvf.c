//
//  read.c
//  TableLookup
//
//  Created by Vlad Zhavoronkov on 7/15/19.
//  Copyright © 2019 Vlad Zhavoronkov. All rights reserved.
//

#include "zvf.h"

char *zvread(const char *filePath) {
    char *buffer;

    FILE *file = fopen(filePath , "r");
    fseek(file, 0L, SEEK_END);
    int length = (int)ftell(file);
    fseek(file, 0L, SEEK_SET);
    buffer = malloc(length);
    
    fread(buffer, sizeof(char), length, file);
    fclose(file);
    
    return buffer;
}

void zvwrite(const char *filePath, const char *content) {
    FILE *file = fopen(filePath, "w+");
    fputs(content, file);
    fclose(file);
}

char *replaceWord(char *src, char *oldWord, char *newWord) {
    char *result;
    int i, count = 0;
    unsigned long oldLength = strlen(oldWord);
    unsigned long newLength = strlen(newWord);
    
    for (i = 0; src[i]; ++i)
        if (strstr(&src[i], oldWord) == &src[i]) {
            count++;
            i += oldLength - 1;
        }
    
    result = malloc(i + count * (newLength - oldLength) + 1);
    
    
    i = 0;
    while (*src) {
        if (strstr(src, oldWord) == src) {
            strcpy(&result[i], newWord);
            i += newLength;
            src += oldLength;
        }
        else
            result[i++] = *src++;
    }
    
    result[i] = '\0';
    return result;
}

char *removeLine(char *src, int lineNumber) {
    char *result;
    int lineStart = 0;
    int lineLength = 0;
    int srcLength = strlen(src);
    
    for (int i = 0, lineCount = 0; lineCount != lineNumber; i++) {
        if (src[i] == '\n') {
            lineStart = i + 1;
            lineCount++;
        }
    }
    
    for (int i = lineStart; src[i] != '\n'; i++)
        lineLength++;
    lineLength++;
    
    result = malloc(srcLength - lineLength);
    
    int resultIndex = 0;
    int srcIndex = 0;
    while (src[srcIndex]) {
        if (srcIndex == lineStart) {
            srcIndex += lineLength;
        } else {
            result[resultIndex] = src[srcIndex];
            srcIndex++;
            resultIndex++;
        }
    }
    
    return result;
}

int getFirstLineThatContain(char *src, char *desired) {
    char *position = strstr(src, desired);
    if (!position) return -1;
    int range = (int)(position - src);
    int numberOfLine = 0;
    
    for (int i = 0; i < range; i++) {
        if (src[i] == '\n') numberOfLine++;
    }
    
    return numberOfLine;
}

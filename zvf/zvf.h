//
//  read.h
//  TableLookup
//
//  Created by Vlad Zhavoronkov on 7/15/19.
//  Copyright © 2019 Vlad Zhavoronkov. All rights reserved.
//

#ifndef read_h
#define read_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *zvread(const char *filePath);
void zvwrite(const char *filePath, const char *content);
char *replaceWord(char *src, char *oldWord, char *newWord);
char *removeLine(char *src, int lineNumber);
int getFirstLineThatContain(char *src, char *desired);

#endif /* read_h */

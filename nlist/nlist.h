//
//  nlist.h
//  TableLookup
//
//  Created by Vlad Zhavoronkov on 7/15/19.
//  Copyright © 2019 Vlad Zhavoronkov. All rights reserved.
//

#ifndef nlist_h
#define nlist_h

#include <stdlib.h>
#include <string.h>

#define HASHTABSIZE 10

static struct nlist *hashtab[HASHTABSIZE];

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
struct nlist *get(int index);
void undef(struct nlist *np);


#endif /* nlist_h */

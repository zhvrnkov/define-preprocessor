//
//  nlist.c
//  TableLookup
//
//  Created by Vlad Zhavoronkov on 7/15/19.
//  Copyright © 2019 Vlad Zhavoronkov. All rights reserved.
//
#include "nlist.h"

unsigned hash(char *s) {
    unsigned hashvalue;
    for (hashvalue = 0; *s != '\0'; s++)
        hashvalue = *s + (31 * hashvalue);
    return hashvalue % HASHTABSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(struct nlist));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *get(int index) {
    return hashtab[index];
}

void undef(struct nlist *np) {
    free((void *) np->defn);
    free((void *) np->name);
}

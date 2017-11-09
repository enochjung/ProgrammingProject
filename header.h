#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _word
{
    int data;
    struct _word* next;
} word;

#endif

#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct _word
{
	char eng[16];
	int number;
	char kor[3][91];
    struct _word* next;
} word;

#endif

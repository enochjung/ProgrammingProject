// 작성자 : 정에녹

#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct _word
{
	char eng[16];
	char kor[300];
    struct _word* next;
} word;

#endif

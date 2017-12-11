// 작성자 : 정에녹

#include "file_manage.h"

static int compare_word(const void *p, const void *q)
{
	char *a = ((word*)p)->eng;
	char *b = ((word*)q)->eng;

	return strcmp(a, b);
}

word* get_word_list(int file_number, int print_way)
{
	char file_name[100];
	FILE *ifp;
	word head;
	int check;

	sprintf(file_name, "%d.dic", file_number);
	if((ifp = fopen(file_name, "rb")) == NULL)
	{
		printf("ERROR - 파일 '%s' 읽기 실패\n", file_name);
		exit(-1);
	}

	head.next = NULL;

	if(print_way == 1)
	{
		word* before = &head;

		while(1)
		{
			word* now = (word*)malloc(sizeof(word));
			check = fread(now, sizeof(word), 1, ifp);
			if(!check)
			{
				free(now);
				break;
			}
			now->next = NULL;
			before->next = now;
			before = now;
		}
	}
	else
	{
		word* target;
		int val;
		int i, j;

		for(i=1; ; i++)
		{
			word* now = (word*)malloc(sizeof(word));
			check = fread(now, sizeof(word), 1, ifp);
			if(!check)
			{
				free(now);
				break;
			}

			target = &head;
			val = rand() % i;
			for(j=0; j<val; j++)
				target = target->next;
			now->next = target->next;
			target->next = now;
		}
	}

	fclose(ifp);

	return head.next;
}

void free_word_list(word* target)
{
	do
	{
		word* next = target->next;
		free(target);
		target = next;
	} while(target != NULL);
}

void create_file(word* target)
{
	overwrite_file(get_last_number()+1, target);
}

static word* get_sorted_word(word* target, int size)
{
	int i;
	word *array;

	array = (word*)malloc(size*sizeof(word));

	for(i=0; target!=NULL; i++)
	{
		array[i] = *target;
		target = target->next;
	}

	qsort(array, size, sizeof(word), compare_word);
	return array;
}

void overwrite_file(int file_number, word* target)
{
	char file_name[100];
	FILE *ofp;
	word *tmp, *array;
	int size, i;

	sprintf(file_name, "%d.dic", file_number);
	if((ofp = fopen(file_name, "wb")) == NULL)
	{
		printf("ERROR - 파일 '%s' 쓰기 실패\n", file_name);
		exit(-1);
	}

	tmp = target;
	for(size=0; tmp!=NULL; size++)
		tmp = tmp->next;

	array = get_sorted_word(target, size);

	for(i=0; i<size; i++)
		fwrite(array+i, sizeof(word), 1, ofp);

	free(array);
	fclose(ofp);
}

int get_last_number()
{
	int file_number = 0;
	char file_name[100];

	do
	{
		sprintf(file_name, "%d.dic", ++file_number);
	} while(fopen(file_name, "rb") != NULL);

	return file_number-1;
}

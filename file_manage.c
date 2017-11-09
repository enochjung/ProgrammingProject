#include "file_manage.h"

word* get_word_list(int file_number, int print_way)
{
	char file_name[100];
	FILE *ifp;
	word head;
	int check;

	sprintf(file_name, "%d.dic", file_number);
	ifp = fopen(file_name, "rb");

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

void overwrite_file(int file_number, word* target)
{
	char file_name[100];
	FILE *ofp;

	sprintf(file_name, "%d.dic", file_number);
	ofp = fopen(file_name, "wb");

	while(target != NULL)
	{
		fwrite(target, sizeof(word), 1, ofp);
		target = target->next;
	}

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

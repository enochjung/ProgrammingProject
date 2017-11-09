#include "word_matching.h"

void word_matching()
{
//
//	word* a = (word*)malloc(sizeof(word));
//	word* b = (word*)malloc(sizeof(word));
//
//	strcpy(a->eng, "apple");
//	a->number = 1;
//	strcpy(a->kor[0], "사과");
//	a->next = b;
//
//	strcpy(b->eng, "banana");
//	b->number = 1;
//	strcpy(b->kor[0], "바나나");
//	b->next = NULL;
//
//	create_file(a);
//
//	free(a);
//	free(b);

	word* head = get_word_list(1, 1);
	
	word* target = head;
	while(target != NULL)
	{
		printf("%s - %s\n", target->eng, target->kor[0]);
		target = target->next;
	}

	free_word_list(head);

	sleep(1);
}

#include "word_matching.h"

void word_matching()
{
	word* a = (word*)malloc(sizeof(word));
	word* b = (word*)malloc(sizeof(word));
	word* c = (word*)malloc(sizeof(word));
	word* d = (word*)malloc(sizeof(word));
	word* e = (word*)malloc(sizeof(word));

	strcpy(a->eng, "apple");
	strcpy(a->kor, "사과");
	a->next = b;

	strcpy(b->eng, "banana");
	strcpy(b->kor, "바나나");
	b->next = c;

	strcpy(c->eng, "crystal");
	strcpy(c->kor, "크리스탈");
	c->next = d;

	strcpy(d->eng, "dragon");
	strcpy(d->kor, "용가리");
	d->next = e;

	strcpy(e->eng, "escape");
	strcpy(e->kor, "탈출하다");
	e->next = NULL;

	overwrite_file(1, a);

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	
	//////////////////////////////////////
	
	//system("clear");
	printf("테스트 전용 창입니다.\n\n");

	word* head = get_word_list(1, 2);
	word* target = head;
	while(target != NULL)
	{
		printf("%s - %s\n", target->eng, target->kor);
		target = target->next;
	}

	free_word_list(head);

	sleep(3);
}

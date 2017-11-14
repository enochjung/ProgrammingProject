#include "flash_card.h"

void flash_card()
{
	int spd,file_number,print_way;
	printf(" 속도(초) : \n");
	scanf(" %d",&spd);
	spd = spd*1000;
	printf(" 파일명(일차) : \n");
	scanf(" %d", &file_number);
	printf("출력방식 : \n");
	scanf(" %d ",&print_way);
	word*head = get_word_list(file_number,print_way);
	for( ; head ;head->next){
		printf(" %s\n", head->eng[0]);
		sleep(spd);
		for(int i =0;i<3;i++)
			printf(" %s \n", head->kor[i]);
	}
	free_word_list(head);
}

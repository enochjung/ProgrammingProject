#include "flash_card.h"
void flash_card()
{
	int spd,file_number,print_way;
	printf("속도(초) : ");
	scanf("%d",&spd);
	printf("파일명(일차) : ");
	scanf("%d", &file_number);
	printf("출력방식(알파벳 순서대로:1, 무작위:2) : ");
	scanf("%d",&print_way);
	word*head = get_word_list(file_number,print_way);
	for(word *t=head; t ; t=t->next){
	        system("clear");
		printf(">>영어 단어 암기 프로그램 : 플래쉬카드<<\n\n\n\n");
		printf("%s\n", t->eng);
		sleep(spd);
		printf(" %s \n", t->kor);
		sleep(spd);
			
	}

	free_word_list(head);
}

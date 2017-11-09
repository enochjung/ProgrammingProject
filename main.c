//#define WORD_MATCHING
//#define FLASH_CARD
//#define HANGMAN
//#define WORDBOOK_MANAGE

#include "header.h"
#include "file_manage.h"

#ifdef WORD_MATCHING
#include "word_matching.h"
#endif

#ifdef FLASH_CARD
#include "flash_card.h"
#endif

#ifdef HANGMAN
#include "hangman.h"
#endif

#ifdef WORDBOOK_MANAGE
#include "wordbook_manage.h"
#endif


int main()
{
	while(1)
	{
		printf(">> 영어 단어 암기 프로그램 <<\n");
		printf("1. 영어 단어 맞추기\t2. 플래쉬카드\n");
		printf("3. 행맨(hangman)\t4. 단어장 관리\n");
		printf("5. 프로그램 종료\n");
		printf("\n");
		printf("번호를 선택하세요: ");
		
		int choice;
		scanf("%d", &choice);
	}
	return 0;
}

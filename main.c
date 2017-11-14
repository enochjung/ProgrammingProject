#define WORD_MATCHING
#define FLASH_CARD
#define HANGMAN
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
	const char* error_str = "";
	int quit = 0;

	srand(time(NULL));

	while(1)
	{
		system("clear");

		printf(">> 영어 단어 암기 프로그램 <<\n");
		printf("1. 영어 단어 맞추기\t2. 플래쉬카드\n");
		printf("3. 행맨(hangman)\t4. 단어장 관리\n");
		printf("5. 프로그램 종료\n");
		printf("\n");
		printf("%s\n", error_str);
		printf("번호를 선택하세요: ");

		error_str = "";
		
		char choice;
		scanf(" %c", &choice);

		switch(choice)
		{
			case '1':
#ifdef WORD_MATCHING
				word_matching();
#else
				error_str = "준비중입니다.";
#endif
				break;

			case '2':
#ifdef FLASH_CARD
				flash_card();
#else
				error_str = "준비중입니다.";
#endif
				break;

			case '3':
#ifdef HANGMAN
				hangman();
#else
				error_str = "준비중입니다.";
#endif
				break;

			case '4':
#ifdef WORDBOOK_MANAGE
				wordbook_manage();
#else
				error_str = "준비중입니다.";
#endif
				break;

			case '5':
				quit = 1;
				break;

			default:
				error_str = "입력에 해당하는 명령이 없습니다.";
				break;
		}

		if(quit)
		{
			system("clear");
			break;
		}
	}
	return 0;
}

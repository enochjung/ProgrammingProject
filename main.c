
// 작성자:김시균
#include "header.h"
#include "file_manage.h"
#include "word_matching.h"
#include "flash_card.h"
#include "hangman.h"
#include "wordbook_manage.h"
int main()
{
	char choice=0, quit=0;
	srand(time(NULL));
	while(1)
	{
		system("clear");
		printf(">> 영어 단어 암기 프로그램 <<\n");
		printf("1. 영어 단어 맞추기\t2. 플래쉬카드\n");
		printf("3. 행맨(hangman)\t4. 단어장 관리\n");
		printf("5. 프로그램 종료\n");
		printf("\n번호를 선택하세요: ");
		scanf(" %c",&choice);
		switch(choice){
			case '1':word_matching();break;
			case '2':flash_card();break;
			case '3':hangman();break;
			case '4':wordbook_manage();break;
			case '5':system("clear");return 0;break;
			default:printf("1~5 사이의 숫자를 입력하세요");break;
	}}
	return 0;
}

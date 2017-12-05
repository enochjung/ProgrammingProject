
//작성자 : 박시균
#include"hangman.h"

void hangman()                                //행맨을 실행하는 함수
{
	int i,file_number, Attempt = 1,life=6;
	char un_line[50]={0};
	char use_str[30]={0};
	char *str;
	char alp_store;
	printf("파일명 : ");
	scanf("%d" ,&file_number);
	word*head=get_word_list(file_number,2);
	for(i=0;i<(int)strlen(head->eng);i++){
		un_line[i*2]='_';
		un_line[i*2+1]=' ';
	}
	
	while(life>0)
	{
		system("clear");
		printf(" >>영어 단어 암기 프로그램 : 행맨 <<\n");
		printf("(힌트)  %s  \n\n",head->kor);
		if(life==6)
			printf("--------------------+\n\n\n\n\n");
      	        else if(life==5){
			printf("--------------------+\n");
			printf("                    o\n\n\n\n");
		}
		else if(life==4){
			printf("--------------------+\n");
			printf("                    o\n");
			printf("                    |\n\n\n");
		}
		else if(life==3){
			printf("--------------------+\n");
			printf("                    o\n");
			printf("                   /|\n\n\n");
		}
		else if(life==2){
			printf("--------------------+\n");
			printf("                    o\n");
			printf("                   /|\\\n\n\n");
		}
		else if(life==1){
		        printf("--------------------+\n");
			printf("                    o\n");
			printf("                   /|\\\n");
			printf("                   / \n\n");
		}

		printf(" %s\n ", un_line);
		
		printf(" %d 번째 시도 : ", Attempt);
		Attempt=Attempt+1;
		scanf(" %c",&alp_store);
		use_str[Attempt-2]=alp_store;
		str=strchr(head->eng,alp_store);
		if(str==NULL)
		{
			life--;
		}
		else
		{
			while(str!=NULL)
			{
				un_line[(int)(str-head->eng)*2]=alp_store;
				str=strchr(str+1,alp_store);
			}
			int success = 0;
			for(i=0;; i++)
			{
				if(head->eng[i]=='\0')
				{
					success = 1;
					break;
				}
				if(un_line[i*2] != head->eng[i])
					break;
			}
			if(success==1)
			{
				printf("#############################\n");
				printf("#############################\n");
				printf("#####Congratulations!!!######\n");
				printf("#############################\n");
				printf("#############################\n");

				getchar();
				getchar();
				break;
			}
		}
	}
	if(life==0)
	{
		printf(" You failed ! \n");
		getchar();
		getchar();
	}
	free_word_list(head);
}

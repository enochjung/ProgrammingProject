#include "hangman.h"

void hangman()
{
	int i,file_number, Attempt = 1,life=6;
	char un_line[]={0};
	char use_str[]={0};
	char *str;
	char alp_store;
	printf("파일명 : ");
	scanf("%d" ,&file_number);
	word*head=get_word_list(file_number,2);
	for(i=0;i<(int)strlen(head->eng);i++)
		un_line[i]='_';
	while(life != 0)
	{
		system("clear");
		printf("(힌트) %s   %s   %s\n",head->kor[0],head->kor[1],head->kor[2]);
		if(life==6)
			printf("--------------------+\n");
      	        else 
			if(life==5){
				printf("--------------------+\n");
				printf("                    o\n");
			}
			else
				if(life==4){
					printf("--------------------+\n");
					printf("                    o\n");
					printf("                    l\n");
				}
				else 
					if(life==3){
						printf("--------------------+\n");
						printf("                    o\n");
						printf("                   /l\\\n");
					}
					else 
						if(life==2){
							printf("--------------------+\n");
							printf("                    o\n");
							printf("                   /l\\\n");
						}
						else
							if(life==1){
								printf("--------------------+\n");
								printf("                    o\n");
								printf("                   /l\\\n");
								printf("                   / \n");
							}

		printf("%d 번째 시도 : ", Attempt);
		printf("%s\n ", un_line);
		Attempt=Attempt+1;
		scanf(" %c ",&alp_store);
		use_str[Attempt-2]=alp_store;
		str=strchr(head->eng,alp_store);
		if(str==NULL)
		{
			printf(" %c 는 이단어에 포함되어 있지 않습니다.\n",alp_store);
			printf(" 목숨이 %d 개 남았습니다.\n",--life);
			printf(" 사용된 알파벳 : \n%s\n",use_str);
		}
		else
		{
			while(str!=NULL)
			{
				un_line[str-head->eng]=alp_store;
				str=strchr(str+1,alp_store);
			}
			printf("%c 는 이단어에 포함되어 있습니다.\n",alp_store);
			printf(" 목숨이 %d 개 남았습니다.\n",life);
			printf(" 사용된 알파벳 : \n%s\n",use_str);
			if(strcmp(un_line,head->eng)==0)
			{
				printf("#############################");
				printf("#####Congratulations!!!######");
				printf("#############################");
				break;
			}
		}
		sleep(1);
	}
	if(life==0)
		printf(" You failed ! \n");
	free_word_list(head);
}

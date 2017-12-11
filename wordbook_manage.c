
#include "wordbook_manage.h"
void add_file();
void add_word();
void print_word();
void print_wordbook();

void wordbook_manage(){
  getchar();
  system("clear");
  printf(">>영어 단어 암기 프로그램 : 단어장 관리<<\n");
  printf("1. 새 파일 추가하기           2.새 단어 추가하기\n");
  printf("3.단어장 보기                 4.단어 파일 목록보기\n");
  printf("5.단어장 관리 종료\n\n\n");
  char choice;
  printf("번호를 입력하세요 : ");
  scanf("%c",&choice);

  switch(choice)
  {
    case '1':  system("clear"); add_file(); break;
    case '2':  add_word(); break;
    case '3':  print_word(); break;
    case '4':  print_wordbook(); break;
    case '5':  system("clear"); break;
    default : printf("1~5까지의 숫자를 입력해 주세요. ");

              wordbook_manage();
               break;
  }
}

void add_file(){
  printf(">>영어 단어 암기 프로그램: 단어장 관리 : 새 파일 추가<<\n");

  word* head=(word*)calloc(1,sizeof(word)); //추가한것
  word* tail=head;
  int i;
  char eng[16];
  char kor[300];
  do
  {
    int i=1;
    scanf("%s",eng);
    if(!strcmp(eng,".add"))
    {
      break;
    }
    scanf("%[^\n]",kor);
    tail->next=(word*)malloc(sizeof(word));
    strcpy(tail->next->eng,eng);
    strcpy(tail->next->kor,kor);
    tail->next->next=NULL;
    tail=tail->next;
    i++;
  }while(strcmp(eng,".add"));
  create_file(head);
  free_word_list(head);
}


void add_word(){
  word* head;
  printf("파일명(일차) :");
  int filenum;
  scanf("%d",&filenum);
  system("clear");
  if(filenum>get_last_number())
  {
    printf("%d.dic 파일은 존재하지 않습니다.다시 입력해주세요. \n",filenum);
    add_word();
    return;
  }
  head = get_word_list(filenum, 1);
  printf(">>영어 단어 암기 프로그램: 단어장 관리 : 새 단어 추가<<\n");
  word* tail=head;
  int i;
  for(i=0;tail->next!=NULL;i++)
    tail=tail->next;
  char eng[16];
  char kor[300];
  do
  {
    int i=1;
    scanf("%s",eng);
    if(!strcmp(eng,".add"))
    {
      break;
    }
    scanf("%[^\n]",kor);
    tail->next=(word*)malloc(sizeof(word));
    strcpy(tail->next->eng,eng);
    strcpy(tail->next->kor,kor);
    tail->next->next=NULL;
    tail=tail->next;
    i++;
  }while(strcmp(eng,".add"));
  overwrite_file(filenum, head);
  free_word_list(head);
}

void print_word(){
    printf("파일명(일차) : ");
    int filenum;
    scanf("%d",&filenum);           //여기 주어진 과제자료에선 엔터 안치던데 알려준게 잘못된듯

    printf("\nㅡㅡㅡㅡㅡ단어장ㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    word* head= get_word_list(filenum,1); //뒤에 알파벳순이라고 안나온것같은데 주어진 자료집에선 a부터 나오는걸로보아 이래해도 될것같음
    word* sion= head;
    while(sion!=NULL)
    {
      printf("%s  %s\n",sion->eng,sion->kor);
      sion=sion->next;
    }
    free_word_list(head);
    getchar();
    getchar();

}

void print_wordbook(){
    int last=get_last_number();
    int n=0; // 5개씩 끊으려공
    printf("ㅡㅡㅡㅡㅡ단어 파일 목록ㅡㅡㅡㅡㅡㅡㅡㅡ\n");
      for(int i=1;i<=last;i++)
      {
        printf("% 3d.dic",i);
        n++;
          if(n%5==0)
            printf("\n");
      }
    printf("\n");
    getchar();
    getchar();
}

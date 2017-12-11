/*typedef struct{
  int number;
  char eng[16];
  char kor[3][61
  word* next]word;*/
#include "word_matching.h"
void word_matching(){
  printf("파일명(일차) : ");
  int filenum;
  int print_way;
  scanf("%d",&filenum);
  printf("출력 방식(알파벳 순서대로 : 1,무작위 :2) : ");
  scanf("%d",&print_way);
  system("clear");

  int num=0, total=0;
  printf(">> 영어 단어 암기 프로그램: 영어 단어 맞추기 <<\n");
  word* head=get_word_list(filenum,print_way);
  word* sion=head;
  char tmp[16]={0};
  printf("%s -> ",head->kor);
  if(head!=NULL)
  {
    scanf("%s",tmp);
    while(strcmp(tmp,".quit"))    //.quit가 눌리지 않으면
    {
      if(!strcmp(tmp,head->eng)) //똑같으면
      {
        printf("correct!\n");
        num++;
      }
      else
        printf("incorrect!\n");

      total++;
      head=head->next;

      if(head==NULL)
        head=sion;

      printf("%s->",head->kor);
      scanf("%s",tmp);
    }
  }
  printf("당신의 점수는 %.2f점입니다. ",((float)num/total)*100);
  free_word_list(sion);
  getchar();
  getchar();
  system("clear");

}

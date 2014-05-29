#include <stdio.h>
#include <string.h>
#define Lmax 20
#define CLR while(fgetc(f)!='\n')

struct Student {
 char group[Lmax];
 struct {
  char fam[Lmax], name[Lmax], s_name[Lmax];
 } fio;
  struct {
      float aver; int b[5];
  } ball;
 Student *next;
};

Student* stack(char _name[])
 {Student *tek, *stack=NULL;
   FILE *f;
   int n;
   if (!(f=fopen(_name, "r")))
   puts("File not found 1");
   else{
     while(!feof(f)){
      tek = new Student;
        if (fgets(tek->group, Lmax, f)){
             tek->group[strlen(tek->group)-1]='\0';
                puts(tek->group);
             fgets(tek->fio.fam, Lmax, f);
             tek->fio.fam[strlen(tek->fio.fam)-1] ='\0';
               puts(tek->fio.fam);
             fgets(tek->fio.name, Lmax, f);
             tek->fio.name[strlen(tek->fio.name)-1]='\0';
               puts(tek->fio.name);
             fgets(tek->fio.s_name, Lmax, f);
             tek->fio.s_name[strlen(tek->fio.s_name)-1]='\0';
               puts(tek->fio.s_name);
             for(int i=0; i<4; i++){
                 fscanf(f,"%d", &tek->ball.b[i]);
                 printf("%d ",tek->ball.b[i]);
                 n=n+tek->ball.b[i];}
             if(!feof(f))CLR;
             printf("\n");
             tek->ball.aver = (float)n/5;
             tek->next=stack;
             stack=tek;
          }
        }
    delete tek;
    }
 return(stack);
 }

void vivod(Student* stack, char name[])
 {FILE *f2;
    if (!(f2=fopen(name, "w")))
    puts("File not found 2");
         if (!stack)
         {
             fprintf(f2,"list after elements removing is empty\n");
         }
         else
         {
             fprintf(f2, "list after elements removing\n");
             //вывод списка в файл
             while(stack!=NULL)
             {
                 fprintf(f2, "Group:%s \n",stack->group);
                 fprintf(f2, "City:%s\n",stack->fio.fam);
                 fprintf(f2, "Factory:%s\n",stack->fio.name);
                 fprintf(f2, "SurName:%s\n",stack->fio.s_name);
             for(int i=0; i<4; i++){
                 fprintf(f2,"%d ", stack->ball.b[i]);
            }
         fprintf(f2, "\n");
         stack=stack->next;
         }
      }
   fclose(f2);
 }

Student* stackres(Student* stack,int l)
{
    Student *f=NULL,*tek, *stackres=NULL,*nec;
    int h,p=0;
    if (!stack)
    puts("No stack");
    else
    while(stack!=NULL)
    {
      h=0;
      for(int i=0; i<4; i++)
          if(stack->ball.b[i] > l)h=1;
        if(h==0){
        if(p==1)
        stackres->next=stack;
        stackres = stack;}
        stack=stack->next;
      if(h==0){
          if(p==0)
       f=stackres;
       p=1;}
    }
    if(stackres!=NULL)stackres->next=NULL;//!!
  return(f); //!!
}

int main()
{
  Student *first;
  Student *firstres;
  int h;
    char name1[Lmax],name2[Lmax];
  printf("Input file name: ");
    gets(name1);
    printf("Output file name: ");
    gets(name2);
    first=stack(name1);
    printf("Input ball: ");
    scanf("%d",&h);
    if (first!=NULL)
     {
         firstres=stackres(first,h);
         vivod(firstres, name2);
         printf("Results saved in file %s\n", name2);
     } else { puts("No stack"); }
 return 0;
}

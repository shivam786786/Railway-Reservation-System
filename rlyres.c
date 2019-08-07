#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
#include<string.h>
#include<dos.h>
#include<time.h>
int enterchoice(){
gotoxy(60,2);
int choice,i;
textcolor(YELLOW);
printf("RAILWAY RESERVATION SYSTEM \n");
srand(time(NULL));
 for(i=0;i<120;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }

    textcolor(YELLOW);
    printf("\n1.View train");
    printf("\n2.Book ticket");
    printf("\n3.View ticket");
    printf("\n4.Search ticket no.");
    printf("\n5.View All booking");
    printf("\n6.View train booking");
    printf("\n7.Cancel train");
    printf("\n8.Cancel ticket");
    printf("\n9.Quit\n\n");
     for(i=0;i<120;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
 textcolor(YELLOW);
    printf("\n\nENTER YOUR CHOICE :- ");

      scanf("%d",&choice);
      return choice;
}
void add_trains()
{
    FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    if(fp == NULL)
    {
        Train alltrains[5]={
        {"123","BPL","GWL",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360},
        {"786","HYD","DEL",6700,4600}

        };
        fp = fopen("f:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,5 * sizeof(Train),1,fp);
        //printf("File saved succesfully");
        fclose(fp);
    }
    else {
           // printf("File already present\n");
        fclose(fp);

    }

}
void view_trains()
{
    FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    int i;
    if(fp == NULL)
    {   textcolor(LIGHTRED);
        delay(100);
        printf("NO DATA FOUND");
    }
    else
    {
       Train t;
       textcolor(WHITE);
    printf("TRAIN NO..\tFROM\tTO\tFIRST AC\tSECOND AC\n");
        for(i=0;i<120;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    textcolor(YELLOW);
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        printf("\n");
        printf("%s\t\t%s\t%s\t%d\t\t%d",t.train_no,t.from,t.to,t.fac_fare,t.sac_fare);
    }

    }
    printf("\n\n");
         for(i=0;i<60;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    fclose(fp);
}
int check_name(char name[]) {
    int i, x = 0, p;
    p = strlen(name);
    for(i = 0; i < p; i++)
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')
            continue;
        else
            return 0;
    return 1;

}

int check_train_no(char *train_no)
{
        FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
        Train t;
        while(fread(&t,sizeof(t),1,fp)==1)
        {
            if(strcmp(t.train_no,train_no)==0)
            {
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
        return 0;

}
int check_mob_no(char *mob_no)
{
    if(strlen(mob_no)!=10)
        return 0;
    while(*mob_no!='\0')
    {
        if(isdigit(*mob_no)==0)
            return 0;
        mob_no++;

    }
    return 1;
}
passenger* get_passenger_details()
{
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name :- ");
    static  passenger psn;
    while(1) {
        fflush(stdin);
    fgets(psn.p_name,20,stdin);
    //("%d",psn.p_name[0]);
    //getch();
    if(psn.p_name[0]=='\n') {
        gotoxy(1,25);
        printf("\t\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("Please Enter a valid Name");
        gotoxy(24,1);
        textcolor(YELLOW);
        continue;
    }
    char* pos;
    pos = strchr(psn.p_name,'\n');
    *pos = '\0';
    if(strcmp(psn.p_name,"0") == 0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        delay(200);
        printf("RESERVATION CANCELLED!");
        return NULL;
    }
    else if(check_name(psn.p_name) == 0) {
         gotoxy(1,25);
        printf("\t\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("Please Enter a valid Name");
        gotoxy(24,1);
        printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        textcolor(YELLOW);
    }
    else
    {
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(1,2);
        break;
    }
    }

    printf("Enter Gender(MALE-M/FEMALE-F) :- ");
    while(1)
    {fflush(stdin);
    scanf("%c",&psn.gender);
    gotoxy(1,25);
    printf("\t\t\t\t\t");
     if(psn.gender == '0')
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        delay(200);
        printf("RESERVATION CANCELLED!");
        return NULL;
    }

    if(psn.gender!='M'&&psn.gender!='F')
    {
        gotoxy(1,25);
        printf("\t\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("ERROR ! GENDER SHOULD BE 'M' OR 'F'");
        gotoxy(1,2);
        textcolor(YELLOW);
        gotoxy(33,2);
        printf("    \b\b\b\b");
    }
    else
    {
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(1,3);
        break;
    }
    }
    printf("Enter train no:-");
    while(1)
    {
        fflush(stdin);
    fgets(psn.train_no,20,stdin);
     char* p;
    p = strchr(psn.train_no,'\n');
    *p = '\0';
     if(strcmp(psn.train_no,"0") == 0)
    {   //clrscr();
        gotoxy(1,25);
         printf("\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("RESERVATION CANCELLED!");
        return NULL;
    }
    if(check_train_no(psn.train_no)==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        delay(200);
        printf("ERROR ! NO SUCH TRAIN FOUND");
        textcolor(YELLOW);
        gotoxy(17,3);
        printf("      \b\b\b\b\b\b");
    }
      else
    {

        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(1,4);
        break;
    }
  }
  printf("Enter age:- ");
  while(1)
  {fflush(stdin);
  int age;
    scanf("%d",&age);
  if(age!=2006001256){
        psn.age = age;
    if(psn.age == 0) {
         gotoxy(1,25);
        textcolor(LIGHTRED);
         printf("\t\t\t\t\r");
         delay(200);
        printf("RESERVATION CANCELLED!");
        textcolor(YELLOW);
        return NULL;
    }
  if(psn.age<0)
  {
      fflush(stdin);
      gotoxy(1,25);
      textcolor(LIGHTRED);
      delay(200);
      printf("\t\t\t\t\t\r");
      printf("ERROR ! AGE SHOULD BE POSITIVE");
      textcolor(YELLOW);
      gotoxy(13,4);
      printf("      \b\b\b\b\b");
  }
  else
  {
        gotoxy(1,25);
        printf("\t\t\t\t\t\r");
        gotoxy(1,5);
        break;
  }

  }
  else {
        textcolor(LIGHTRED);
        gotoxy(1,25);
    printf("ERROR ! Age Should be an integer and Positive");
  textcolor(YELLOW);
    gotoxy(13,4);
    printf("   \b\b\b");
  }
}
  printf("Enter Mobile no:-");
  while(1)
  {
       fflush(stdin);
  fgets(psn.mob_no,20,stdin);
  char* pon;
  pon=strchr(psn.mob_no,'\n');
  if(pon!=NULL)
  *pon='\0';
   if(strcmp(psn.mob_no,"0") == 0)
    {
        //clrscr();
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("RESERVATION CANCELLED!");
        textcolor(YELLOW);
        return NULL;
    }
  if(check_mob_no(psn.mob_no)==0)
  {
       gotoxy(1,25);
      textcolor(LIGHTRED);
      delay(200);
      printf("ERROR ! MOBILE NUMBER SHOULD HAVE ONLY 10 DIGITS AND SHOULD BE NUMBERS");
      textcolor(YELLOW);
      gotoxy(18,5);
      printf("\t       \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  }
  else
  {
    gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,6);
        break;
  }

  }
  printf("Enter class(FIRST-F/SECOND-S):-");
  while(1)
  {
      fflush(stdin);
      scanf("%c",&psn.p_class);
       if(psn.p_class == '0')
    {

        gotoxy(1,25);
        textcolor(LIGHTRED);
         printf("\t\t\t\t\r");
         delay(200);
        printf("RESERVATION CANCELLED!");
        textcolor(YELLOW);
        return NULL;
    }
      if(psn.p_class!='F'&&psn.p_class!='S')
      {
          gotoxy(1,25);
          textcolor(LIGHTRED);
          delay(200);
          printf("Error ! NO SUCH CLASS FOUND");
          textcolor(YELLOW);
          gotoxy(32,6);
          printf(" \b");
      }
      else
      {
          gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(1,7);
        textcolor(YELLOW);
        break;

      }
  }
  printf("Enter address:-");
      fflush(stdin);
      fgets(psn.add,20,stdin);
    char *por;
    por = strchr(psn.add,'\n');
    if(por!=NULL)
      *por = '\0';
      if(strcmp(psn.add,"0")==0)
      {

           gotoxy(1,25);
        textcolor(LIGHTRED);
         printf("\t\t\t\t\r");
         delay(200);
        printf("RESERVATION CANCELLED!");
        textcolor(YELLOW);
        return NULL;
      }

    return &psn;
  }
 int get_booked_ticket_count(char *train,char cls)
 {
   FILE *fp = fopen("f:\\myproject\\allbookings.dat","rb");
     if(fp == NULL)
        return 0;
        int count = 0;
        passenger psg;
        while(fread(&psg,sizeof(passenger),1,fp))
        {
            if(strcmp(psg.train_no,train)==0 && psg.p_class==cls)
                count++;

        }
        fclose(fp);
        return count;
 }
int last_ticket_no()
{
  FILE *fp = fopen("f:\\myproject\\allbookings.dat","rb");
    if(fp == NULL)
        return 0;
    passenger psg;
    while(fread(&psg,sizeof(passenger),1,fp));
    fclose(fp);
    return psg.ticket_no;
}
int book_ticket(passenger p)
{

    int x = get_booked_ticket_count(p.train_no,p.p_class);
    if(x == 30)
        return -1;
    int y = last_ticket_no() + 1;

     FILE *fp = fopen("f:\\myproject\\allbookings.dat","ab");
     if(fp == NULL)
        exit(1);
     p.ticket_no = y;
     fwrite(&p,sizeof(passenger),1,fp);
     fclose(fp);
     return y;
}
void view_ticket(int ticket_no)
{
    passenger psn;
    Train tr;
    int x = 0;
   FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    if(fp == NULL || fr == NULL)
    {    textcolor(LIGHTRED);
        gotoxy(1,25);
        delay(200);
        printf("ERROR ! NO RECORD FOUND");
        return;
    }
    textcolor(LIGHTMAGENTA);

    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(ticket_no == psn.ticket_no)
        {
             x = 1;
             textcolor(LIGHTCYAN);
             printf("NAME:- %s\nGENDER:- %c\nTRAIN NO:- %s\nAGE:- %d\nMOBILE NO:- %s\nCLASS:- %c\nTICKET NO:- %d\nADDRESS:- %s\n",psn.p_name,psn.gender,psn.train_no,psn.age,psn.mob_no,psn.p_class,psn.ticket_no,psn.add);
             while(fread(&tr,sizeof(Train),1,fp))
             {
                 if(strcmp(psn.train_no,tr.train_no)==0)
                 {
                    if(psn.p_class == 'S')
                     printf("FROM:- %s\nTO:-%s\nFARE:-%d\n",tr.from,tr.to,tr.sac_fare);
                    else
                      printf("FROM:- %s\nTO:-%s\nFARE:-%d\n",tr.from,tr.to,tr.fac_fare);
                     break;
                 }

             }
             textcolor(YELLOW);

          break;
       }

}
if(x == 0 && ticket_no <= last_ticket_no() + 1)
{
            textcolor(LIGHTRED);
            printf("TICKET NUMBER %d IS CANCELLED",ticket_no);
            textcolor(YELLOW);
            fclose(fp);
            fclose(fr);
            return;


}
if(x == 0)
       {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            delay(200);
            printf("INVALID TICKET NUMBER");
            textcolor(YELLOW);

       }
       fclose(fp);
       fclose(fr);
}
int accept_ticket_no()
{

    int ticket_no;
     gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter ticket no:- ");
    while(1)
    {
       scanf("%d",&ticket_no);
       if(ticket_no == 0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
         printf("\t\t\t\t\r");
         delay(200);
        printf("CANCELLING PROCESS IS CANCELLED!");
        textcolor(YELLOW);
        return 0;
    }

    if(ticket_no<0)
       {   gotoxy(1,25);
       textcolor(LIGHTRED);
       delay(200);
           printf("TICKET NUMBER SHOULD BE POSITIVE");
           textcolor(YELLOW);
           gotoxy(18,1);
           printf("   \b\b\b");

       }
    else
    {
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(100,1);
        printf("\t\t\t");
        gotoxy(1,2);
         return ticket_no;
    }

    }




}
int  cancel_ticket(int ticket_no)
{
    FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    FILE *fp = fopen("f:\\myproject\\temp.dat","wb");

    if(fr == NULL)
    {
        printf("NO BOOKINS DONE YET");
        return -1;
    }
    passenger psn;
    int flag = 0;
    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(psn.ticket_no != ticket_no)
        {
            fwrite(&psn,sizeof(passenger),1,fp);

        }
        else
            flag = 1;

    }
    fclose(fr);
    fclose(fp);
    if(flag == 1)
    {
        remove("f:\\myproject\\allbookings.dat");
        rename("f:\\myproject\\temp.dat","f:\\myproject\\allbookings.dat");

    }
    else
    {
       remove("f:\\myproject\\temp.dat");
       fclose(fp);
       fclose(fr);
    }
    return flag;

}

char * accept_train_no()
{
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("PRESS 0 TO EXIT");
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("Enter train no:- ");
    static char train_no[10];
    int check;
    fflush(stdin);


    while(1)
    {   scanf("%s",&train_no);
        if(strcmp(train_no,"0") == 0)
        {   clrscr();
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t\t\r");
            delay(200);
            printf("CANCELLING TRAIN PROCESS IS CANCELLED");
            textcolor(YELLOW);
            return NULL;
        }
         check = check_train_no(train_no);
        if(check == 0)
        {
            gotoxy(1,25);
             textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t\t\r");
            delay(200);
            printf("INVALID TRAIN NUMBER");
            gotoxy(17,1);
            printf("     \b\b\b\b\b");
            textcolor(YELLOW);

        }
        else
        {
            gotoxy(1,25);
            printf("\t\t\t\t\t");
            gotoxy(1,1);
            return train_no;

        }

    }

}
int cancel_train(char *train_no)
{
   FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    FILE *fp = fopen("f:\\myproject\\temp.dat","wb");
    if(fr == NULL)
    {
        printf("NO BOOKINGS DONE YET");
        return -1;
    }
    if(fp == NULL)
    {
        printf("TEMPORARY FILE CANNOT OPEN");
        return -1;
    }
    passenger psn;
    int flag = 0;
    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(strcmp(psn.train_no,train_no)!=0)
           {
            fwrite(&psn,sizeof(passenger),1,fp);
           }
        else
            flag = 1;
    }
    fclose(fp);
    fclose(fr);
    if(flag == 0)
    {
        remove("f:\\myproject\\temp.dat");
    }
    else
    {
        remove("f:\\myproject\\allbookings.dat");
        rename("f:\\myproject\\temp.dat","f:\\myproject\\allbookings.dat");
    }
    return flag;

}
char *accept_mob_no()
{
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("PRESS 0 TO EXIT");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter Mobile no:-");
  while(1)
  {
       fflush(stdin);
      static char mob_no[20];
  fgets(mob_no,20,stdin);
  char* pon;
  pon=strchr(mob_no,'\n');
  if(pon!=NULL)
  *pon='\0';
   if(strcmp(mob_no,"0") == 0)
    {   clrscr();
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\r");
        textcolor(LIGHTRED);
        delay(200);
        printf("INPUT CANCELLED");
        textcolor(YELLOW);
        return NULL;
    }
  if(check_mob_no(mob_no)==0)
  {
       gotoxy(1,25);
      textcolor(LIGHTRED);
      delay(200);
      printf("ERROR ! MOBILE NUMBER SHOUD HAVE 10DIGITS AND SHOULD ONLY BE DIGITS");
      textcolor(YELLOW);
      gotoxy(18,1);
      printf("\t       \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  }
  else
  {
    gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,1);
        return mob_no;
  }

  }
}
int * get_ticket_no(char * mob_no)
{
    FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    if(fr == NULL)
    {
        return NULL;
    }
    int count = 0;
    passenger psn;
    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(strcmp(psn.mob_no,mob_no)==0)
        {
            count++;
        }
    }
    if(count == 0)
    {
        fclose(fr);
        return NULL;
    }
    int i = 0;
    rewind(fr);
    int *p = (int *)malloc((count+1)*sizeof(int));
    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(strcmp(psn.mob_no,mob_no)==0)
        {
            *(p+i)=psn.ticket_no;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fr);
    return p;
}

void view_all_tickets(char *mob_no,int *ticket_no)
{   clrscr();
    FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    Train tr;
    passenger psn;
    if(fr == NULL)
    {
        printf("NO TICKET BOOKED AGAINST THIS MOBILE NUMBER %s",mob_no);
        return;
    }
    if(ticket_no == NULL)
    {   textcolor(LIGHTRED);
        printf("NO TICKET BOOKED AGAINST THIS MOBILE NUMBER %s",mob_no);
        return;
    }
    textcolor(WHITE);
    printf("FOLLOWING ARE THE TICKETS BOOK AGAINST THIS MOBILE NUMBER %s",mob_no);
    int i = 0;
    textcolor(LIGHTCYAN);
    printf("\n\nTicket No\tClass\tName\t\tGender\tAge\tTrain No\tFrom\tTo\tFare\n");
    //textcolor(LIGHTMAGENTA);
    int j;
         for(j=0;j<120;j++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    textcolor(YELLOW);
    while(*(ticket_no + i)!=-1)
    {
        while(fread(&psn,sizeof(passenger),1,fr))
        {
            if(psn.ticket_no == *(ticket_no+i))
            {
               printf("\n%d\t\t%c\t%s\t%c\t%d\t%s\t",psn.ticket_no,psn.p_class,psn.p_name,psn.gender,psn.age,psn.train_no);
               while(fread(&tr,sizeof(Train),1,fp))
              {
                   if(strcmp(psn.train_no,tr.train_no)==0)
               {
                if(psn.p_class == 'S')
                        printf("\t%s\t%s\t%d",tr.from,tr.to,tr.sac_fare);
                else
                     printf("\t%s\t%s\t%d",tr.from,tr.to,tr.fac_fare);
                     rewind(fp);
                     break;

               }
              }
               break;
            }
        }
        i++;

    }

printf("\n\n");
 for(j=0;j<60;j++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    fclose(fr);
    fclose(fp);
}


void view_booking(char* train_no)
{
    clrscr();
    FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
    FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    Train tr;
    if(fr == NULL)
    {
        printf("NO TICKET BOOKED AGAINST THIS TRAIN NUMBER %s",train_no);
        return;
    }
    passenger psn;
    int flag = 0;
    textcolor(WHITE);
     printf("FOLLOWING ARE THE TICKETS BOOK AGAINST THIS TRAIN NUMBER %s",train_no);
     textcolor(LIGHTCYAN);
    printf("\n\nTicket No\tClass\tName\t\tGender\tAge\tMobile No\tFrom\tTo\tFare\n");
    textcolor(LIGHTMAGENTA);
    int i;
    for(i=0;i<120;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    textcolor(YELLOW);
    while(fread(&psn,sizeof(passenger),1,fr))
    {
        if(strcmp(psn.train_no,train_no)==0)
        {
            flag = 1;
          printf("\n%d\t\t%c\t%s\t%c\t%d\t%s",psn.ticket_no,psn.p_class,psn.p_name,psn.gender,psn.age,psn.mob_no);
           while(fread(&tr,sizeof(Train),1,fp))
              {
                   if(strcmp(psn.train_no,tr.train_no)==0)
               {
                if(psn.p_class == 'S')
                        printf("\t%s\t%s\t%d",tr.from,tr.to,tr.sac_fare);
                else
                     printf("\t%s\t%s\t%d",tr.from,tr.to,tr.fac_fare);
                     rewind(fp);
                     break;
               }
              }
        }
    }

    if(flag == 0)
    {   clrscr();
        textcolor(LIGHTRED);
        delay(200);
        printf("NO TICKETS BOOKED IN TRAIN NUMBER %s FOUND",train_no);
    }
     printf("\n");
   for(i=0;i<60;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    fclose(fr);
    fclose(fp);
}
void view_all_bookings()
{
   FILE *fr = fopen("f:\\myproject\\allbookings.dat","rb");
   FILE *fp = fopen("f:\\myproject\\alltrains.dat","rb");
    Train tr;
    if(fr == NULL||fp==NULL)
    {   textcolor(LIGHTRED);
        printf("NO BOOKINGS DONE YET");
        return;
    }
   textcolor(WHITE);
   int flag = 0;
   printf("FOLOWING TICKETS ARE BOOKED");
   textcolor(LIGHTCYAN);
    printf("\n\nTicket No\tClass\tName\t\tGender\tAge\tMobile No\tTrain no\tFrom\tTo\t\tFare\n");
    textcolor(LIGHTMAGENTA);
    int i;
         for(i=0;i<120;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    textcolor(YELLOW);
    passenger psn;
    while(fread(&psn,sizeof(passenger),1,fr))
    {
      printf("\n%d\t\t%c\t%s\t%c\t%d\t%s\t%s\t",psn.ticket_no,psn.p_class,psn.p_name,psn.gender,psn.age,psn.mob_no,psn.train_no);
      while(fread(&tr,sizeof(Train),1,fp))
              {
                   if(strcmp(psn.train_no,tr.train_no)==0)
               { flag = 1;
                if(psn.p_class == 'S')
                        printf("\t%s\t%s\t%d",tr.from,tr.to,tr.sac_fare);
                else
                     printf("\t%s\t%s\t%d",tr.from,tr.to,tr.fac_fare);
                     rewind(fp);
                     break;
               }
              }


    }
    if(flag == 0)
    {
        clrscr();
        textcolor(LIGHTRED);
        delay(200);
        printf("NO BOOKINGS DONE YET");
    }
    printf("\n\n");
    textcolor(LIGHTMAGENTA);
        for(i=0;i<60;i++)
 {
     textcolor((rand()%14)+1);
     printf("**");

 }
    fclose(fr);
    fclose(fp);

}

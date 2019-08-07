#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include "rlyres.h"

int main()
{
    int choice;
    add_trains();
    passenger *ptr;
    int ticket_no;

    while(1)
    {
         choice = enterchoice();
         if(choice == 9)
            exit(0);
         switch(choice)
         {
         case 1:
             //view trains
             clrscr();
             view_trains();
              textcolor(WHITE);
             printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
             getch();
             clrscr();
             break;
         case 2:
            //book tickets
            clrscr();
            ptr = get_passenger_details();
            if(ptr!=NULL)
            {
              ticket_no = book_ticket(*ptr);
            if(ticket_no == -1)
               {
                clrscr();
                textcolor(WHITE);
                printf("TICKET CANNOT BE BOOKED\nSEATS ARE NOT AVAILABLE");
                 printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
                getch();
                clrscr();
                break;

            }
            textcolor(LIGHTCYAN);
            clrscr();
            printf("YOUR TICKET IS BOOKED \nTICKET NUMBER is %d",ticket_no);
            }
            textcolor(WHITE);
             printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
            getch();
            clrscr();
            break;
         case 3:
            //view ticket
            clrscr();
            ticket_no = accept_ticket_no();
            if(ticket_no!=0)
           {
                view_ticket(ticket_no);
           }
            textcolor(WHITE);
            printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
            getch();
            clrscr();
            break;
         case 4:
             //search ticket no.
             clrscr();
             char *mob_no;
             int *tktno;
             if(mob_no!=NULL)
             {
                 mob_no = accept_mob_no();
                 tktno = get_ticket_no(mob_no);
                 view_all_tickets(mob_no,tktno);
             }
             textcolor(WHITE);
             printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
             textcolor(YELLOW);
            getch();
            clrscr();

            break;
         case 5:
             //view all booking
             clrscr();
              view_all_bookings();
               textcolor(WHITE);
             printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
             textcolor(YELLOW);
            getch();
            clrscr();
            break;
         case 6:
             //view train booking
             clrscr();
             char *train_no;
             train_no=accept_train_no();
             if(train_no!=NULL)
             {
                 view_booking(train_no);

             }
             textcolor(WHITE);
             printf("\n\nPRESS ANY KEY TO BACK MAIN MENU");
             textcolor(YELLOW);
            getch();
            clrscr();

            break;

         case 7:
             //cancel train
             clrscr();
             char *ptrain;
             int check;
             ptrain = accept_train_no();
             textcolor(WHITE);
             if(ptrain!=NULL)
             {
               check = cancel_train(ptrain);
               if(check == 0)
               {
                   printf("SORRY ! NO TICKETS FOUND IN THIS TRAIN");

               }

               else
                {   textcolor(LIGHTCYAN);
                    printf("TRAIN NUMBER %s IS CANCELLED SUCCESSFULLY",ptrain);
                }
            }
                textcolor(WHITE);
               printf("\nPRESS ANY KEY TO BACK MENU");
               getch();
               clrscr();
               break;

         case 8:
             //cancel ticket quit
             clrscr();
             int ticketno;
             int status;
             ticketno = accept_ticket_no();
             if(ticketno == 0)
             {
                 textcolor(WHITE);
                 printf("\nPRESS ANY KEY TO BACK MENU");
                 getch();
                 textcolor(YELLOW);
                 clrscr();
                 break;
             }
            status = cancel_ticket(ticketno);
            clrscr();
            if(status == -1)
            {
                textcolor(WHITE);
                printf("\nPRESS ANY KEY TO BACK MENU");
                 getch();
                 textcolor(YELLOW);
                 clrscr();
                 break;

            }
          else  if(status == 1)
            {
                textcolor(LIGHTRED);
                printf("TICKET NO %d CANCELLED SUCCESSFULLY",ticketno);
                textcolor(WHITE);
                printf("\nPRESS ANY KEY TO BACK MENU");
                 getch();
                 textcolor(YELLOW);
                 clrscr();
                 break;

            }
            else
            {
                textcolor(WHITE);
                clrscr();
                printf("NO RECORD FOUND");
                printf("\nPRESS ANY KEY TO BACK MENU");
                 getch();
                 textcolor(YELLOW);
                 clrscr();
                 break;

            }
            break;
         default:
            textcolor(LIGHTRED);
            printf("WRONG CHOICE ! TRY AGAIN");
            getch();
            clrscr();
      }


    }
    return 0;
}

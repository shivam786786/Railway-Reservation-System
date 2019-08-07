#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED


struct Train{
char train_no[20];
char from[20];
char to[20];
int fac_fare;
int sac_fare;
};//structure for train
typedef struct Train Train;

struct passenger{
char p_name[20];
char add[20];
char gender;
char mob_no[20];
int age;
char train_no[20];
char p_class;
int ticket_no;
};//structure for passenger
typedef struct passenger passenger;

int enterchoice();
void add_trains();
void view_trains();
int book_ticket(passenger);
int * get_ticket_no(char *);
void view_ticket(int);
void view_all_bookings();
int view_bookings(char *);
int cancel_ticket(int);
int cancel_train(char*);
int check_train_no(char*);
passenger* get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char *);
int accept_ticket_no();
char * accept_train_no();
char* accept_mob_no();
void view_all_tickets(char *,int *);
void view_booking(char*);
int booked_ticket_count(char *train);










#endif // RLYRES_H_INCLUDED

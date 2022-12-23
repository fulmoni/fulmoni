#include<stdio.h>
#include<stdlib.h>

void login()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="username";
    char pass[10]="password";
    FILE *fp;
    fp = fopen("BookedSeat.txt","w");
    fclose(fp);

    do
{

        printf("\n\t\t\t\t\t\t     *************************************************** ");
        printf("\n\t\t\t\t\t\t     ************************ LOGIN FIRST ************** ");
        printf("\n\t\t\t\t\t\t     *************************************************** ");
        printf(" \n\n     ENTER USERNAME:- ");
        scanf("%s",&uname);
        printf(" \n\n     ENTER PASSWORD:- ");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13)
                break;
            else
                printf("*");
            i++;
        }






   pword[i]='\0';
 //char code=pword;
   i=0;
 //scanf("%s",&pword);
   if(strcmp(uname,"username")==0 && strcmp(pword,"password")==0)
   {
       printf("\n\t\t\t\t\t\t\t*********** LOGIN IS SUCCESSFUL******");
       printf("\n\t\t\t\t\t\t\t*********** WELCOME TO OUR BOOKING SYSTEM");
       printf("\n\t\t\t\t\t\t\t\t\t\t\t Press any key to continue ....");
       getch();//Holds the screen
       break;
   }
   else
   {
     printf("\n          LOGIN IS  UNSUCCESSFUL \n Try again !!!\n");
     a++;
     getch();//holds the screen
   }
}

   while(a<=2);
   if(a>2)
   {
     printf("\n Sorry you have entered the wrong username and password for three times !!!");
     getch();
     exit(0);
   }
   system("cls");
}

// part 2
struct Booking
{
    char code[20];
    char name[20];
    char date[20];
    char time[20];
    int cost;
};

struct Booking b[100];
int seat =50;

void movie_details();
void buy_ticket();
void old_record();
void main()
{
    login();
    int ch;
    do{
        printf("\n\t\t\t\t\t\t++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf("\n\t\t\t\t\t\t        MOVIE TICKET BOOKING ");
        printf("\n\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++");

        printf("Enter <1> For Movie Details\n");
        printf("Enter <2> For Buy Ticket\n");
        printf("Enter <3> TO View All Transactions\n");
        printf("Enter <4> To Exit\n");

        printf("Enter Your Choice : ");
        scanf("%d",&ch);
           system ("cls");

        switch (ch)
        {
           case 1:
                movie_details();
           break;

           case 2:
               buy_ticket();
           break;

           case 3:
              old_record();
           break;

           case 0:
               exit(0);
           break;

           default:
              printf("Wrong choice!");
           break;
        }
    } while (ch!=0);

}
//Part 3
void movie_details()
{
    char ch;
    FILE *fp;

    fp= fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("file does not found!");
        exit(1);
    }
    else
    {
        system("cls");
        while((ch = fgetc(fp))!=EOF )
            printf("%c",ch);

    }
    fclose(fp);

}
//for ticket booking
void buy_ticket()
{
    int count=0;
    //struct book b;
    FILE *fp;
    FILE *ups;
    FILE *ufp;

    int total_seat,mobile,total_amount;
    char name[20];

     char ch;//used in display all movies
     char movie_code[20];//for searching
     //display all movies by default for movie code
     fp = fopen("data.txt","r");
     if(fp == NULL)
     {
         printf("file does not found!");
         exit(1);
     }
     else
     {
         system ("cls");
         while((ch = fgetc(fp)) != EOF )
            printf("%c",ch);
     }
     fclose(fp);

     //display ends
     printf("\n to Buy Ticket Choice Movie(Enter the number of Movie)\n");
     printf("\n Enter movie code: ");
     scanf("%s",movie_code);
     //system("clear");
     fp = fopen("data.txt","r");
     if(fp == NULL)
     {
         printf("file does not found!");
         exit(1);
     }
     else
     {
         while(getc(fp)!=EOF)
         {
             fscanf(fp,"%s %s %s %s %d",b[count].code,b[count].name,b[count].date,b[count].time,&b[count].code,&b[count].name,&b[count].date,&b[count].time);
              if(strcmp(b[count].code,movie_code)==0)
              {
                  printf("\n Record Found\n");
                  printf("\n\t\tCode:%s",b[count].code);
                  printf("\n\t\tMovie name:%s",b[count].name);
                  printf("\n\t\tDate:%s",b[count].date);
                  printf("\n\t\tPrice of ticket:%dTK",b[count].cost);

                  break;
              }
              count++;
         }




              }
              printf("\n Fill Details *");
              printf("\n Your name: ");
              scanf("%s",name);
              printf("\n Mobile number: ");
              scanf("%d",&mobile);
              printf("\n Total number of tickets: ");
              scanf("%d",&total_seat);
              if(total_seat>=10)
              {
                  printf("You can't book those amount of tickets\n");
                  printf("Please book between 10 tickets\n");
                  printf("\nPlease re-enter total number of tickets: ");
                  scanf("%d",&total_seat);
            }


       int i,j;
       int seat[10];
       printf("\n\t\t\t\t                                       SCREEN\n\n\n");
       for(i=1;i<100;i++)
       {
           printf("%d\t",i);

           printf("\t",i);
           if(i%10==0)
           printf("\n\n");
       }
       printf("\n Booked seats\n");
       fp = fopen("Bookseat.txt","r");
       if(fp == NULL)
       {
        printf("file does not found!");
         exit(1);
       }
       else
       {
         while((ch = fgetc(fp)) != EOF )
            printf("%c",ch);
       }
       fclose(fp);
       printf("\n These seats are booked for %s Movie",b[count].name);
       printf("\n Please choose others seats");
       for(i=1;i<=total_seat;i++)
        printf("\n Choose seat number: ");
       scanf("%d",&j);


       if(j=100 || j<1)
       {
           printf("%d seat is unavailable in this theater\n",j);
           printf("Please re-enter seat number: ");
           scanf("%d",&j);
       }
            ufp = fopen("Bookedseat.txt","a");
       if(ufp == NULL)
       {
           printf("File does not found");
       }
       else
       {
           fprintf(ufp,"%d\n",j);
           printf("\n Record insert Successful to the Booked seat file");
           seat[i-1]=j;
       }
       printf("\n");
       fclose(ufp);
       fclose(fp);



 total_amount = b[count].cost * total_seat;

  printf("\n\t\t\t\t\t\t\t----------------THEATER BOOKING TICKET--------\n");
  printf("\n\t\t\t\t\t\t\t===============================================\n");
  printf("\n\n\n\t\t\t\tName:%s                     \t\t\t\tMovie Name:%s\n",name,b[count].name);
  printf("\n\n\n\t\t\t\tMobile Number:%d                  \t\t\t\tDate :%s\n",mobile,b[count].date);
  printf("\n\n\n\t\t\t\t                     Time:%s\n",b[count].time);
  printf("\n\n\n\t\t\t\t                     Total Seats :%d\n",total_seat);
  printf("\n\n\n\t\t\t\t                     Cost Per Ticket : %d TK",b[count].cost);
  printf("\n\n\n\t\t\t\t                     Total Amount : %d TK",total_amount);
  printf("\n\n\n\t\t\t\t                     Seat Number : ");
  for (i=1;i<=total_seat;i++)
  {
    printf("%d",seat[i-1]);
  }
  printf("\n");

  printf("\t\t\t\t\t\t\t           PAYMENT                          \n");
  printf("\t\t\t\t\t\t\t*****************SHONALI BANK***************************\n");
  printf("\n Merchant Number : 01234567890\n");
  printf("\nYour Number:%d\n",mobile);
  printf("\n Total Amount:%d TK\n",total_amount);
  printf("\n\n\n\t\t\t\t**************Booking Confirmed********** \n");
  printf("\n\n\n\t\t\t\t**************ENJOY YOUR MOVIE********** \n");


  ups=fopen("oldTransaction.txt","a");
  if (ups==NULL)
  {
    printf("File not Found");
  }
  else
  {
    fprintf(ufp,"%s %d %d %d %s %d %s %s\n",name,mobile,total_seat,total_amount,b[count].name,b[count].cost,b[count].date,b[count].time);
    printf("\n Record insert Successful to the old record file");
  }
    printf("\n");
   fclose(ufp);
   fclose(fp);
   }

//for view all user transactions
void old_record()
{
    char ch;
    FILE *fp;

    //system("clear");
    fp = fopen("oldTransaction.txt","r");
    if(fp==NULL)
    {
        printf("file does not found! ");
        exit(1);
    }
    else
    {
       system("cls");
       while((ch = fgetc(fp) )!= EOF )
        printf("%c",ch);
    }
    fclose(fp);

}


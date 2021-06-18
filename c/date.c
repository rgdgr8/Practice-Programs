#include<stdio.h>
enum month{jan=1,feb,mar,apr,may,jun,july,aug,sep,oct,nov,dec};
typedef enum month month;

typedef struct{
month m;
int day;
}date;

char* print_month(month m){//function to print month
 switch(m){
       case jan:return "January";break;
       case feb:return "February";break;
       case mar:return "March";break;
       case apr:return "April";break;
       case may:return "May";break;
       case jun:return "June";break;
       case july:return "July";break;
       case aug:return "August";break;
       case sep:return "September";break;
       case oct:return "October";break;
       case nov:return "November";break;
       case dec:return "December";break;
 }
}

int in_range(int day, month m){//function to check if the day is valid for the given month
 if(day>31)
   return 0;

 if(m==2 && day>28)//for february
   return 0;
 
 if((m==4 || m==6 || m==9 || m==11) && m>30)//for all 30 day months
   return 0;

 return 1;
}

date next_day(date d){//function to calculate next day
 date nd;
 if(d.m==dec && d.day ==31){//special case 31st december changes to 1st january
   nd.m = 1;
   nd.day = 1;
   return nd;
 }

 if(d.m==2){//for feb
   if(d.day<28){
     nd.m = d.m;
     nd.day = (d.day+1);
   }
   else{
     nd.m = (d.m+1);
     nd.day = 1;
   }

   return nd;
 }
   
 if((d.m==4 || d.m==6 || d.m==9 || d.m==11)){//for 30 day months
   if(d.day<30){
     nd.m = d.m;
     nd.day = (d.day+1);
   }
   else{
   nd.m = (d.m+1);
   nd.day = 1;
   }

   return nd;
 }
 
 if((d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12)){//for 31 day months
   if(d.day<31){
     nd.m = d.m;
     nd.day = (d.day+1);
   }
   else{
   nd.m = (d.m+1);
   nd.day = 1;
   }

   return nd; 
 }
 return nd;
}

int main()
{ 
 printf("Enter a number between 1 and 12, e.g. 1(for January) and 4(for April):");
 month m;
 scanf("%d",&m);
 while(m<1 || m>12){//if invalid month is entered
      printf("Enter a number between 1 and 12 only!:");
      scanf("%d",&m);
 }
 printf("Enter a day:");
 int day;
 scanf("%d",&day);
 while(day<=0 || in_range(day,m)==0){//if invalid day is entered
      printf("Enter a valid day for the month:");
      scanf("%d",&day);
 }
 
 date d = {m,day};
 printf("Your date is: %s %d\n",print_month(d.m),d.day);//print the entered date
 date nd = next_day(d);
 printf("Next day is: %s %d\n",print_month(nd.m),nd.day);//print the next date 
 return 0;
}

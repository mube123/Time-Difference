#include <iostream>
using namespace std;
struct TIME {
   int seconds;
   int minutes;
   int hours;
};

void differenceBetweenTimePeriod(struct TIME t1,
                                 struct TIME t2,
                                 struct TIME *diff);

int main() {
   struct TIME startTime, stopTime, diff;

   cout<<"Enter the start time. \n";
   cout<<"Enter hours, minutes and seconds: ";
   cin>>startTime.hours>>startTime.minutes>>startTime.seconds;

   cout<<"Enter the stop time. \n";
   cout<<"Enter hours, minutes and seconds: ";
   cin>>stopTime.hours>>stopTime.minutes>>stopTime.seconds;

   // Difference between start and stop time
   differenceBetweenTimePeriod(startTime, stopTime, &diff);
   cout<<"\nTime Difference:"<<startTime.hours<<":"<<startTime.minutes<<":"<<startTime.seconds;
   cout<<"-"<<stopTime.hours<<":"<<stopTime.minutes<<":"<<stopTime.seconds<<" = "<<diff.hours<<":"<<diff.minutes<<":"<<diff.seconds;
   return 0;
}

// Computes difference between time periods
void differenceBetweenTimePeriod(struct TIME start,
                                 struct TIME stop,
                                 struct TIME *diff) 
{
   while (stop.seconds > start.seconds) 
   {
      --start.minutes;
      start.seconds += 60;
   }
   diff->seconds = start.seconds - stop.seconds;
   
   
   while (stop.minutes > start.minutes) 
   {
      --start.hours;
      start.minutes += 60;
   }
   diff->minutes = start.minutes - stop.minutes;
   
   
   diff->hours = start.hours - stop.hours;
}

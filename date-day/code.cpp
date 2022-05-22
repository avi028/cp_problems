/*
*Problem :
Given a date, determine what is the day (Monday, Tuesday, . . . , Sunday) of that date?
(e.g. 9 August 2010 – the launch date of the first edition of this book – is Monday)
*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i,d,m,y,\
    month_code [12]={0,3,3,6,1,4,6,2,5,0,3,5},\
    cen_code [7]= {4,2,0,6,4,2,0},\
    cen_number[7] = {17,18,19,20,21,22,23};

  string month,\
    days[7] = {"Monday","Tuesday","Wednesday","Thursday","Firday","Saturday","Sunday"},\
    months[12]= {"January", "Febuary","March","April","May","June","July","August","September","October","November","December"};

  cin>>d>>month>>y;

  for(i=0;i<12;i++){if(month.compare(months[i])==0)break;}
  /*centuary code + year code + month code + day - leap year code */  

  d = cen_code[(y/100)-17] +\
      ((y%100)+((y%100)/4))%7 + \
      month_code[i] + \
      + d +\
      (((i==0 || i==1) && ((y%4==0 && y%100!=0) || (y%400)==0))?-1:0);

  cout<< days[d%7 -1];    

  return 0;
}

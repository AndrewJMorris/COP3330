// Andrew Morris
// time.cpp
// Due June 16
#include <iostream>
#include <iomanip>
#include "time.h"

//Constructors (One for no param, one for seconds as a param, one for 4 params)
Time::Time()
{
  days = 0;
  hours = 0;
  minutes = 0;
  seconds = 0;
}
Time::Time(int s)                     
{
  if (s < 0)
  {
    days = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
  }
  else
  {
    if (s > 60)
    {
      seconds = s % 60;
      minutes = seconds % 60;
      hours = s % 3600;
      days = s / 86400;
    }
    callcheckTime(days,hours,minutes,seconds);
  }
}
Time::Time(int d, int h, int m, int s)
{
  callcheckTime(d,h,m,s);
}

void Time::checkTime(int &d, int &h, int &m, int &s)
{
  if (d < 0 || h < 0 || m < 0 || s < 0)
  {
    days = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
  }
else if (h >= 24)
  {
    while (h >= 24)
    {
      d++;
      h = h - 24;
    }
  }
else if (m >= 60)
  {
   while (m > 60)
   {
     h++;
     m = m - 60;
   }
  }
if (s >= 60)
  {
    m++;
    s = s - 60;
  }
}

void Time::callcheckTime(int &d, int &h, int &m, int &s)
{
  checkTime(d,h,m,s);
}

//---------------- FRIEND FUNCTIONS -----------------//

// Insertion and extraction operator overload to set the default formatting for output.
ostream& operator<<(ostream& s , const Time& t )
{
  s <<  t.days << "~" << setw(2) << setfill('0') << t.hours << ":" << setw(2) << setfill('0') << t.minutes << ":" << setw(2) << setfill('0') << t.seconds;

  return s;
}
istream& operator>>(istream& s, Time& t)
{
  s >> t.days >> t.hours >> t.minutes >> t.seconds;
  t.callcheckTime(t.days, t.hours, t.minutes, t.seconds);

  return s;
} 

// Aiddtional arithmetic operator overload functions
Time operator+(const Time& t1 , const Time& t2)
{
  Time r;

  r.days = (t1.days + t2.days);
  r.hours = (t1.hours + t2.hours);
  if (r.hours >= 24)
  {
    while (r.hours >= 24)
    {
      r.days++;
      r.hours = r.hours - 24;
    }
  }
  r.minutes = (t1.minutes + t2.minutes);
  if (r.minutes >= 60)
  {
    while (r.minutes >= 60)
    {
      r.hours++;
      r.minutes = r.minutes - 60;
    }
  }
  r.seconds = (t1.seconds + t2.seconds);
  if (r.seconds >= 60)
  {
    while (r.seconds >= 60)
    {
      r.minutes++;
      r.seconds = r.seconds - 60;
    }
  }

  return r;
}
Time operator-(const Time& t1 , const Time& t2)
{
  Time r;

  if ( t1 < t2)
  {
    r.days = 0;
    r.hours = 0;
    r.minutes = 0;
    r.seconds = 0;
  }
  r.days = (t1.days - t2.days);
  r.hours = (t1.hours - t2.hours);
  r.minutes = (t1.minutes - t2.minutes);
  r.seconds = (t1.seconds - t2.seconds);

  
  return r;
}
Time operator*(const Time& t1 , int multiplier)
{
  Time r;

  r.days = (t1.days * multiplier);
  r.hours = (t1.hours * multiplier);
  if (r.hours >= 24)
  {
    while (r.hours >= 24)
    {
      r.days++;
      r.hours = r.hours - 24;
    }
  }
  r.minutes = (t1.minutes * multiplier);
  r.seconds = (t1.seconds * multiplier);
  
  return r;
}

// boolean, comparison operator overload functions
bool operator==(const Time& t1 , const Time& t2)
 {
   if (t1.days == t2.days)
   {
     if (t1.hours == t2.hours)
     {
       if (t1.minutes == t2.hours)
       {
         if (t1.seconds == t2.seconds)
         {
           return true;
         }
       }
     }
   }
    return false;   
 }
bool operator!=(const Time& t1 , const Time& t2)
 {
  if (t1 == t2)
   return false; 
  else
   return true;
 }
bool operator< (const Time& t1 , const Time& t2)
{
   if (t1.days < t2.days)
   {
     if (t1.hours < t2.hours)
     {
       if (t1.minutes < t2.hours)
       {
         if (t1.seconds < t2.seconds)
         {
           return true;
         }
       }
     }
   }
    return false;   
 }
bool operator> (const Time& t1 , const Time& t2)
{
  if (t1.days > t2.days)
    return true;
    if ( t1.days == t2.days)
      if (t1.hours > t2.hours)
        return true;
      else if (t1.hours == t2.hours)
        if (t1.minutes > t2.minutes)
          return true;
        else if (t1.minutes == t2.minutes)
          if (t1.seconds > t2.seconds)
            return true;
  else
    return false; 
}
bool operator<=(const Time& t1 , const Time& t2)
{
  if (t1 <= t2)
    return true;
  else
    return false; 
}
bool operator>=(const Time& t1 , const Time& t2)
{
  if (t1 >= t2)
    return true;
  else
    return false; 
}
//-------------FRIEND FUNCTION END-----------------//

// Prefix and postfix increment operators for Time.
Time& Time::operator++()
{
  days = days + 1;
  hours = hours + 1;
  minutes = minutes + 1;
  seconds = seconds + 1;

  return *this; 
}
Time Time::operator++(int)
{
  Time temp = *this;
  days = days + 1;
  hours = hours + 1;
  minutes = minutes + 1;
  seconds = seconds + 1;

  return temp;
}
// Prefix and Postfix decrement operators for Time.
Time& Time::operator--()
{
  days = days - 1;
  hours = hours - 1;
  minutes = minutes - 1;
  seconds = seconds - 1;

  return *this;
}
Time Time::operator--(int)
{
  Time temp = *this;
  days = days - 1;
  hours = hours - 1;
  minutes = minutes - 1;
  seconds = seconds - 1;

  return temp;
}

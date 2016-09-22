#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <math.h>


using namespace std;

time_t currentTime;
struct tm *localTime;

int Day()
{
    time( &currentTime );
  localTime = localtime( &currentTime );

  int Day    = localTime->tm_mday;

  return Day;
}

int Month()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Month  = localTime->tm_mon + 1;

    return Month;
}

int Year()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Year   = localTime->tm_year + 1900;

    return Year;
}

int Hour24()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Hour   = localTime->tm_hour;

    return Hour;
}
int Hour12()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Hour   = localTime->tm_hour;
    if(Hour>12)
    {
        Hour-=12;
        return Hour;
    }
    else
        return Hour;
}

int Min()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Min    = localTime->tm_min;

    return Min;
}

int Sec()
{
    time( &currentTime );
    localTime = localtime( &currentTime );

    int Sec    = localTime->tm_sec;

    return Sec;
}

using namespace std;

int mSec()
{


  LARGE_INTEGER ticksPerSecond;
  LARGE_INTEGER tick;   // A point in time
  LARGE_INTEGER time;   // For converting tick into real time




  // get the high resolution counter's accuracy
  QueryPerformanceFrequency(&ticksPerSecond);

  // what time is it? (not the local time)
  QueryPerformanceCounter(&tick);

  //printf ("\n Ticks par seconde = %ld",ticksPerSecond.QuadPart);

  // convert the tick number into the number of seconds
  // since the system was started...
  time.QuadPart = tick.QuadPart/ticksPerSecond.QuadPart;


  //get the number of hours
  int hours = time.QuadPart/3600;

  //get the number of minutes
  time.QuadPart = time.QuadPart - (hours * 3600);
  int minutes = time.QuadPart/60;

  //get the number of seconds
  int seconds = time.QuadPart - (minutes * 60);

  double ticks_per_micro= (double)ticksPerSecond.QuadPart/1000000;
  //printf ("\n div = %f",ticks_per_micro);

  //get the number of Microseconds
  double microSeconds = (double)((tick.QuadPart % ticksPerSecond.QuadPart) / ticks_per_micro);

  return(abs((int)microSeconds));


  }


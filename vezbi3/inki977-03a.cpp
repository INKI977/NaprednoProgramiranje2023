#include <iostream>
#include <time.h>

int main ()
{
  time_t now;
  struct tm newyear;
  int seconds;

  time(&now);  /* ovaa funkcija go vrakja momentalnoto vreme vo format kako sekundi izminati od 01.01.1970 */

  newyear = *localtime(&now);/*ovaa funkcija go vrakja momentalnoto vreme vo nashata vremenska zona*/

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;

  seconds = difftime(now,mktime(&newyear));/*ovaa funkcija ja presmetuva razlikata pomegju vkupno sekundi izminati od 01.01.1970 i sekundi pominati od 01.01.2023*/
  /*rezultatot se pecati podolu*/

  std::cout<<" seconds since new year in the current timezone "<< seconds;

  return 0;
}
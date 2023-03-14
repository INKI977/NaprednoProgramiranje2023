#include <iostream>
#include <ctime>

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);/*go vrakja vremeto izminato od 01.01.1970 vo sekundi*/
  
  timeinfo = localtime (&rawtime);/*vremeto izminato od 01.01.1970 ko konvertira vo lokalnata vremenska zona*/
  
  std::cout<<"Current local time and date: "<< asctime(timeinfo);/*ja pretvora strukturata od tipot tm vo string*/

  return 0;
}
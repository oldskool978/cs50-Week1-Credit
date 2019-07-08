#include"credit.h"


int main(void)
{
  Get_NuMber();
  printf ("%s", isitValid(NuMber));
  free(NuMber);
  return 0;
}

#include"credit.h"


int main(void)
{
  printf ("Number: ");
  Get_NuMber();
  printf ("%s", isitValid(NuMber));
  free(NuMber);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int LuHn(char CreD[20]);
char *isitValid(char VaLidate[20]);
char *NuMber;
void Get_NuMber(void);


//Function to check for Amex Visa or Mastercard
char *isitValid(char VaLidate[20])
{
  if ( (strlen(VaLidate) == 14 ) | !(strlen(VaLidate) > 12) | (strlen(VaLidate) > 16 ))
  { return "INVALID\n"; exit(0);}
         switch((((VaLidate[0] -'0') * 10) + (VaLidate[1] - '0')))
         {
               case 34: case 37:
               if ( (LuHn(NuMber) % 10 ) == 0)
               {return "AMEX\n";}
                     case 40 ... 45:
                     if ( (LuHn(NuMber) % 10 ) == 0)
                     {return "VISA\n";}
                           case 51 ... 55:
                           if ( (LuHn(NuMber) % 10 ) == 0)
                           {return "MASTERCARD\n";}
                                 default:
                                 return "INVALID\n";
  }
  return "INVALID\n";
}


//Function to get NuMber, only digits.
void Get_NuMber(void)
{
    do
    {
    free(NuMber);
    NuMber = (char*)malloc(20);
    printf ("Number: ");
    scanf("%s", &NuMber[0]);
    getchar();
    }
    while ( NuMber < 0 );
    for (int CNum = 0 ; CNum < strlen(NuMber) ; CNum++ )
        { if (isdigit(NuMber[CNum]) == 0)
        { Get_NuMber();}}
}


//Luhns algorythm, Accepts Char arr returns int
int LuHn(char CreD[20])
{
  int SoLvE = 0;
  char DiGit2[3];
  for (int HNum = strlen(CreD) - 1 ; HNum > 0; HNum = HNum -2 )
  {
  sprintf(&DiGit2[0], "%d", (CreD[HNum -1] - '0') * 2 );
  int DiGit1 = strlen(DiGit2);
     if ( DiGit1 >= 2)
     {SoLvE = SoLvE + ((DiGit2[0] -'0') + (DiGit2[1] - '0'));}
     else {SoLvE = SoLvE + (DiGit2[0] -'0');}}
         for (int HNum = strlen(CreD) ; HNum > 0; HNum = HNum -2 )
         {SoLvE = SoLvE + (CreD[HNum -1] - '0');}
  return SoLvE;
}

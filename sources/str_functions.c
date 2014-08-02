/*
** str_functions.c for str_functions in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:38:05 2011 gregoire1 borel
** Last update Tue Mar 15 17:38:34 2011 gregoire1 borel
*/

#include "../headers/str_functions.h"
#include "../headers/aff_functions.h"

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (0);
      i++;
    }
  return (1);
}

char	*my_revstr(char *str)
{
  int   i;
  int   y;
  int   a;

  a = 0;
  i = 0;
  y = my_strlen(str) - 1;
  while (i < y)
    {
      a = str[i];
      str[i++] = str[y];
      str[y--] = a;
    }
  return (str);
}

int	my_transl_nbr(char *str, int result)
{
  int   i;
  int   flag;
  int   signe;

  flag = 0;
  signe = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == '-' || str[i] == '+') && flag == 0)
        {
          if (str[i] == '-')
            signe = -signe;
        }
      else if (str[i] >= '0' && str[i] <= '9')
        {
          flag = 1;
          result = result * 10 + (str[i] - '0');
        }
      else
        return (signe * result);
      i++;
    }
  return (signe * result);
}

int	my_getnbr(char *str)
{
  int   result;

  result = 0;
  result = my_transl_nbr(str, result);
  return (result);
}

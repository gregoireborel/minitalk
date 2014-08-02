/*
** my_atoi_base.c for my_atoi_base in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:43:36 2011 gregoire1 borel
** Last update Tue Mar 15 15:43:38 2011 gregoire1 borel
*/

#include "../headers/aff_functions.h"
#include "../headers/my_atoi_base.h"

int	find(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (base[i] == c)
        return (i);
      i++;
    }
  return (0);
}

int	my_pow(int a, int b)
{
  int	mult;

  mult = a;
  while (b > 1)
    {
      a = a * mult;
      b--;
    }
  return (a);
}

int	my_atoi_base(char *str, char *base)
{
  int	i;
  int	mult;
  int	coeff;
  int	nb;

  i = 0;
  nb = 0;
  mult = my_strlen(base);
  coeff = my_strlen(str) - 1;
  while (str[i])
    {
      if (coeff != 0)
        nb += find(str[i], base) * my_pow(mult, coeff);
      else
        nb += find(str[i], base);
      i++;
      coeff--;
    }
  return (nb);
}

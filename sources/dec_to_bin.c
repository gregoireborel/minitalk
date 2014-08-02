/*
** dec_to_bin.c for dec_to_bin in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:44:15 2011 gregoire1 borel
** Last update Thu Mar 17 15:31:04 2011 gregoire1 borel
*/

#include <stdlib.h>
#include "../headers/dec_to_bin.h"
#include "../headers/str_functions.h"
#include "../headers/aff_functions.h"
#include "../headers/x_functions.h"

char	*dec_to_bin(int	nb, char *bin, int i, int max)
{
  int	res;

  if (nb == 0)
    {
      bin = x_malloc((max + 1) * sizeof(*bin));
      bin[max] = 0;
      bin[i] = 0;
      return (bin);
    }
  res = nb % 2;
  bin = dec_to_bin((nb / 2), bin, (i + 1), max);
  bin[i] = res + 48;
  return (bin);
}

char	*fill_bin(char *str, int max)
{
  int	i;

  i = my_strlen(str);
  if (i < max)
    {
      str[i] = '0';
      while (i < max)
	str[i++] = '0';
    }
  return (str);
}

char	*conv_to_bin(int nb, int max)
{
  char	*bin;

  bin = NULL;
  bin = dec_to_bin(nb, bin, 0, max);
  bin = fill_bin(bin, max);
  bin = my_revstr(bin);
  return (bin);
}

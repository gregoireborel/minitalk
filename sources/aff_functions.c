/*
** aff_functions.c for aff_functions in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:39:31 2011 gregoire1 borel
** Last update Thu May  5 19:19:58 2011 gregoire1 borel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../headers/aff_functions.h"

void    aff_pid()
{
  pid_t pid;

  pid = getpid();
  my_putstr("\033[31mServer's PID : \033[00m");
  my_putnbr(pid);
  my_putstr("\n");
}

void    my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void    my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  while (nb > 9)
    {
      my_putnbr(nb / 10);
      nb = nb % 10;
    }
  nb += 48;
  my_putchar(nb);
}

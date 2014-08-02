/*
** x_functions.c for x_functions in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Thu Mar 17 15:08:56 2011 gregoire1 borel
** Last update Thu Mar 17 15:37:06 2011 gregoire1 borel
*/

#define _POSIX_SOURCE

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "../headers/x_functions.h"

void	*x_malloc(size_t size)
{
  void	*ptr;

  ptr = NULL;
  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return (ptr);
}

void	x_kill(int pid, int signal)
{
  if (kill(pid, signal) == -1)
    exit(EXIT_FAILURE);
}

void    my_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}

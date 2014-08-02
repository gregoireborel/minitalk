/*
** pong.c for pong in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 17:37:54 2011 gregoire1 borel
** Last update Tue Mar 15 17:42:02 2011 gregoire1 borel
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../headers/pong.h"

void    empty(int sig)
{
  (void) sig;
}

void    pong(void)
{
  if (signal(SIGUSR1, empty) == SIG_ERR)
    exit(EXIT_FAILURE);
  pause();
}


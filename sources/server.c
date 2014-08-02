/*
** server.c for server in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:46:55 2011 gregoire1 borel
** Last update Thu Mar 17 15:48:57 2011 gregoire1 borel
*/

#define _BSD_SOURCE
#define _POSIX_SOURCE

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../headers/aff_functions.h"
#include "../headers/my_atoi_base.h"
#include "../headers/str_functions.h"
#include "../headers/x_functions.h"
#include "../headers/server.h"

int	pid_client = -1;

void    ping(void)
{
  if ((kill(pid_client, SIGUSR1)) == -1)
    exit(EXIT_FAILURE);
}

void	get_client_pid(int signal)
{
  static char	buf[32];
  static int	i = 0;
  int	nb;

  if (signal == SIGUSR1)
    buf[i++] = '1';
  if (signal == SIGUSR2)
    buf[i++] = '0';
  if (i == 32)
    {
      buf[i] = '\0';
      i = 0;
      nb = my_atoi_base(buf, "01");
      pid_client = nb;
      my_putstr("\033[32mClient says: \033[00m");
      usleep(1200);
      ping();
    }
}

void	get_msg(int signal)
{
  static char	buf[8];
  static int	i = 0;
  int	nb;

  usleep(300);
  if (signal == SIGUSR1)
    buf[i++] = '1';
  if (signal == SIGUSR2)
    buf[i++] = '0';
  if (i == 8)
    {
      buf[i] = '\0';
      i = 0;
      nb = my_atoi_base(buf, "01");
      my_putchar(nb);
      if (nb == 0)
	{
	  ping();
	  pid_client = -1;
	  my_putchar('\n');
	  return ;
	}
    }
  ping();
}

int	main()
{
  aff_pid();
  while (42)
    {
      if (pid_client == -1)
	{
	  if (signal(SIGUSR1, get_client_pid) == SIG_ERR)
	    exit(EXIT_FAILURE);
	  if (signal(SIGUSR2, get_client_pid) == SIG_ERR)
	    exit(EXIT_FAILURE);
	}
      else
        {
          if (signal(SIGUSR1, get_msg) == SIG_ERR)
	    exit(EXIT_FAILURE);
	  if (signal(SIGUSR2, get_msg) == SIG_ERR)
	    exit(EXIT_FAILURE);
	}
      pause();
    }
  return (0);
}

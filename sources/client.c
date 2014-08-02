/*
** client.c for client in /home/borel_b//proj/minitalk/minitalk/sources
** 
** Made by gregoire1 borel
** Login   <borel_b@epitech.net>
** 
** Started on  Tue Mar 15 15:43:52 2011 gregoire1 borel
** Last update Thu Mar 17 15:39:08 2011 gregoire1 borel
*/

#define _BSD_SOURCE
#define _POSIX_SOURCE

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/aff_functions.h"
#include "../headers/str_functions.h"
#include "../headers/dec_to_bin.h"
#include "../headers/x_functions.h"
#include "../headers/pong.h"
#include "../headers/client.h"

int	get_serv_pid(char *av)
{
  pid_t	pid_serv;

  if (my_str_isnum(av))
    pid_serv = my_getnbr(av);
  else
    {
      my_putstr("Error PID : PID must be an integer.\n");
      return (-1);
    }
  return (pid_serv);
}

void	send_pid(int pid_serv)
{
  pid_t	pid_client;
  char	*bin_client_pid;
  int	i;

  i = 0;
  pid_client = getpid();
  bin_client_pid = conv_to_bin(pid_client, 32);
  while (bin_client_pid[i])
    {
      if (bin_client_pid[i] == '0')
	x_kill(pid_serv, SIGUSR2);
      if (bin_client_pid[i] == '1')
	x_kill(pid_serv, SIGUSR1);
      usleep(900);
      i++;
    }
  my_free(bin_client_pid);
}

void	terminate_msg(int pid_serv)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      x_kill(pid_serv, SIGUSR2);
      pong();
      i++;
    }
}

void	send_msg(char *str, int pid_serv)
{
  char	*bin;
  int	i;
  int	y;

  i = 0;
  while (str[i])
    {
      bin = conv_to_bin(str[i++], 8);
      y = 0;
      while (bin[y])
	{
	  usleep(300);
	  if (bin[y] == '0')
	    x_kill(pid_serv, SIGUSR2);
	  else if (bin[y] == '1')
	    x_kill(pid_serv, SIGUSR1);
	  pong();
	  y++;
	}
      my_free(bin);
    }
  terminate_msg(pid_serv);
}

int	main(int argc, char **argv)
{
  pid_t	pid_serv;

  if (argc == 3)
    {
      if ((pid_serv = get_serv_pid(argv[1])) == -1)
	return (0);
      my_putstr("\033[31mConnecting to server...\n\033[00m");
      send_pid(pid_serv);
      pong();
      my_putstr("\033[31mSending message...\n\033[00m");
      send_msg(argv[2], pid_serv);
      my_putstr("\033[31mDone !\n\033[00m");
    }
  else
    my_putstr("Usage: [server PID] [string]\n");
  return (0);
}

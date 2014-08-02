#ifndef CLIENT_
# define CLIENT_

int     get_serv_pid(char *av);
void    send_pid(int pid_serv);
void    terminate_msg(int pid_serv);
void    send_msg(char *str, int pid_serv);
void	pong(void);

#endif /*!CLIENT_*/

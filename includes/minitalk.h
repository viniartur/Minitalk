#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

// Funções utilitárias
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

// Funções do servidor
void	handle_signal(int sig, siginfo_t *info, void *context);

// Funções do cliente
void	send_bit(int pid, unsigned char bit);
void	send_char(int pid, unsigned char c);
void	send_string(int pid, char *str);

#endif
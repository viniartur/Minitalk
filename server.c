#include "minitalk.h"

static volatile sig_atomic_t	g_current_char = 0;
static volatile sig_atomic_t	g_bit_count = 0;

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;

	if (sig == SIGUSR1)
		g_current_char |= (0 << g_bit_count);
	else if (sig == SIGUSR2)
		g_current_char |= (1 << g_bit_count);
	
	g_bit_count++;
	
	if (g_bit_count == 8)
	{
		if (g_current_char == '\0')
			write(1, "\n", 1);
		else
		{
			// Cast para remover o volatile
			char c = (char)g_current_char;
			write(1, &c, 1);
		}
		g_current_char = 0;
		g_bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction failed\n", 2);
		return (1);
	}
	
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction failed\n", 2);
		return (1);
	}
	
	while (1)
		pause();
	
	return (0);
}
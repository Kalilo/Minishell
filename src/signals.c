#include "../includes/minishell.h"

void sig_handler(int signo)
{
	if (signo == SIGHUP || signo == SIGQUIT || signo == SIGABRT ||
		signo == SIGKILL || signo == SIGTERM || signo == SIGUSR1 || 
		signo == SIGUSR2)
	{
		ft_putstr("\e[31mExiting Program.\n");
		exit(0);
	}
	if (signo == SIGTRAP || signo == SIGBUS ||
		signo == SIGSEGV || signo == SIGSYS)
	{
		ft_putstr("\e[31mError: an unexpected error occured.\n");
		exit(0);
	}
}

void	sigs(void)
{
	int		k;

	k = 0;
	while (++k < 32)
		signal(k, sig_handler);
}

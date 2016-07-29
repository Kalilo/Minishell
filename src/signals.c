#include "../includes/minishell.h"

/*
**The restart function needs the origonal process to die,
** before being called.
**It will not be used for now.
*/
void	restart(void)
{
	t_env	*env;

	env = (t_env *)back_up_env(NULL);
	ft_putstr("\e[31mRestarting...");
	execve("./minishell", NULL, E_EN);
	exit(0);
}

void	sig_handler(int signo)
{
	printf("\e[93mSignal recieved: '%d'\n", signo);//debug
	if (signo == SIGHUP || signo == SIGQUIT || signo == SIGKILL ||
		signo == SIGTERM || signo == SIGUSR1 || signo == SIGTTIN ||
		signo == SIGUSR2)
	{
		ft_putstr("\e[31mExiting Program.\n");
		exit(0);
	}
	if (signo == SIGTRAP || signo == SIGBUS || signo == SIGABRT ||
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

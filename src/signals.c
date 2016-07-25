#include "../includes/minishell.h"

void sig_handler(int signo)
{
	ft_putstr("\e[31mError: an unexpected error occured.\n");
	exit(0);
}

void	sigs2(void)
{
	//To be continued...
}

void	sigs(void)
{
	signal(SIGHUP, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGILL, sig_handler);
	signal(SIGTRAP, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGEMT, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGBUS, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGSYS, sig_handler);
	signal(SIGPIPE, sig_handler);
	signal(SIGALRM, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGURG, sig_handler);
	signal(SIGSTOP, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCHLD, sig_handler);
	signal(SIGTTIN, sig_handler);
	sigs2();
}

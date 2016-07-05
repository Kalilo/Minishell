/*
 *	Things we still need:
 *		t_env	struct
 *		int		arg_valid(char **sa, int i); -a
 *		void	error(int i); -a
 *		char	*find_path(char *s); -a
 *		int		is_own(char *s); -k
 *		int		env_valid(char *s); -a
 *		void	get_env(char **environ); -v
 *		void	free2d(char *sa[][]) -k
 *		void	ft_echo(char **sa);
 *		void	ft_cd(char **sa);
 *		void	ft_export(char **sa);
 *		void	ft_unset(char **sa);
 *		void	ft_env(char **sa);
 */
#ifndef MINISHELL_H
# define MINISHELL_H

/*Includes*/ 
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>
# include "libft.h"

/*Defines*/
	/*Shorthand*/
# define E_EN env->environ
# define E_SI env->size
# define E_LI env->line
# define E_ER env->error

	/*Error Messages*/
# define E_MESS01 "Error: No such file or directory.\n"
# define E_MESS02 "Error: Command not found.\n"
# define E_MESS03 "Error: Command failed.\n"

	/*Stings*/
# define SH_L "$> "
# define CM_EXIT "exit"
# define CM_EXIT_S 5

/*Structures*/

typedef struct	s_env
{
	char		**environ;/*last possition is our local variables.*/
	int			env_size;
	char		*line;
	int			error;
}				t_env;
/*Prototypes*/
	/*command.c*/
int 	do_command(char *com);
void	do_fork(char *s);
void	command(t_env *env, char *s);
	/*errors.c*/
int		error1(int err);
int		error(int err);
	/*get_line.c*/
char	*re_malloc(char *line, size_t size);
int		get_line(int fd, char **line);
	/*set_env.c*/
void	set_env(t_env *env, char *s);
	/*count.c*/
int		count(char *s, char c);
	/*own_command.c*/
int		is_own(char *s);
void	own_command(char **sa);
	/*ft_strchr_f.c*/
int		ft_strchr_f(char *s, char c);
	/*get_env.c*/
char	**get_env(char **environ);
#endif

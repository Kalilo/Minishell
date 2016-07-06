/*
 *
 * Change the following params:
 * 	ft_*;
 *
 *	Things we still need:
 *		int		arg_valid(char **sa, int i); -a
 *		void	error(int i); -a
 *		char	*find_path(char s[]); -a
 *		int		env_valid(char s[]); -a
 *		void	replace_var(char *s[]);-v
 *		void	ft_echo(char *sa[]);-c
 *		void	ft_cd(char *sa[]);-a
 *		void	ft_env(char **sa);-v
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
# include "../libft/includes/libft.h"

/*Defines*/
	/*Shorthand*/
# define E_EN env->environ
# define E_SI env->size
# define E_LI env->line
# define E_ER env->error
# define E_A env->a

	/*Error Messages*/
# define E_MESS01 "Error: No such file or directory.\n"
# define E_MESS02 "Error: Command not found.\n"
# define E_MESS03 "Error: Command failed.\n"
# define E_MESS04 "Memory problem.\n"

	/*Stings*/
# define SH_L "$> "
# define CM_EXIT "exit"
# define CM_EXIT_S 5
# define OWN_FUNCS "cd setenv unsetenv env exit "
# define AL_SYM "$()- "

/*Structures*/

typedef struct	s_env
{
	char		**environ;/*last possition is our local variables.*/
	int			env_size;
	char		*line;
	int			error;
	char		*a;
}				t_env;
/*Prototypes*/
	/*checks.c*/
int 	allowed_character(char c);
int		arg_valid(char **sa, int i);
	/*command.c*/
int 	do_command(char *com);
void	command(t_env *env, char *s);
	/*errors.c*/
int		error1(int err);
int		error(int err);
	/*exit.c*/
void		free2d(char **arr);
void		exit_prog(t_env env);
	/*get_line.c*/
char	*re_malloc(char *line, size_t size);
int		get_line(int fd, char **line);
	/*own_command.c*/
int 	is_own(char *s);
	/*set_env.c*/
int		env_valid(char *s);
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
	/*ft_unset.c*/
void	ft_removestr(char **big, char *little);
void	ft_unset(char *sa[], char *var);
	/*ft_export.c*/
void	ft_export(char *sa[], char *s);

#endif

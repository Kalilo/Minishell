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
# include <dirent.h>
# include "../libft/includes/libft.h"

#include <stdio.h>//debug!
#include <string.h>//debug!
// printf("\n");//debug

/*Defines*/
	/*Shorthand*/
# define E_EN env->environ
# define E_SI env->env_size
# define E_LI env->line
# define E_ER env->error
# define E_A env->a

	/*Error Messages*/
# define E_MESS01 "\e[31mError: No such file or directory.\n"
# define E_MESS02 "\e[31mError: Command not found.\n"
# define E_MESS03 "\e[31mError: Command failed.\n"
# define E_MESS04 "\e[31mMemory problem.\n"
# define E_MESS05 "\e[31mis_own is not working properly"

	/*Stings*/
# define SH_L "\e[32m$> \e[0m\e[36m"
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
int 	do_command(t_env *env, char *com);
void	command(t_env *env, char *s);
	/*errors.c*/
int		error1(int err);
int		error(int err);
	/*exit.c*/
void	free2d(char **arr);
void	exit_prog(t_env *env);
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
void	own_command(t_env *env, char **sa, char *s);
	/*ft_strchr_f.c*/
int		ft_strchr_f(char *s, char c);
	/*get_env.c*/
char	**get_env(char **environ);
int		get_envsize(char **env);
	/*ft_unset.c*/
void	ft_removestr(char *big, char *little);
void	ft_unset(char ***sa, char *var);
	/*ft_export.c*/
void	ft_export(char *sa[], int env_size, char *s);
	/*ft_env.c*/
void	ft_env(char **sa);
char	*find_var_val(t_env *env, const char *var);
	/*find_path.c*/
int		scan_dir(char *s, char *path);
char	*add_path(char	*path, char	*extension);
char	*find_path(t_env *env, char s[]);
	/*echo.c*/
void	ft_echo(char **sa);
	/*ft_cd.c*/
void	ft_cd(t_env *env, char **sa);
	/*trim.c*/
char	*trim_start(char *str);
void	trim_end(char **str);
void	trim_str(char **str);
int		trim_arr(char ***arr);
char	*rm_tabs(char *str);

#endif

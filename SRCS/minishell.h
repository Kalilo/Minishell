/*
 *	Things we still need:
 *		t_env	struct
 *		int		arg_valid(char **sa, int i);
 *		int		count(char *s, char c); #plus one here to get right amount#
 *		void	error(int i);
 *		char	*find_path(char *s);
 *		int		is_own(char *s);
 *		void	own_command(char **sa);
 */
#ifndef MINISHELL_H
# define MINISHELL_H

/*Includes*/ 
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*Defines*/

/*Includes*/

/*Prototypes*/
	/*command.c*/
int 	do_command(char *com);
void	do_fork(char *s);
void	command(t_env *env, char *s);
	/*errors.c*/
int		error1(t_data *data);
int		error(t_data *data);
	/*get_line.c*/
char	*re_malloc(char *line, size_t size);
int		get_line(int fd, char **line);
	/*set_env.c*/
void	set_env(t_env *env, char *s);
	
#endif

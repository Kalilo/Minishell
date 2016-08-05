#include "../includes/minishell.h"

void	key_handler(t_env *env, char *key)
{
	//put_bin((unsigned char *)key);//debug
	//printf("Key Pressed: '%s'\n", key);//debug
	if (*key == K_BKSP && I_C1 >= 0)
		I_L1[I_C1--] = '\0';
	else if (!ft_strcmp(K_UP, key))
		com_history(env, HIST_PREV);
	else if (!ft_strcmp(K_DOWN, key))
		com_history(env, HIST_NEXT);
	else if (!ft_strcmp(K_RIGHT, key))
		ke_right(env);
	else if (!ft_strcmp(K_LEFT, key))
		ke_left(env);
}

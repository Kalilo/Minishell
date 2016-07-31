#include "../includes/minishell.h"

void	key_handler(t_env *env, char *key)
{
	//put_bin((unsigned char *)key);//debug
	if (*key == KEY_BKSP && I_C1 >= 0)
		I_L1[I_C1--] = '\0';
}

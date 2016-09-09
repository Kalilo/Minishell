#include "../includes/minishell.h"

void	auto_complete(void)
{
	DIR				*fd;
	struct dirent	*dirp;


	fd = open_dir("./");
	if (fd != NULL)
	{
		while ((dirp = readdir(fd)) != NULL)
			puts(dirp->d_name);
		close_dir(fd);
	}
}

/*
 *	Check that the ft_strjoin works
 */

void	ft_export(char *sa[][], int env_size, char *s)
{
	int		i;
	char	*temp;
	char	*stemp;

	temp = *sa[env_size - 1];
	stemp = s;
	s = ft_strjoin(s, "\n");
	*sa[env_size - 1] = ft_strjoin(*sa[env_size], s);
	free (temp);
	free(stemp);
}

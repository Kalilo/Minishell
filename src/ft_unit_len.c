/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:09:44 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 14:09:45 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_len_until(char *str, char c)
{
	int		k;

	k = 0;
	if (!str)
		return (0);
	while (str[0] && str[k] != c)
		k++;
	return (k);
}

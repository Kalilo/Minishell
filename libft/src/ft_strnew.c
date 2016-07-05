/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 07:36:58 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/03 09:30:25 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (str[cnt])
	{
		str[cnt] = '\0';
		cnt++;
	}
	return (str);
}

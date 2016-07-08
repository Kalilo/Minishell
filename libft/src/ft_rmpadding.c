/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmpadding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 12:57:01 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/08 14:23:02 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_rmpadding(char *str)
{
	size_t	*arr;
	size_t	cnt;
	size_t	cnt2;
	size_t	cnt3;
	size_t	cnt4;
	char	*dest;

	cnt = 0;
	cnt2 = 0;
	cnt3 = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str));
	arr = ft_check_dquote(str);
	while (str[cnt] && str[cnt + 1] && str[cnt + 2] && str[cnt] != '\0' \
			&& str[cnt + 1] != '\0' && str[cnt + 2] != '\0')
	{
		cnt4 = cnt;
		if ((cnt == arr[cnt2]) && arr[cnt2 + 1] && arr[cnt2])
		{
			cnt4 = cnt + 1;
			while (cnt4 != arr[cnt2])
			{
				dest[cnt3] = str[cnt4];
				cnt3++;
				cnt4++;
			}
		}
		cnt = cnt4;
		if ((str[cnt] == 32 || str[cnt] == 9) && \
					(str[cnt + 1] == 32 || str[cnt + 1] == 9))
		{
			while ((str[cnt] == 32 || str[cnt] == 9) && \
					(str[cnt + 1] == 32 || str[cnt + 1] == 9))
			{
				cnt += 2;
			}
		}
		dest[cnt3] = str[cnt];
		cnt3++;
		cnt++;
	}
	return (dest);
}

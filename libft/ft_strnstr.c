/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:00:52 by mdupuis           #+#    #+#             */
/*   Updated: 2021/07/05 12:07:00 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	else
	{
		while (s1[i])
		{
			j = 0;
			while ((s2[j] == s1[i + j]) && i + j < len)
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}

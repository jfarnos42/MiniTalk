/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:48:57 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/02/09 00:55:34 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s1len;

	s1len = ft_strlen(s1);
	if (s1len < start)
	{
		len = 0;
		start = s1len;
	}
	else if ((s1len - start) < len)
		len = s1len - start;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1 + start, len + 1);
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:38:23 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/02/11 18:53:46 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getfrontcut(const char *s1, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	getendcut(const char *s1, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		fcut;
	int		ecut;

	if (!s1 || !set)
		return (0);
	fcut = getfrontcut(s1, set);
	ecut = getendcut(s1, set);
	if (fcut >= ecut)
		return (ft_strdup(""));
	dst = malloc(sizeof(char) * (ecut - fcut + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1 + fcut, ecut - fcut +1);
	return (dst);
}

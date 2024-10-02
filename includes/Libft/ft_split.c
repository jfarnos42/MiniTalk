/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:32:10 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/02/11 18:51:46 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcount(char const *s, char c)
{
	int	i;
	int	count;

	if (s == NULL)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wrdlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	**ft_freematrix(char **array, int i)
{
	while (i-- > 0)
		free (array[i]);
	free (array);
	return (0);
}

static char	**ft_split2(char const *s, char c, size_t i, size_t len)
{
	char	**list;
	int		save;

	save = 0;
	list = malloc(sizeof(char *) * (ft_wrdcount(s, c) + 1));
	if (!list)
		return (NULL);
	while (s[i])
	{
		len = ft_wrdlen((char *)&s[i], c);
		if (len != 0)
		{
			list[save] = ft_substr(&s[i], 0, len);
			if (!list[save])
				return (ft_freematrix(list, save));
			save++;
		}
		if (len == 0)
			i++;
		else
			i = i + len;
	}
	list[save] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	return (ft_split2(s, c, 0, 0));
}

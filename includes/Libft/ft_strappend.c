/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:39:55 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/02 05:26:36 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *chain, char *block)
{
	char	*aux;

	aux = NULL;
	if (chain)
	{
		aux = chain;
		free(chain);
		return (ft_strjoin(aux, block));
	}
	return (ft_strdup(block));
}

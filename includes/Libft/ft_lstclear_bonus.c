/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:35:04 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/02/11 18:31:02 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxnode;

	while ((*lst) != NULL)
	{
		auxnode = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = auxnode;
	}
}

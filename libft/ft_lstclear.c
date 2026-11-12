/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:30:12 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 10:36:58 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nex;
	t_list	*delete;

	delete = *lst;
	while (delete)
	{
		nex = delete->next;
		del(delete->content);
		free(delete);
		delete = nex;
	}
	*lst = 0;
}

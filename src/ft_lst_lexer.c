/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:40:11 by med-doba          #+#    #+#             */
/*   Updated: 2022/08/21 10:54:39 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	ft_lstadd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	tmp = *lst;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	new->next = NULL;
	*lst = tmp;
}

t_lexer	*ft_lstnew(char *content, int linked)
{
	t_lexer	*node;

	node = (t_lexer *)malloc(sizeof(t_lexer));
	if (node == NULL)
		return (NULL);
	node->content = ft_strdup(content);
	node->next = NULL;
	node->linked = linked;
	return (node);
}

void	ft_free_lst(t_lexer **head)
{
	t_lexer		*tmp;

	while ((*head))
	{
		free((*head)->content);
		tmp = (*head)->next;
		free((*head));
		(*head) = tmp;
	}
}

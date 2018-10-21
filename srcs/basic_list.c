/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:13:48 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/04 21:07:32 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_create_elem(char *s, struct stat *data)
{
	t_list			*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		malloc_error();
	new->name = s;
	new->info = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_elem_back(t_list **head, char *s, struct stat *data)
{
	t_list	*current;
	t_list	*new;

	new = ft_create_elem(s, data);
	current = *head;
	if (current && current->name)
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	else
		*head = new;
}

t_list	*delete_list(t_list **head)
{
	t_list		*current;

	current = *head;
	if (current)
	{
		while (current->next)
		{
			if (current->prev)
				free_everything(current->prev);
			current = current->next;
		}
		free_everything(current->prev);
		free_everything(current);
	}
	return (NULL);
}

void	remove_dot_files(t_list **head)
{
	t_list	*current;
	char	*tmp;

	current = *head;
	while (current && remove_path(current->name))
	{
		tmp = remove_path(current->name);
		if (tmp[0] == '.')
		{
			free(current->name);
			current->name = NULL;
		}
		current = current->next;
	}
}

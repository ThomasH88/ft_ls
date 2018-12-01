/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:43:08 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 19:31:14 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error_list(t_list **head)
{
	t_list			*current;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (current)
	{
		if (current->name && current->name[ft_strlen(current->name) - 1] != '/')
			b_printf("ft_ls: %s: No such file or directory\n", current->name);
		else if (current->name)
			b_printf("ft_ls: %s: Not a directory\n", current->name);
		current = current->next;
	}
}

void	print_list(t_list **head, char lart[7], char *door)
{
	t_list			*current;

	current = *head;
	while (current)
	{
		if (lart && lart[0] == '1')
		{
			if (remove_path(current->name))
				print_long_fmt(current->info, current->name, door);
		}
		else
		{
			if (remove_path(current->name) && door)
				b_printf("%s\n", remove_path(current->name));
			else if (current->name)
				b_printf("%s\n", current->name);
		}
		current = current->next;
	}
}

void	print_rev_list(t_list **head, char lart[7], char *door)
{
	t_list	*current;

	current = *head;
	if (current)
	{
		while (current->next)
			current = current->next;
		while (current)
		{
			if (lart && lart[0] == '1')
			{
				if (current->name)
					print_long_fmt(current->info, current->name, door);
			}
			else
			{
				if (current->name && door)
					b_printf("%s\n", remove_path(current->name));
				else if (current->name)
					b_printf("%s\n", (current->name));
			}
			current = current->prev;
		}
	}
}

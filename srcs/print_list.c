/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:43:08 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/04 15:05:03 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_error_list(t_list **head)
{
	t_list			*current;

	current = *head;
	while (current)
	{
		if (current->name)
			printf("b_ls: %s: No such file or directory\n", current->name);
		current = current->next;
	}
}

void	print_list(t_list **head, char lart[5])
{
	t_list			*current;

	current = *head;
	while (current)
	{
		if (lart && lart[0] == '1')
		{
			if (remove_path(current->name))
				print_long_fmt(current->info, current->name);
		}
		else
		{
			if (remove_path(current->name))
				printf("%s\n", remove_path(current->name));
		}
		current = current->next;
	}
}

void	print_rev_list(t_list **head, char lart[5])
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
					print_long_fmt(current->info, current->name);
			}
			else
			{
				if (current->name)
					printf("%s\n", remove_path(current->name));
			}
			current = current->prev;
		}
	}
}
